//
// Created by Dustin on 5/22/25.
//

#include "../include/Token.h"

Token::Token(TokenType type, std::string lexeme, LiteralType literal, int line)
    : type_{type}, lexeme_{lexeme}, literal_{literal}, line_{line} {}

std::string Token::toString() const {
    return TokenType_Literal[type_] + " " + lexeme_;
}
