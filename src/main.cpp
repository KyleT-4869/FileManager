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
        std::cout << "start: start a file called data.json and write data into it." << "\n";
        return 0;
    }

    std::string command = argv[1];

    if(command == "move") {
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

    if(command == "start") {
        createJSON();
    }

    if(command == "goto") {
        if(argc < 2) {
            std::cerr << "name and location must be provided" << "\n";
            return 1;
        }
        else {
            std::string filePath = readJSON(argv[2]);
            goTo(filePath);
        }
    }

    if(command == "printall") {
        printAll();
    }

    if(command == "add") {
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