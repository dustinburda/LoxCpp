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
    virtual std::any visitBinary(Binary& expr) = 0;
    virtual std::any visitGrouping(Grouping& expr) = 0;
    virtual std::any visitLiteral(Literal& expr) = 0;
    virtual std::any visitUnary(Unary& expr) = 0;
};


#endif //LOXCPP_INTERPRETER_H
