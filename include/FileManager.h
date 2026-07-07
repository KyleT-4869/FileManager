#pragma once
#include <string>

namespace FileManager {
    bool setUp();
    void moveFile(std::string& originalPath, std::string& newRelativePath);
    void run(std::string& filePath);
    void goTo(std::string& path);
    std::string getLatestDownload();
    std::string_view getDataFilePath();
}