//
// Created by Dustin on 5/22/25.
//

#ifndef LOXCPP_TOKENTYPE_H
#define LOXCPP_TOKENTYPE_H

#include <string>
#include <unordered_map>

enum class TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
// One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
// Literals.
    IDENTIFIER, STRING, NUMBER,
// Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    EOF_
};

std::unordered_map<std::string, TokenType> Keyword_TokenType {
        {"AND", TokenType::AND},
        {"CLASS", TokenType::CLASS},
        {"ELSE", TokenType::ELSE},
        {"FALSE", TokenType::FALSE},
        {"FUN", TokenType::FUN},
        {"FOR", TokenType::FOR},
        {"IF", TokenType::IF},
        {"NIL", TokenType::NIL},
        {"OR", TokenType::OR},
        {"PRINT", TokenType::PRINT},
        {"RETURN", TokenType::RETURN},
        {"SUPER", TokenType::SUPER},
        {"THIS", TokenType::THIS},
        {"TRUE", TokenType::TRUE},
        {"VAR", TokenType::VAR},
        {"WHILE", TokenType::WHILE}
};


#endif //LOXCPP_TOKENTYPE_H
