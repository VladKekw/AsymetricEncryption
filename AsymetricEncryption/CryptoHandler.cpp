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
#include <openssl/ec.h>  
#include <openssl/rand.h>


namespace fs = std::filesystem;

CryptoHandler::CryptoHandler() {}


//void CryptoHandler::GenerateKeys(const std::string& publicKeyFile, const std::string& privateKeyFile) {
//    if (currentAlgorithm == "RSA") {
//        GenerateKeysRSA(publicKeyFile, privateKeyFile);
//    }
//    else if (currentAlgorithm == "ElGamal") {
//        GenerateKeysElGamal(publicKeyFile, privateKeyFile);
//    }
//    else if (currentAlgorithm == "ECC") {
//        GenerateKeysECC(publicKeyFile, privateKeyFile);
//    }
//}

void CryptoHandler::GenerateKeys(const std::string& publicKeyFile, const std::string& privateKeyFile) {
    try {
        for (int i = 0; i < 10; ++i) {
            std::string pubTmp = "temp_pub_" + std::to_string(i) + ".key";
            std::string privTmp = "temp_priv_" + std::to_string(i) + ".key";

            if (currentAlgorithm == "RSA") {
                GenerateKeysRSA(pubTmp, privTmp);
            }
            else if (currentAlgorithm == "ElGamal") {
                GenerateKeysElGamal(pubTmp, privTmp);
            }
            else if (currentAlgorithm == "ECC") {
                GenerateKeysECC(pubTmp, privTmp);
            }

           
            if (std::filesystem::exists(pubTmp)) {
                std::filesystem::remove(pubTmp);
            }
            if (std::filesystem::exists(privTmp)) {
                std::filesystem::remove(privTmp);
            }
        }

        // final keys
        if (currentAlgorithm == "RSA") {
            GenerateKeysRSA(publicKeyFile, privateKeyFile);
        }
        else if (currentAlgorithm == "ElGamal") {
            GenerateKeysElGamal(publicKeyFile, privateKeyFile);
        }
        else if (currentAlgorithm == "ECC") {
            GenerateKeysECC(publicKeyFile, privateKeyFile);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка при генерації ключів: " << e.what() << std::endl;
    }
}


void CryptoHandler::GenerateKeysElGamal(const std::string& publicKeyFile, const std::string& privateKeyFile) {
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_DHX, nullptr);
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

void CryptoHandler::GenerateKeysRSA(const std::string& publicKeyFile, const std::string& privateKeyFile) {
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

void CryptoHandler::GenerateKeysECC(const std::string& publicKeyFile, const std::string& privateKeyFile) {
    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, nullptr);
    EVP_PKEY* pkey = nullptr;

    if (!ctx || EVP_PKEY_keygen_init(ctx) <= 0 ||
        EVP_PKEY_CTX_set_ec_paramgen_curve_nid(ctx, NID_X9_62_prime256v1) <= 0 ||
        EVP_PKEY_generate(ctx, &pkey) <= 0) {
        std::cerr << "Помилка генерації ECC ключів\n";
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
    if (currentAlgorithm == "RSA") {
        return EncryptRSA(plainText, publicKeyFile);
    }
    else if (currentAlgorithm == "ElGamal") {
        return EncryptElGamal(plainText, publicKeyFile);
    }
    else if (currentAlgorithm == "ECC") {
        EncryptECC(plainText, publicKeyFile);
    }
    return "";
}

std::string CryptoHandler::EncryptECC(const std::string& plainText, const std::string& publicKeyFile) {
    BIO* keybio = BIO_new_file(publicKeyFile.c_str(), "r");
    EVP_PKEY* pkey = PEM_read_bio_PUBKEY(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "Помилка генерації публічного ключа\n";
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    EVP_PKEY_encrypt_init(ctx);

    size_t outlen;
    EVP_PKEY_encrypt(ctx, nullptr, &outlen, (unsigned char*)plainText.c_str(), plainText.size());
    std::vector<unsigned char> encryptedText(outlen);
    if (EVP_PKEY_encrypt(ctx, encryptedText.data(), &outlen, (unsigned char*)plainText.c_str(), plainText.size()) <= 0) {
        std::cerr << "Помилка шифрування\n";
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "";
    }

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return std::string(encryptedText.begin(), encryptedText.end());
}




std::string CryptoHandler::EncryptElGamal(const std::string& plainText, const std::string& publicKeyFile) {
    BIO* keybio = BIO_new_file(publicKeyFile.c_str(), "r");
    EVP_PKEY* pkey = PEM_read_bio_PUBKEY(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "Помилка завантаження ключа: " << publicKeyFile << "\n";
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    EVP_PKEY_encrypt_init(ctx);

    size_t outlen;
    EVP_PKEY_encrypt(ctx, nullptr, &outlen, (unsigned char*)plainText.c_str(), plainText.size());
    std::vector<unsigned char> encryptedText(outlen);
    EVP_PKEY_encrypt(ctx, encryptedText.data(), &outlen, (unsigned char*)plainText.c_str(), plainText.size());

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return std::string(encryptedText.begin(), encryptedText.end());
}


std::string CryptoHandler::EncryptRSA(const std::string& plainText, const std::string& publicKeyFile) {
    BIO* keybio = BIO_new_file(publicKeyFile.c_str(), "r");
    if (!keybio) {
        std::cerr << "??????? ???????? ????? ????????? ?????: " << publicKeyFile << "\n";
        return "";
    }

    EVP_PKEY* pkey = PEM_read_bio_PUBKEY(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "??????? ???????????? ????????? ?????: " << publicKeyFile << "\n";
        ERR_print_errors_fp(stderr);
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        std::cerr << "??????? ????????? ????????? ??? ??????????\n";
        EVP_PKEY_free(pkey);
        return "";
    }

    if (EVP_PKEY_encrypt_init(ctx) <= 0) {
        std::cerr << "??????? ???????????? ??????????\n";
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "";
    }

    EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);

    int key_size = EVP_PKEY_size(pkey);
    int max_data_size = key_size - 42;  // ??????????? RSA PKCS1_OAEP_PADDING

    std::vector<unsigned char> encrypted_data;

    for (size_t i = 0; i < plainText.size(); i += max_data_size) {
        std::string block = plainText.substr(i, max_data_size);
        size_t outlen;

        if (EVP_PKEY_encrypt(ctx, nullptr, &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "??????? ?????????? ?????? ????????????? ?????\n";
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        std::vector<unsigned char> encrypted_block(outlen);
        if (EVP_PKEY_encrypt(ctx, encrypted_block.data(), &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "??????? ?????????? ?????\n";
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
    if (currentAlgorithm == "RSA") {
        return DecryptRSA(cipherText, privateKeyFile);
    }
    else if (currentAlgorithm == "ElGamal") {
        return DecryptElGamal(cipherText, privateKeyFile);
    }
    else if (currentAlgorithm == "ECC") {
        DecryptECC(cipherText, privateKeyFile);
    }
    return "";
}
std::string CryptoHandler::DecryptElGamal(const std::string& cipherText, const std::string& privateKeyFile) {
    BIO* keybio = BIO_new_file(privateKeyFile.c_str(), "r");
    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "Помилка завантаження приватного ключа: " << privateKeyFile << "\n";
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    EVP_PKEY_decrypt_init(ctx);

    size_t outlen;
    EVP_PKEY_decrypt(ctx, nullptr, &outlen, (unsigned char*)cipherText.c_str(), cipherText.size());
    std::vector<unsigned char> decryptedText(outlen);
    EVP_PKEY_decrypt(ctx, decryptedText.data(), &outlen, (unsigned char*)cipherText.c_str(), cipherText.size());

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return std::string(decryptedText.begin(), decryptedText.end());
}


std::string CryptoHandler::DecryptRSA(const std::string& cipherText, const std::string& privateKeyFile) {
    if (cipherText.empty()) {
        std::cerr << "???????: ??????? ????? ????????!\n";
        return "";
    }

    BIO* keybio = BIO_new_file(privateKeyFile.c_str(), "r");
    if (!keybio) {
        std::cerr << "??????? ???????? ????? ?????????? ?????\n";
        return "";
    }

    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "??????? ???????????? ?????????? ?????\n";
        ERR_print_errors_fp(stderr);
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    if (!ctx) {
        std::cerr << "??????? ????????? ????????? ??? ????????????\n";
        EVP_PKEY_free(pkey);
        return "";
    }

    if (EVP_PKEY_decrypt_init(ctx) <= 0) {
        std::cerr << "??????? ???????????? ????????????\n";
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
            std::cerr << "??????? ?????????? ?????? ?????????????? ?????\n";
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            return "";
        }

        std::vector<unsigned char> decrypted_block(outlen);
        if (EVP_PKEY_decrypt(ctx, decrypted_block.data(), &outlen, (unsigned char*)block.c_str(), block.size()) <= 0) {
            std::cerr << "??????? ???????????? ?????\n";
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


std::string CryptoHandler::DecryptECC(const std::string& cipherText, const std::string& privateKeyFile) {
    BIO* keybio = BIO_new_file(privateKeyFile.c_str(), "r");
    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(keybio, nullptr, nullptr, nullptr);
    BIO_free(keybio);

    if (!pkey) {
        std::cerr << "Помилка завантаження приватного ключа\n";
        return "";
    }

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);
    EVP_PKEY_decrypt_init(ctx);

    size_t outlen;
    EVP_PKEY_decrypt(ctx, nullptr, &outlen, (unsigned char*)cipherText.c_str(), cipherText.size());
    std::vector<unsigned char> decryptedText(outlen);
    if (EVP_PKEY_decrypt(ctx, decryptedText.data(), &outlen, (unsigned char*)cipherText.c_str(), cipherText.size()) <= 0) {
        std::cerr << "Помилка дешифрування\n";
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return "";
    }

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return std::string(decryptedText.begin(), decryptedText.end());
}

void CryptoHandler::BackupFile(const std::string& originalFilePath) {
    namespace fs = std::filesystem;

    fs::path originalPath(originalFilePath);
    if (!fs::exists(originalPath)) return;

    
    std::string baseName = originalPath.stem().string(); 
    std::string ext = originalPath.extension().string();
    fs::path copyPath = originalPath.parent_path() / (baseName + "_copy" + ext);

    fs::copy_file(originalPath, copyPath, fs::copy_options::overwrite_existing);
}