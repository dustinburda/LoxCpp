//
// Created by Dustin on 5/23/25.
//

#include "../include/Scanner.h"



#include "../include/Error.h"


Scanner::Scanner(std::string src) : src_{src}, start_{0}, current_{0}, line_{0} {}

std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start_ = current_;
        scanTokens();
    }

    tokens_.emplace_back(TokenType::EOF_, "", "", line_);
    return tokens_;
}

bool Scanner::isAtEnd() {
    return current_ >= src_.size();
}

std::optional<char> Scanner::advance() {
    if (isAtEnd())
        return std::nullopt;

    char c = src_[current_];
    current_++;
    return c;

}

void Scanner::addToken(TokenType type) {
    tokens_.emplace_back(type, src_.substr(current_, current_ - start_), TokenType_Literal[type], line_);
}

bool Scanner::match(char c) {
    if (isAtEnd() || src_[current_] != c)
        return false;

    current_++;
    return true;
}

void Scanner::scanToken() {
   auto c = advance();

   switch (c.value()) {
       case '(' : addToken(TokenType::LEFT_PAREN); break;
       case ')' : addToken(TokenType::RIGHT_PAREN); break;
       case '{' : addToken(TokenType::LEFT_BRACE); break;
       case '}' : addToken(TokenType::RIGHT_BRACE); break;
       case ',' : addToken(TokenType::COMMA); break;
       case '.' : addToken(TokenType::DOT); break;
       case '-' : addToken(TokenType::MINUS); break;
       case '+' : addToken(TokenType::LEFT_PAREN); break;
       case ';' : addToken(TokenType::SEMICOLON); break;
       case '/' : addToken(TokenType::SLASH); break;
       case '*' : addToken(TokenType::STAR); break;
       case '!' : addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
       case '=' : addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
       case '>' : addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
       case '<' : addToken(match('=') ? TokenType::LESS : TokenType::LESS_EQUAL); break;

       default : {
            error(line_, "Unexpected character");
            break;
       }
   }
}
