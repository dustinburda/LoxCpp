//
// Created by Dustin on 5/26/25.
//

#include "../include/Binary.h"
#include "../include/Grouping.h"
#include "../include/Literal.h"
#include "../include/Unary.h"
#include "../include/ExprPrinter.h"

std::string ExprPrinter::parenthesize(std::string lexeme, std::initializer_list<std::shared_ptr<Expression>> exprs) {
     std::string s;
     s += "(";
     s += lexeme;

     for (auto expr_ptr : exprs) {
         s += " ";
         s += std::any_cast<std::string>(expr_ptr->accept( *dynamic_cast<ExprVisitor<std::any>*>(this) ));
     }

     s += ")";

     return s;
}

std::string ExprPrinter::print(Expression* expr) {
    return std::any_cast<std::string>(expr->accept( *dynamic_cast<ExprVisitor<std::any>*>(this) ));
}

std::any ExprPrinter::visitBinary(Binary& expr) {
    return parenthesize(expr.operator_.lexeme_, {expr.left_, expr.right_});
}

std::any ExprPrinter::visitGrouping(Grouping& expr) {
    return parenthesize("grouping", {expr.expr_});
}

std::any ExprPrinter::visitLiteral(Literal& expr) {
    auto variant = expr.literal_;

    std::string print_val;
    if (auto* val = std::get_if<int>(&variant)) {
        print_val = std::to_string(*val);
    } else if (auto* val = std::get_if<double>(&variant)) {
        print_val = std::to_string(*val);
    } else if (auto* val = std::get_if<std::string>(&variant)) {
        print_val = *val;
    }

    return print_val;
}

std::any ExprPrinter::visitUnary(Unary& expr) {
    return parenthesize(expr.operator_.lexeme_, {expr.right_});
}