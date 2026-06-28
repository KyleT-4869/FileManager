#pragma once
#include <string>
 
namespace JSON {
    void createJSON();
    void modifyJSON(std::string& name, std::string& data);
    std::string readJSON(char* name);
}
