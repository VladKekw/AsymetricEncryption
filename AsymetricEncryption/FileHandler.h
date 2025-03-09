#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler {
public:
    static std::string ReadFile(const std::string& filePath);
    static void WriteFile(const std::string& filePath, const std::string& data);
    static void DeleteFile(const std::string& filePath);
};

#endif // FILEHANDLER_H
