#ifndef MAINFORM_H
#define MAINFORM_H

#include <windows.h>
#include <string>
#include "CryptoHandler.h"
#include "FileHandler.h"

class MainForm {
public:
    MainForm(HINSTANCE hInstance);
    int Run();
    void OnEncrypt();
    void OnDecrypt();
    void OnOpenFile();
    void OnSelectKey();
    std::string GetSelectedFile();
    std::string GetSelectedKey();
    void SetAlgorithm(const std::string& algo);
    CryptoHandler cryptoHandler;

private:
    HWND hwnd = nullptr;
    HINSTANCE hInstance;
    
    std::string selectedFile;
    std::string selectedKey;
    std::string algorithm;
};

#endif // MAINFORM_H
