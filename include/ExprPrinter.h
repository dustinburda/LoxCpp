//
// Created by Dustin on 5/26/25.
//

#ifndef LOXCPP_EXPRPRINTER_H
#define LOXCPP_EXPRPRINTER_H

#include <string>

#include "Expression.h"
#include "ExprVisitor.h"


class ExprPrinter : public ExprVisitor<std::any> {
public:
    std::string print(Expression* expr);
private:
    std::string parenthesize(std::string lexeme, std::initializer_list<std::shared_ptr<Expression>> exprs);

    std::any visitBinary(Binary& expr) override;
    std::any visitGrouping(Grouping& expr) override;
    std::any visitLiteral(Literal& expr) override;
    std::any visitUnary(Unary& expr) override;
};


#endif //LOXCPP_EXPRPRINTER_H
