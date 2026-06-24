#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "FileManager.h"

namespace fs = std::filesystem;

void FileManager::moveFile(std::string& originalPath, std::string& newRelativePath) {
    fs::path oldFilePath(originalPath);

    fs::path newFilePath = fs::path(newRelativePath) / oldFilePath.filename();

    fs::rename(oldFilePath, newFilePath);
}