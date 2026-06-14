#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Welcome to FileManager, here are the options:" << "\n";
        std::cout << "move: move the file to a new directory, location must be provided" <<"\n";
        return 1;
    }

    if(argv[1] == "move") {
        if(argv[2] == nullptr) {
            std::cout << "file path must be provided" << "\n";
            return 0;
        }
        if(argv[3] == nullptr) {
            std::cout << "location must be provided" << "\n";
        }
        else {
            std::filesystem::path filePath = argv[2];
            if(argv[3] == "-re4r") {
                std::filesystem::rename(filePath, R"(D:\Fluffy Mod Manager\Games\RE4R\Mods)");
            }
            if(argv[3] == "-sb") {
                std::filesystem::rename(filePath, R"(D:\SteamLibrary\steamapps\common\StellarBlade\SB\Content\Paks\~mods\CustomNanosuitSystem)");
            }
            if(argv[3] == "re9") {
                std::filesystem::rename(filePath, R"(D:\Fluffy Mod Manager\Games\RE9\Mods)");
            }
        }
    }
    
    if(argv[1] == "run") {
        if(argv[2] == nullptr) {
            std::cout << "provide a program to run" << "\n";
            return 0;
        }
        if(argv[2] == "-picture") {
            std::system(R"(explorer.exe C:\Users\kylet\Pictures)");
        }
        if(argv[2] == "-user") {
            std::system(R"(explorer.exe C:\Users)");
        }
    }
}