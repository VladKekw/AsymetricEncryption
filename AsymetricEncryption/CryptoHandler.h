#ifndef CRYPTOHANDLER_H
#define CRYPTOHANDLER_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <string>

class CryptoHandler {
public:
    CryptoHandler();
    void GenerateKeys(const std::string& publicKeyFile, const std::string& privateKeyFile);
    std::string Encrypt(const std::string& plainText, const std::string& publicKeyFile);
    std::string Decrypt(const std::string& cipherText, const std::string& privateKeyFile);
};

#endif // CRYPTOHANDLER_H
