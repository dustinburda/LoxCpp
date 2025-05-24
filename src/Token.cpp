//
// Created by Dustin on 5/22/25.
//

#include "../include/Token.h"

Token::Token(TokenType type, std::string lexeme, LiteralType literal, int line)
    : type_{type}, lexeme_{lexeme}, literal_{literal}, line_{line} {}

std::string Token::toString() const {
    std::string literal_str;

    if (auto literal_ptr = std::get_if<int>(&literal_))
        literal_str = std::to_string(*literal_ptr);
    else if (auto literal_ptr = std::get_if<double>(&literal_))
        literal_str = std::to_string(*literal_ptr);
    else if (auto literal_ptr = std::get_if<std::string>(&literal_))
        literal_str = *literal_ptr;

    return TokenType_Literal[type_] + " " +lexeme_ + " " + literal_str;
}
