#pragma once
#include <string>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    json j;
    j["name"] = "Lewis Hamilton";
    j["team"] = "Mercedes";
    j["titles"] = 7;

    std::cout << j.dump(4) << std::endl; // pretty-print
}

