#pragma once
#include <string>
#include <filesystem>

namespace FileManager {
    void setUp();
    void moveFile(std::string& originalPath, std::string& newRelativePath);
    void run(std::string& filePath);
    void goTo(std::string& path);
    std::string getLatestDownload();
    std::filesystem::path getDataFilePath();
}