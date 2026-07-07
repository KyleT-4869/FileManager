#pragma once
#include <string>
#include <filesystem>

namespace JSON {
    void createJSON(const char* pathToJsonFile);
    void modifyJSON(const char* pathToJsonFile, std::string& name, std::string& data);
    std::string readJSON(const char* pathToJsonFile, const char* name);
    void printAll(const char* pathToJsonFile);
}
