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
        std::cerr <<"Error: this command must be passed a direcotory path" << "\n";
    }
}

void FileManager::run(std::string& path) {
    fs::path filePath = path;
    if(filePath.extension() != ".exe") {
        std::cerr << "Error: file provided must be an exe file" << "\n";
        std::cerr << "provided file: " << filePath.string() << "\n";
        return;
    }

    fs::directory_entry potentialDirectoryPath(filePath);
    if(potentialDirectoryPath.is_directory()) {
        std::cerr << "Error: must be a file" << "\n";
        return;
    }

    fs::path originalPath = fs::current_path();
    fs::current_path(filePath.parent_path());

    std::system(filePath.string().c_str());
    
    fs::current_path(originalPath);

}