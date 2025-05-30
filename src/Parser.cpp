//
// Created by Dustin on 5/26/25.
//

#include "../include/Binary.h"
#include "../include/Error.h"
#include "../include/Literal.h"
#include "../include/Parser.h"
#include "../include/Unary.h"

Parser::Parser(std::vector<Token> tokens) : tokens_{tokens}, current_{0} {}

std::shared_ptr<Expression> Parser::parse() {
    try {
        return expression();
    } catch (std::exception& e) {
        return nullptr;
    }
}

bool Parser::isAtEnd() {
    return peek().type_ == TokenType::EOF_;
}

Token Parser::peek() {
    return tokens_[current_];
}

Token Parser::previous() {
    return tokens_[current_ - 1];
}

bool Parser::check(TokenType type) {
    if (isAtEnd())
        return false;

    return tokens_[current_].type_ == type;
}

Token Parser::advance() {
    if (!isAtEnd())
        current_++;
    return tokens_[current_ - 1];
}

bool Parser::match(std::initializer_list<TokenType> types) {
    for (auto type : types) {
        if (check(type))
        {
            advance();
            return true;
        }
    }

    return false;
}

std::shared_ptr<Expression> Parser::expression() {
    return equality();
}

std::shared_ptr<Expression> Parser::equality() {
    auto expr_comparison = comparison();

    while (match({TokenType::EQUAL_EQUAL, TokenType::BANG_EQUAL})) {
        Token _operator = previous();
        auto right = comparison();
        expr_comparison = std::make_shared<Binary>(std::move(expr_comparison), _operator, right);
    }

    return expr_comparison;
}

std::shared_ptr<Expression> Parser::comparison() {
    auto expr_term = term();

    while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL}))
    {
        Token _operator = previous();
        auto right = term();
        expr_term = std::make_shared<Binary>(std::move(expr_term), _operator, right);
    }

    return expr_term;
}

std::shared_ptr<Expression> Parser::term() {
    auto expr_factor = factor();

    while (match({TokenType::MINUS, TokenType::PLUS})) {
        Token _operator = previous();
        auto right = factor();
        expr_factor = std::make_shared<Binary>(std::move(expr_factor), _operator, right);
    }

    return expr_factor;
}

std::shared_ptr<Expression> Parser::factor() {
    auto expr_unary = unary();

    while (match({TokenType::SLASH, TokenType::STAR})) {
        Token _operator = previous();
        auto right = unary();
        expr_unary = std::make_shared<Binary>(std::move(expr_unary), _operator, right);
    }

    return expr_unary;
}

std::shared_ptr<Expression> Parser::unary() {
    std::shared_ptr<Expression> expr_unary;

    if (match({TokenType::BANG, TokenType::MINUS})) {
        Token _operator = previous();
        auto right = unary();
        expr_unary = std::make_shared<Unary>(right, _operator);
    } else {
        expr_unary = primary();
    }

    return expr_unary;
}

void reportError(Token token, std::string message) {
    if (token.type_ == TokenType::EOF_) {
        report(token.line_, " at end", message);
    } else {
        report(token.line_, " at " + token.lexeme_ + "'", message);
    }
}

ParseError error(Token token, std::string message) {
    reportError(token, message);
    return ParseError(message);
}


Token Parser::consume(TokenType type, std::string error_message) {
    if (check(type))
        return advance();

    throw error(peek(), error_message);
}

void Parser::synchronize() {
    advance();

    while (!isAtEnd()) {
        if (previous().type_ == TokenType::SEMICOLON)
            return;

        switch (peek().type_) {
            case TokenType::CLASS:
            case TokenType::FUN:
            case TokenType::VAR:
            case TokenType::FOR:
            case TokenType::IF:
            case TokenType::WHILE:
            case TokenType::PRINT:
            case TokenType::RETURN:
                return;
        }

        advance();
    }
}

std::shared_ptr<Expression> Parser::primary() {
    if (match({TokenType::NUMBER,TokenType::STRING}))
        return std::make_shared<Literal>(previous().literal_);
    else if (match({TokenType::FALSE}))
        return std::make_shared<Literal>(false);
    else if (match({TokenType::TRUE}))
        return std::make_shared<Literal>(true);
    else if (match({TokenType::NIL} ))
        return std::make_shared<Literal>(nullptr);
    else if (match({TokenType::LEFT_PAREN})) {
        auto expr = expression();
        consume(TokenType::RIGHT_PAREN, "Expect ')' after expression");
        return expr;
    }

    throw error ( peek(), "Expect expression" );
}