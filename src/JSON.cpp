#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <cstdio>
#include "JSON.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"

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
}

std::string JSON::readJSON(std::string& name) {
    FILE* fp = fopen("data.json", "rb");
    
    if(fp == nullptr) {
        std::cerr << "Error: unable to open data.json" << "\n";
        return nullptr;
    }

    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document doc;
    doc.ParseStream(is);

    if(doc.HasParseError()) {
        std::cerr << "Error: failed to parse JSON document" << "\n";
        return nullptr;
    }

    if(doc.HasMember(name.c_str()) && doc[name.c_str()].IsString()) {
        return doc[name.c_str()].GetString();
    } else {
        std::cerr << "Error: no filepath associated with the given name" << "\n";
    }
}