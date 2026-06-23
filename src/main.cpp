#include <iostream>
#include <filesystem>
#include <string>
#include "JSON.h"

/*
int main(int argc, char* argv[]) {
    
}
*/

int main() {
    // std::string testString = "re4";
    // std::cout << JSON::readJSON(testString) << "\n";
    //JSON::createJSON();
    std::string name = "re5";
    std::string data = "D:\\FluffyModManager\\Games\\RE4R";
    JSON::modifyJSON(name, data);
}