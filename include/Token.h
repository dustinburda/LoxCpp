//
// Created by Dustin on 5/22/25.
//

#ifndef LOXCPP_TOKEN_H
#define LOXCPP_TOKEN_H

#include <string>
#include <variant>

#include "TokenType.h"

class Token {
public:
    Token();
private:
    TokenType type_;
    std::string lexeme_;
    std::variant<std::string, int, double> literal_;
    int line_;
};


#endif //LOXCPP_TOKEN_H
