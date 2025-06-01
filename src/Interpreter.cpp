//
// Created by Dustin on 5/31/25.
//

#include "../include/Interpreter.h"

#include <variant>

#include "../include/Binary.h"
#include "../include/Grouping.h"
#include "../include/Literal.h"
#include "../include/Unary.h"

std::any Interpreter::evaluate(Expression* expr) {
    expr->accept( *dynamic_cast<ExprVisitor<std::any>*>(this) );
}

std::any Interpreter::visitBinary(Binary& expr) {
    auto left = evaluate(expr.left_.get());
    auto right = evaluate(expr.right_.get());

    switch (expr.operator_.type_) {
        case TokenType::PLUS:
        case TokenType::MINUS:
        case TokenType::SLASH:
        case TokenType::STAR:
        case TokenType::GREATER:
        case TokenType::GREATER_EQUAL:
        case TokenType::LESS:
        case TokenType::LESS_EQUAL:
    }

    return nullptr; // Unreachable
}

std::any Interpreter::visitGrouping(Grouping& expr) {
    return evaluate(expr.expr_.get());
}


std::any Interpreter::visitLiteral(Literal& expr) {
    return expr.literal_; // std::variant<int, double, std::string, double>
}


std::any Interpreter::visitUnary(Unary& expr) {
    auto right = std::any_cast<LiteralType>(evaluate(expr.right_.get()));

    auto value = getLiteralValue(right);

    switch (expr.operator_.type_) {
        case TokenType::BANG:
            return !std::any_cast<bool>(value);
        case TokenType::MINUS:
            if (value.type() == typeid(int))
                return -std::any_cast<int>(value);
            else if (value.type() == typeid(double ))
                return -std::any_cast<double>(value);
    }

    return nullptr; // Unreachable
}