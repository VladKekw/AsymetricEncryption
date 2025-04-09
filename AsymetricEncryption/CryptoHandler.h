#ifndef CRYPTOHANDLER_H
#define CRYPTOHANDLER_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <string>

class CryptoHandler {
public:
    CryptoHandler();
    std::string currentAlgorithm = "RSA";
    void BackupFile(const std::string& originalFilePath);
    void GenerateKeys(const std::string& publicKeyFile, const std::string& privateKeyFile);
    std::string Encrypt(const std::string& plainText, const std::string& publicKeyFile);
    std::string Decrypt(const std::string& cipherText, const std::string& privateKeyFile);

    void GenerateKeysRSA(const std::string& publicKeyFile, const std::string& privateKeyFile);
    std::string EncryptRSA(const std::string& plainText, const std::string& publicKeyFile);
    std::string DecryptRSA(const std::string& cipherText, const std::string& privateKeyFile);

    void GenerateKeysElGamal(const std::string& publicKeyFile, const std::string& privateKeyFile);
    std::string EncryptElGamal(const std::string& plainText, const std::string& publicKeyFile);
    std::string DecryptElGamal(const std::string& cipherText, const std::string& privateKeyFile);

    void GenerateKeysECC(const std::string& publicKeyFile, const std::string& privateKeyFile);
    std::string EncryptECC(const std::string& plainText, const std::string& publicKeyFile);
    std::string DecryptECC(const std::string& cipherText, const std::string& privateKeyFile);

};

#endif // CRYPTOHANDLER_H
