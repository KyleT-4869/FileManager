#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Welcome to FileManager, here are the options:" << "\n";
        std::cout << "move: move the file to a new directory, filepath and new location must be provided" <<"\n";
        return 1;
    }
    std::string command = argv[1];

    if(command == "move") {
        if(argc < 3) {
            std::cout << "location must be provided" << "\n";
            return 0;
        }
        std::string location = argv[3];
    
        if(argv[2] == "-latest") {
            
        }
        std::filesystem::path filePath = argv[2];

        if(location == "-re4r") {
            std::filesystem::rename(filePath, R"(D:\Fluffy Mod Manager\Games\RE4R\Mods)");
        }
        if(location == "-sb") {
            std::filesystem::rename(filePath, R"(D:\SteamLibrary\steamapps\common\StellarBlade\SB\Content\Paks\~mods\CustomNanosuitSystem)");
        }
        if(location == "re9") {
            std::filesystem::rename(filePath, R"(D:\Fluffy Mod Manager\Games\RE9\Mods)");
        }
        if(location == "-bak") {
            std::filesystem::rename(filePath, R"()");
        }
    }
    
    if(command == "run") {
        std::string program = argv[2];

        if(program == "-picture") {
            std::system(R"(explorer.exe C:\Users\kylet\Pictures)");
        }
        if(program == "-user") {
            std::system(R"(explorer.exe C:\Users)");
        }
        if(program == "-desk") {
            std::system(R"(explorer.exe C:\Users\kylet\Desktop)");
        }
        if(program =="-download") {
            std::system(R"(explorer.exe C:\Users\kylet\Downloads)");
        }
    }
}