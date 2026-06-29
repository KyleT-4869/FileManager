#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include "FileManager.h"

namespace fs = std::filesystem;

void FileManager::moveFile(std::string& originalPath, std::string& newRelativePath) {
    fs::path oldFilePath(originalPath);

    fs::path newFilePath = fs::path(newRelativePath) / oldFilePath.filename();

    fs::rename(oldFilePath, newFilePath);
}

void FileManager::goTo(std::string& path) {
    fs::path filePath = path;
    fs::directory_entry directoryPath(path);

    if(directoryPath.is_directory()) {
        std::string shellCommmands = "explorer " + directoryPath.path().string();
        std::system(shellCommmands.c_str());
    }
    else {
        std::cerr <<"This command must be passed a direcotory path, not a filepath" << "\n";
    }
}