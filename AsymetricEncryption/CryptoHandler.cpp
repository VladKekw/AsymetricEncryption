#include "CryptoHandler.h"
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <codecvt>
#include <locale>


namespace fs = std::filesystem;

CryptoHandler::CryptoHandler() {}

void CryptoHandler::GenerateKeys(const std::string& publicKeyFile, const std::string& privateKeyFile) {
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_from_name(nullptr, "RSA", nullptr);
    EVP_PKEY* pkey = nullptr;

    if (!ctx || EVP_PKEY_keygen_init(ctx) <= 0 || EVP_PKEY_generate(ctx, &pkey) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        return;
    }

    BIO* bp_public = BIO_new_file(publicKeyFile.c_str(), "w+");
    PEM_write_bio_PUBKEY(bp_public, pkey);
    BIO_free(bp_public);

    BIO* bp_private = BIO_new_file(privateKeyFile.c_str(), "w+");
    PEM_write_bio_PrivateKey(bp_private, pkey, nullptr, nullptr, 0, nullptr, nullptr);
    BIO_free(bp_private);

    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
}

std::string CryptoHandler::Encrypt(const std::string& plainText, const std::string& publicKeyFile) {
    BIO* keybio = BIO_new_file(publicKeyFile.c_str(), "r");
    if (!keybio) {
        std::cerr << "Помилка відкриття файлу публічного ключа: " << publicKeyFile << "\n";
        return "";
    }

    EVP_PKEY* pkey = PEM_read_bio_PUBKEY(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "Помилка завантаження публічного ключа: " << publicKeyFile << "\n";
        ERR_print_errors_fp(stderr);
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        std::cerr << "Помилка створення контексту для шифрування\n";
        EVP_PKEY_free(pkey);
        return "";
    }

    if (EVP_PKEY_encrypt_init(ctx) <= 0) {
        std::cerr << "Помилка ініціалізації шифрування\n";
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "";
    }

    EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);

    int key_size = EVP_PKEY_size(pkey);
    int max_data_size = key_size - 42;  // Ограничение RSA PKCS1_OAEP_PADDING

    std::vector<unsigned char> encrypted_data;

    for (size_t i = 0; i < plainText.size(); i += max_data_size) {
        std::string block = plainText.substr(i, max_data_size);
        size_t outlen;

        if (EVP_PKEY_encrypt(ctx, nullptr, &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "Помилка визначення розміру зашифрованого блоку\n";
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        std::vector<unsigned char> encrypted_block(outlen);
        if (EVP_PKEY_encrypt(ctx, encrypted_block.data(), &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "Помилка шифрування блоку\n";
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        encrypted_data.insert(encrypted_data.end(), encrypted_block.begin(), encrypted_block.end());
    }

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return std::string(encrypted_data.begin(), encrypted_data.end());
}


std::string CryptoHandler::Decrypt(const std::string& cipherText, const std::string& privateKeyFile) {
    if (cipherText.empty()) {
        std::cerr << "Помилка: Вхідний текст порожній!\n";
        return "";
    }

    BIO* keybio = BIO_new_file(privateKeyFile.c_str(), "r");
    if (!keybio) {
        std::cerr << "Помилка відкриття файлу приватного ключа\n";
        return "";
    }

    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "Помилка завантаження приватного ключа\n";
        ERR_print_errors_fp(stderr);
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        std::cerr << "Помилка створення контексту для дешифрування\n";
        EVP_PKEY_free(pkey);
        return "";
    }

    if (EVP_PKEY_decrypt_init(ctx) <= 0) {
        std::cerr << "Помилка ініціалізації дешифрування\n";
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "";
    }

    EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);

    int key_size = EVP_PKEY_size(pkey);
    std::vector<unsigned char> decrypted_data;

    for (size_t i = 0; i < cipherText.size(); i += key_size) {
        std::string block = cipherText.substr(i, key_size);
        size_t outlen;

        if (EVP_PKEY_decrypt(ctx, nullptr, &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "Помилка визначення розміру розшифрованого блоку\n";
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        std::vector<unsigned char> decrypted_block(outlen);
        if (EVP_PKEY_decrypt(ctx, decrypted_block.data(), &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "Помилка дешифрування блоку\n";
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        decrypted_data.insert(decrypted_data.end(), decrypted_block.begin(), decrypted_block.end());
    }

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return std::string(decrypted_data.begin(), decrypted_data.end());
}
// Преобразование std::wstring в UTF-8 std::string
std::string wstring_to_utf8(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    return converter.to_bytes(wstr);
}

// Преобразование UTF-8 std::string в std::wstring
std::wstring utf8_to_wstring(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    return converter.from_bytes(str);
}


