//
// Created by Dustin on 5/26/25.
//

#ifndef LOXCPP_PARSER_H
#define LOXCPP_PARSER_H

#include "Token.h"

#include <exception>
#include <string>
#include <vector>

#include "Expression.h"


class ParseError : public std::exception {
public:
    ParseError(std::string error_message) : error_message_{error_message} {}
    const char* what() const noexcept override { return error_message_.data(); }
private:
    std::string error_message_;
};

class Parser {
public:
    Parser(std::vector<Token> tokens);

private:
    bool isAtEnd();
    bool check(TokenType type);
    bool match(std::initializer_list<TokenType> types);
    Token peek();
    Token advance();
    Token previous();

    Token consume(TokenType type, std::string error_message);

    std::shared_ptr<Expression> expression();
    std::shared_ptr<Expression> equality();
    std::shared_ptr<Expression> comparison();
    std::shared_ptr<Expression> term();
    std::shared_ptr<Expression> factor();
    std::shared_ptr<Expression> unary();
    std::shared_ptr<Expression> primary();

    std::vector<Token> tokens_;
    int current_;
};


#endif //LOXCPP_PARSER_H
