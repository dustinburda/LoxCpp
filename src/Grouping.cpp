//
// Created by Dustin on 5/25/25.
//

#include "../include/Grouping.h"

Grouping::Grouping(std::shared_ptr<Expression> expr)
    : expr_{expr} {}


std::any Grouping::accept(ExprVisitor<std::any>& visitor) {
    return visitor.visitGrouping(*this);
}