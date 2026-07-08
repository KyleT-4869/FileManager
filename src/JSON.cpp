#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <filesystem>
#include "JSON.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"

using namespace rapidjson;
namespace fs = std::filesystem;

void JSON::createJSON(const char* pathToJsonFile) {
    std::ofstream file;
    file.open(pathToJsonFile, std::ios::out | std::ios::trunc);
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
        std::cerr << "Error: unable to open file to write to" << "\n";
        std::cerr << pathToJsonFile;
    }
}

std::string JSON::readJSON(const char* pathToJsonFile ,const char* name) {
    FILE* fp = fopen(pathToJsonFile, "rb");
    
    if(fp == nullptr) {
        fclose(fp);
        std::cerr << "Error: unable to open data.json" << "\n";
        return "";
    }

    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document doc;
    doc.ParseStream(is);

    if(doc.HasParseError()) {
        fclose(fp);
        std::cerr << "Error parsing JSON: " + doc.GetParseError() << "\n";
        return "";
    }

    if(doc.HasMember(name) && doc[name].IsString()) {
        fclose(fp);
        return doc[name].GetString();
    } else {
        fclose(fp);
        std::cerr << "Error: no filepath associated with the given name" << "\n";
        return "";
    }
}

void JSON::modifyJSON(const char* pathToJsonFile, std::string& name, std::string& data) {
    FILE* fp = fopen(pathToJsonFile, "r");

    if(fp == nullptr) {
        std::cerr << "Unable to open data.json" << "\n";
        return;
    }

    char buffer[65536];
    FileReadStream is(fp, buffer, sizeof(buffer));

    Document d;
    d.ParseStream(is);

    if(d.HasParseError()) {
        fclose(fp);
        std::cerr << "Error parsing JSON: " << d.GetParseError() <<"\n";
        return;
    }

    if(!d.IsObject()) {
        fclose(fp);
        std::cerr <<"Error: JSON root is not an object." << "\n";
        return;
    }

    if(d.HasMember(name.c_str())) {
        d[name.c_str()].SetString(data.c_str(), data.length(), d.GetAllocator());
    } else {
        Value inputName;
        Value inputData;

        inputName.SetString(name.c_str(), name.length(), d.GetAllocator());
        inputData.SetString(data.c_str(), data.length(), d.GetAllocator());
        d.AddMember(inputName, inputData, d.GetAllocator());
    }
    fclose(fp);

    fp = fopen("data.json", "w");
    if(fp == nullptr) {
        std::cerr << "Error: unable to open data.json" << "\n";
        return;
    }

    FileWriteStream os(fp, buffer, sizeof(buffer));
    Writer<FileWriteStream> writer(os);
    d.Accept(writer);

    fclose(fp);
}

void JSON::printAll(const char* pathToJsonFile) {
    FILE* fp = fopen(pathToJsonFile, "rb");

    if(fp == nullptr) {
        std::cerr << "Error: unable to open data.json" << "\n";
        return;
    }

    char buffer[65536];
    FileReadStream is(fp, buffer, sizeof(buffer));

    Document doc;
    doc.ParseStream(is);

    if(doc.HasParseError()) {
        fclose(fp);
        std::cerr << "Error: parsing JSON " << doc.GetParseError() << "\n";
        return;
    }
    if(!doc.IsObject()) {
        fclose(fp);
        std::cerr <<"Error: JSON root is not an object" << "\n";
        return;
    }

    for(Value::ConstMemberIterator itr = doc.MemberBegin(); itr != doc.MemberEnd(); ++itr) {
        std::cout << "\"" << itr->name.GetString() << "\":" << "\"" <<doc[itr->name].GetString() << "\"" <<"\n";
    }
    fclose(fp);
}