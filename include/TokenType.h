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

static std::unordered_map<std::string, TokenType> Literal_TokenType {
        {"(", TokenType::LEFT_PAREN},
        {")", TokenType::RIGHT_BRACE},
        {"{", TokenType::LEFT_BRACE},
        {"}", TokenType::RIGHT_BRACE},
        {",", TokenType::COMMA},
        {".", TokenType::DOT},
        {"+", TokenType::PLUS},
        {"-", TokenType::MINUS},
        {";", TokenType::SEMICOLON},
        {"/", TokenType::SLASH},
        {"*", TokenType::STAR},

        {"!", TokenType::BANG},
        {"!=", TokenType::BANG_EQUAL},
        {"=", TokenType::EQUAL},
        {"==", TokenType::EQUAL_EQUAL},
        {">", TokenType::GREATER},
        {">=", TokenType::GREATER_EQUAL},
        {"<", TokenType::LESS},
        {"<=", TokenType::LESS_EQUAL},

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

static std::unordered_map<TokenType, std::string> TokenType_Literal {
        {TokenType::LEFT_PAREN, "LEFT_PAREN"},
        {TokenType::RIGHT_BRACE, "RIGHT_PAREN"},
        {TokenType::LEFT_BRACE, "LEFT_BRACE"},
        {TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
        {TokenType::COMMA, "COMMA"},
        {TokenType::DOT, "DOT"},
        {TokenType::PLUS, "PLUS"},
        {TokenType::MINUS, "MINUS"},
        {TokenType::SEMICOLON, "SEMI-COLON"},
        {TokenType::SLASH, "SLASH"},
        {TokenType::STAR, "STAR"},

        {TokenType::BANG, "BANG"},
        {TokenType::BANG_EQUAL, "BANG_EQUAL"},
        {TokenType::EQUAL, "EQUAL"},
        {TokenType::EQUAL_EQUAL, "EQUAL EQUAL"},
        {TokenType::GREATER, "GREATER"},
        {TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
        {TokenType::LESS, "LESS"},
        {TokenType::LESS_EQUAL, "LESS_EQUAL"},

        {TokenType::IDENTIFIER, "IDENTIFIER"},
        {TokenType::STRING, "STRING"},
        {TokenType::NUMBER, "NUMBER"},



        {TokenType::AND, "AND"},
        {TokenType::CLASS, "CLASS"},
        {TokenType::ELSE, "ELSE"},
        {TokenType::FALSE, "FALSE"},
        {TokenType::FUN, "FUN"},
        {TokenType::FOR, "FOR"},
        {TokenType::IF, "IF"},
        {TokenType::NIL, "NIL"},
        {TokenType::OR, "OR"},
        {TokenType::PRINT, "PRINT"},
        {TokenType::RETURN, "RETURN"},
        {TokenType::SUPER, "SUPER"},
        {TokenType::THIS, "THIS"},
        {TokenType::TRUE, "TRUE"},
        {TokenType::VAR, "VAR"},
        {TokenType::WHILE, "WHILE"}
};



#endif //LOXCPP_TOKENTYPE_H
