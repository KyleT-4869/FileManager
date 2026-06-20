#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include "JSON.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
namespace fs = std::filesystem;

void JSON::createJSON() {
    std::ofstream file;
    file.open("data.json", std::ios::out | std::ios::trunc);
        if(file.is_open()) {

            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            writer.StartObject();

            std::string input;
            std::cout << "Enter a name and an associated location, or enter 'q' to quit" << "\n";
            std::getline(std::cin, input);

            while(input != "q") {

                std::stringstream ss(input);
                std::string name;
                std::string filepath;
                ss >> name >> filepath;
                
                writer.Key(name.c_str());
                writer.String(filepath.c_str()); 

                std::cout << "Enter a name and an associated location, or enter 'q' to quit" << "\n";
                std::getline(std::cin, input);
            }
            
            writer.EndObject();
            file << buffer.GetString();
            file.close();
        } else {
            std::cerr << "unable to open file to write to" << "\n";
        }
    // if(file.is_open()) {
    //     bool first = true;
    //     std::string input;
    //     std::cout << "Enter a name and a location, enter q to quit: " << "\n";
    //     std::getline(std::cin, input);
    //     while(input != "q") {
    //         if(!first) {
    //             file << ",";
    //         }
    //         std::stringstream ss(input);
    //         std::string name;
    //         std::string filepath;
    //         ss >> name;
    //         std::getline(ss, filepath);

    //         if (!filepath.empty() && filepath[0] == ' ') {
    //             filepath.erase(0, 1);
    //         }
    //         StringBuffer buffer;
    //         Writer<StringBuffer> writer(buffer);
    //         writer.StartObject();
    //         writer.Key(name.c_str());
    //         writer.String(filepath.c_str());
    //         writer.EndObject();
    //         file << buffer.GetString();
    //         first = false;

    //         std::cout << "Enter another name and location, enter q to quit" << "\n";
    //         std::getline(std::cin, input);
    //     }
    //     file.close();

    // } else {
    //     std::cerr << "Unable to open file to write to" << "\n";
    // }
}