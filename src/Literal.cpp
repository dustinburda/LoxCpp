//
// Created by Dustin on 5/25/25.
//

#include "../include/Literal.h"

Literal::Literal(std::variant<std::string, int, double> literal) :
    literal_{literal} {}

std::any Literal::accept(ExprVisitor<std::any>& visitor) {
    return visitor.visitLiteral(*this);
}