#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include "FileManager.h"
#include "JSON.h"

namespace fs = std::filesystem;
using namespace JSON;

bool::FileManager::setUp() {
    
}

void FileManager::moveFile(std::string& originalPath, std::string& newRelativePath) {
    fs::path oldFilePath(originalPath);
    fs::path relativePath(newRelativePath);
    fs::directory_entry potentialDirectory(oldFilePath);

    if(potentialDirectory.is_directory()) {
        if(oldFilePath.root_name() != relativePath.root_name()) {
            fs::path newFilepath = relativePath / oldFilePath.filename();
            fs::copy(oldFilePath, newFilepath);
            fs::remove_all(oldFilePath);
        }
        else {
            fs::path newFilePath = relativePath / oldFilePath.filename();
            fs::rename(oldFilePath, newFilePath);
        }
    }
    else {
        fs::path oldFilePath(originalPath);
        fs::path newFilePath = fs::path(newRelativePath) / oldFilePath.filename();
        fs::rename(oldFilePath, newFilePath);
    }
    
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

// std::string FileManager::getLatestDownload() {
//     //fs::path originalPath = fs::current_path();
//     std::string_view sv {readJSON("download")};

//     if(sv == "") {
//         std::cerr << "Error: cannot find 'download' and it's associated filepath in data.json" << "\n";
//         return nullptr;
//     }
//     // else {
        
//     // }
// }