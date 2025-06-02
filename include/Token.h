//
// Created by Dustin on 5/22/25.
//

#ifndef LOXCPP_TOKEN_H
#define LOXCPP_TOKEN_H

#include <string>
#include <variant>

#include "TokenType.h"

using LiteralType = std::variant<std::string, double, bool>;

class Token {
public:
    Token();
    Token(TokenType type, std::string lexeme, LiteralType literal, int line);

    std::string toString() const;

    TokenType type_;
    std::string lexeme_;
    LiteralType literal_;
    int line_;
};


#endif //LOXCPP_TOKEN_H
