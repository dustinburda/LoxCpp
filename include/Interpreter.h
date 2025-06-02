//
// Created by Dustin on 5/31/25.
//

#ifndef LOXCPP_INTERPRETER_H
#define LOXCPP_INTERPRETER_H


#include "ExprVisitor.h"
#include "Expression.h"

#include <any>
#include <memory>

class Interpreter : public ExprVisitor<std::any> {
public:
    std::any evaluate(Expression* expr);
private:
    bool isEqual(std::any left, std::any right);

    std::any visitBinary(Binary& expr) override;
    std::any visitGrouping(Grouping& expr) override;
    std::any visitLiteral(Literal& expr) override;
    std::any visitUnary(Unary& expr) override;
};


#endif //LOXCPP_INTERPRETER_H
