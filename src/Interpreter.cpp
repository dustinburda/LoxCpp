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
    return expr->accept( *dynamic_cast<ExprVisitor<std::any>*>(this) );
}

bool Interpreter::isEqual(std::any left, std::any right) {
    if (left.type() == right.type()) {
        if (left.type() == typeid(bool))
            return std::any_cast<bool>(left) == std::any_cast<bool>(right);
        if (left.type() == typeid(std::string))
            return std::any_cast<std::string>(left) == std::any_cast<std::string>(right);
        if (left.type() == typeid(double))
            return std::any_cast<double>(left) == std::any_cast<double>(right);
    }
    else
        return false;
}

std::any Interpreter::visitBinary(Binary& expr) {
    auto left = evaluate(expr.left_.get());
    auto right = evaluate(expr.right_.get());

    switch (expr.operator_.type_) {
        case TokenType::PLUS:
            if (left.type() == typeid(std::string) && right.type() == typeid(std::string))
                return std::any_cast<std::string>(left) + std::any_cast<std::string>(right);
            else if (left.type() == typeid(double) && right.type() == typeid(double))
                return std::any_cast<double>(left) + std::any_cast<double>(right);
        case TokenType::MINUS:
            return std::any_cast<double>(left) - std::any_cast<double>(right);
        case TokenType::SLASH:
            return std::any_cast<double>(left) / std::any_cast<double>(right);
        case TokenType::STAR:
            return std::any_cast<double>(left) * std::any_cast<double>(right);
        case TokenType::GREATER:
            return std::any_cast<double>(left) > std::any_cast<double>(right);
        case TokenType::GREATER_EQUAL:
            return std::any_cast<double>(left) >= std::any_cast<double>(right);
        case TokenType::LESS:
            return std::any_cast<double>(left) < std::any_cast<double>(right);
        case TokenType::LESS_EQUAL:
            return std::any_cast<double>(left) <= std::any_cast<double>(right);
        case TokenType::BANG_EQUAL:
            return !isEqual(left, right);
        case TokenType::EQUAL_EQUAL:
            return isEqual(left, right);

    }

    return nullptr; // Unreachable
}

std::any Interpreter::visitGrouping(Grouping& expr) {
    return evaluate(expr.expr_.get());
}


std::any Interpreter::visitLiteral(Literal& expr) {
    return getLiteralValue(expr.literal_); // std::variant<int, double, std::string, double>
}


std::any Interpreter::visitUnary(Unary& expr) {
    auto value = evaluate(expr.right_.get());

    switch (expr.operator_.type_) {
        case TokenType::BANG:
            if (value.type() == typeid(bool))
                return !std::any_cast<bool>(value);
            else
                return false;
        case TokenType::MINUS:
            return -std::any_cast<double>(value);
    }

    return nullptr; // Unreachable
}