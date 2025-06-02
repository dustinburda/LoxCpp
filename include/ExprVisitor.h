//
// Created by Dustin on 5/26/25.
//

#ifndef LOXCPP_EXPIRVISITOR_H
#define LOXCPP_EXPIRVISITOR_H

#include <memory>
#include <string>
#include <variant>
#include <any>

class Binary;
class Grouping;
class Literal;
class Unary;

using LiteralType = std::variant<std::string, double, bool>;

std::any getLiteralValue(LiteralType literal);

template <typename R>
class ExprVisitor {
public:
    ~ExprVisitor() = default;

    virtual R visitBinary(Binary& expr) = 0;
    virtual R visitGrouping(Grouping& expr) = 0;
    virtual R visitLiteral(Literal& expr) = 0;
    virtual R visitUnary(Unary& expr) = 0;
};

#endif //LOXCPP_EXPIRVISITOR_H
