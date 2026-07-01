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
        std::cout << ". move: move the file to a new directory, location must be provided" << "\n";
        std::cout << ". start: start a file called data.json and write data into it." << "\n";
        std::cout << ". printall: print out all the data inside of data.json to console" << "\n";
        std::cout << ". goto: go to a specific directory in file explorer" << "\n";
        std::cout << ". run: run the specified exe file" << "\n";
        return 0;
    }

    std::string command = argv[1];
    constexpr char kGeneralErrorMessage[] {"Error: name and location must be provided"};
    constexpr char kRunErrorMessage[] {"Error: name must be provided"};

    if(command == "start") {
        createJSON();
    }

    if(command == "printall") {
        printAll();
    }

    if(command == "goto") {
        if(argc < 3) {
            std::cerr << kGeneralErrorMessage << "\n";
            return 1;
        }
        else {
            std::string filePath = readJSON(argv[2]);
            goTo(filePath);
        }
    }

    if(command == "add") {
        if(argc < 4) {
            std::cerr << kGeneralErrorMessage << "\n";
            return 1;
        }
        else {
            std::string name = argv[2];
            std::string filePath = argv[3];
            modifyJSON(name, filePath);
        }
    }

    if(command == "run") {
        if(argc < 3) {
            std::cerr << kRunErrorMessage << "\n";
            return 1;
        }
        else {
            std::string filePath = readJSON(argv[2]);
            run(filePath);
        }
    }

    if(command == "move") {
        if(argc < 4) {
            std::cerr << kGeneralErrorMessage << "\n";
            return 1;
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

}
