#include "MainForm.h"
#include <commdlg.h>
#include <shlobj.h>
#include <string>
#include <cwchar>
#include <iostream>
#include <stdexcept>
MainForm::MainForm(HINSTANCE hInstance) {
    this->hInstance = hInstance;
}

int MainForm::Run() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return static_cast<int>(msg.wParam);
}

void MainForm::OnEncrypt() {
    if (selectedFile.empty() || selectedKey.empty()) {
        MessageBox(hwnd, L"Будь ласка, оберіть файл і ключ!", L"Помилка", MB_OK | MB_ICONERROR);
        return;
    }

    try {
        std::string plainText = FileHandler::ReadFile(selectedFile);
        std::string encryptedText = cryptoHandler.Encrypt(plainText, selectedKey);

        if (!encryptedText.empty()) {
            FileHandler::WriteFile(selectedFile, encryptedText);
            MessageBox(hwnd, L"Файл зашифровано успішно!", L"Готово", MB_OK | MB_ICONINFORMATION);
        }
        else {
            MessageBox(hwnd, L"Помилка шифрування!", L"Помилка", MB_OK | MB_ICONERROR);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
        MessageBox(hwnd, L"Помилка читання файлу!", L"Помилка", MB_OK | MB_ICONERROR);
    }
}



void MainForm::OnDecrypt() {
    if (selectedFile.empty() || selectedKey.empty()) {
        MessageBox(hwnd, L"Будь ласка, оберіть файл і ключ!", L"Помилка", MB_OK | MB_ICONERROR);
        return;
    }

    try {
        std::string encryptedText = FileHandler::ReadFile(selectedFile);
        std::string decryptedText = cryptoHandler.Decrypt(encryptedText, selectedKey);

        if (!decryptedText.empty()) {
            FileHandler::WriteFile(selectedFile, decryptedText);
            MessageBox(hwnd, L"Файл розшифровано успішно!", L"Готово", MB_OK | MB_ICONINFORMATION);
        }
        else {
            MessageBox(hwnd, L"Помилка дешифрування!", L"Помилка", MB_OK | MB_ICONERROR);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
        MessageBox(hwnd, L"Помилка читання файлу!", L"Помилка", MB_OK | MB_ICONERROR);
    }
}


void MainForm::OnOpenFile() {
    OPENFILENAME ofn;
    wchar_t fileName[MAX_PATH] = L"";
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = L"Text Files\0*.txt\0All Files\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if (GetOpenFileName(&ofn)) {
        char charFileName[MAX_PATH];
        size_t convertedChars = 0;
        wcstombs_s(&convertedChars, charFileName, MAX_PATH, fileName, _TRUNCATE);
        selectedFile = std::string(charFileName);
    }
}

void MainForm::OnSelectKey() {
    OPENFILENAME ofn;
    wchar_t fileName[MAX_PATH] = L"";
    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = L"Key Files\0*.key\0All Files\0*.*\0";
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if (GetOpenFileName(&ofn)) {
        char charFileName[MAX_PATH];
        size_t convertedChars = 0;
        wcstombs_s(&convertedChars, charFileName, MAX_PATH, fileName, _TRUNCATE);
        selectedKey = std::string(charFileName);
    }
}

std::string MainForm::GetSelectedFile() { return selectedFile; }
std::string MainForm::GetSelectedKey() { return selectedKey; }
void MainForm::SetAlgorithm(const std::string& algo) { algorithm = algo; }