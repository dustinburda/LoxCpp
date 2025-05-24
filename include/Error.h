//
// Created by Dustin on 5/23/25.
//

#ifndef LOXCPP_ERROR_H
#define LOXCPP_ERROR_H

#include <string>
#include <iostream>

static bool hadError = false;

static void report(int line, std::string where, std::string message) {
    std::cout << "[line " + std::to_string(line) + "] Error" + where + ": " + message;
    hadError = true;
}

static void error (int line, std::string message) {
    report(line, "", message);
}

#endif //LOXCPP_ERROR_H
