#include "FileHandler.h"
#include <fstream>
#include <stdexcept>
#include <filesystem>
#include <ctime>
namespace fs = std::filesystem;

std::string FileHandler::ReadFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::in | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Не вдалося відкрити файл для читання");
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void FileHandler::WriteFile(const std::string& filePath, const std::string& data) {
    //if (fs::exists(filePath)) {
    //    fs::remove(filePath);  // Видаляємо старий файл перед записом нового
    //}
    std::ofstream file(filePath, std::ios::out | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Не вдалося відкрити файл для запису");
    }

    file.write(data.c_str(), data.size());
    file.close();
}

//void FileHandler::WriteFile(const std::string& filePath, const std::string& data) {
//    std::ofstream file(filePath, std::ios::out | std::ios::binary);
//    if (!file) {
//        throw std::runtime_error("Не вдалося відкрити файл для запису");
//    }
//    file.write(data.c_str(), data.size());
//    file.close();
//
//
//    std::string copyFilePath = filePath + "_copy.txt";
//
//
//    std::ofstream copyFile(copyFilePath, std::ios::out | std::ios::binary);
//    if (!copyFile) {
//        throw std::runtime_error("Не вдалося створити копію файлу");
//    }
//    copyFile.write(data.c_str(), data.size());
//    copyFile.close();
//
//
//}

void FileHandler::DeleteFile(const std::string& filePath) {
    if (fs::exists(filePath)) {
        fs::remove(filePath);
    }
}