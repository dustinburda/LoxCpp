//
// Created by Dustin on 5/23/25.
//

#ifndef LOXCPP_SCANNER_H
#define LOXCPP_SCANNER_H

#include "Token.h"

#include <optional>
#include <string>
#include <vector>

class Scanner {
public:
    Scanner() = default;
    Scanner(std::string src);

    std::vector<Token> scanTokens();
private:
    bool isAtEnd();
    std::optional<char> advance();
    void addToken(TokenType type);
    bool match (char c);
    char peek();
    char peekNext();
    void string();
    void number();
    void identifier_keyword();
    void scanToken();

    std::string src_;
    std::vector<Token> tokens_;

    std::size_t start_;
    std::size_t current_;
    std::size_t line_;
};


#endif //LOXCPP_SCANNER_H
