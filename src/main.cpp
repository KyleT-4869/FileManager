#include <iostream>
#include <filesystem>
#include <string>
#include "JSON.h"
#include "FileManager.h"

using namespace JSON;
using namespace FileManager;

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Welcome to FileManager, here are the options: " << "\n";
        std::cout << "move: move the file to a new directory, location must be provided" << "\n";
        return 0;
    }

    if(argv[1] == "move") {
        if(argc < 3) {
            std::cout << "location must be provided" << "\n";
            return 0;
        }
        else {
            std::string originalPath = argv[2];
            std::string filePath = readJSON(argv[3]);
            if(filePath.empty()) {
                return 1;
            }
            else {
                moveFile(originalPath, filePath);
                return 0;
            } 
        }
    }

    if(argv[1] == "add") {
        if(argc < 3) {
            std::cout << "name and location must be provided" << "\n";
        }
    }

}


// int main() {
//     // std::string testString = "re4";
//     // std::cout << JSON::readJSON(testString) << "\n";
//     //JSON::createJSON();
//     // std::string name = "re5";
//     // std::string data = "D:\\FluffyModManager\\Games\\RE4R";
//     // JSON::modifyJSON(name, data);

//     // std::string originalPath = R"(C:\Users\kylet\Downloads\test.txt)";
//     // std::string newRelativePath = R"(C:\Users\kylet\Desktop\TestFolder)";
//     // FileManager::moveFile(originalPath, newRelativePath);

// }