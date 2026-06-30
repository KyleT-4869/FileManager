#pragma once
#include <string>

namespace FileManager {
    void moveFile(std::string& originalPath, std::string& newRelativePath);
    void run(std::string& filePath);
    void goTo(std::string& path);
}