//
// Created by Dustin on 5/23/25.
//

#include "../include/Scanner.h"

#include <cctype>


#include "../include/Error.h"


Scanner::Scanner(std::string src) : src_{src}, start_{0}, current_{0}, line_{0} {}

std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start_ = current_;
        scanToken();
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
    tokens_.emplace_back(type, src_.substr(start_, current_ - start_), TokenType_Literal[type], line_);
}

bool Scanner::match(char c) {
    if (isAtEnd() || src_[current_] != c)
        return false;

    current_++;
    return true;
}

char Scanner::peek() {
    if (isAtEnd())
        return '\0';

    return src_[current_];
}

char Scanner::peekNext() {
    if (current_ + 1 >= src_.size())
        return '\0';

    return src_[current_ + 1];
}

void Scanner::number() {
    while (std::isdigit(peek()))
        advance();

    if (peek() == '.' && std::isdigit(peekNext())) {
        advance(); // .

        while (std::isdigit(peek()))
            advance();
    }

    auto lexeme = src_.substr(start_, current_ - start_);
    tokens_.emplace_back(TokenType::NUMBER, lexeme, std::stod(lexeme), line_);
}

void Scanner::identifier_keyword() {
    while (std::isalnum(peek()))
        advance();

    auto lexeme = src_.substr(start_, current_ - start_);

    if (Literal_TokenType.count(lexeme) == 0)
        tokens_.emplace_back(TokenType::IDENTIFIER, lexeme, lexeme, line_);
    else
        tokens_.emplace_back(Literal_TokenType[lexeme], lexeme, lexeme, line_);
}

void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line_++;

        advance();
    }

    if (isAtEnd())
        error(line_, "Unterminated string");

    advance(); // "

    std::string literal = src_.substr(start_ + 1, current_ - 1);
    tokens_.emplace_back(TokenType::STRING, literal, literal, line_);
}

void Scanner::scanToken() {
   auto c = advance().value();

   switch (c) {
       case '(' : addToken(TokenType::LEFT_PAREN); break;
       case ')' : addToken(TokenType::RIGHT_PAREN); break;
       case '{' : addToken(TokenType::LEFT_BRACE); break;
       case '}' : addToken(TokenType::RIGHT_BRACE); break;
       case ',' : addToken(TokenType::COMMA); break;
       case '.' : addToken(TokenType::DOT); break;
       case '-' : addToken(TokenType::MINUS); break;
       case '+' : addToken(TokenType::PLUS); break;
       case ';' : addToken(TokenType::SEMICOLON); break;
       case '*' : addToken(TokenType::STAR); break;
       case '!' : addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
       case '=' : addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
       case '>' : addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
       case '<' : addToken(match('=') ? TokenType::LESS : TokenType::LESS_EQUAL); break;
       case '/' : {
           if (match('/')) {
                while (peek() != '\n' && !isAtEnd())
                    advance();
           } else {
               addToken(TokenType::SLASH);
           }
           break;
       }

       case '\n':
           line_++;
           break;
       case '\r':
       case '\t':
       case ' ':
           break;

       case '\"':
           string();
           break;

       default : {
           if (std::isdigit(c)) {
               number();
           } else if (std::isalpha(c)) {
               identifier_keyword();
           } else {
               error(line_, "Unexpected character");
           }

           break;

       }
   }
}
