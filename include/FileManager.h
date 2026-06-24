#pragma once
#include <string>

namespace FileManager {
    void moveFile(std::string& originalPath, std::string& newRelativePath);
    void copyFile(std::string& filePath, std::string& copyLocation);
    void deleteFile(std::string& filePath);
    void run(std::string& filePath);
    void goTo(std::string& path);
}