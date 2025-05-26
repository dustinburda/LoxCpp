//
// Created by Dustin on 5/24/25.
//

#include "../include/Binary.h"

Binary::Binary(std::shared_ptr<Expression> left, Token _operator, std::shared_ptr<Expression> right)
    : left_{left}, operator_{_operator}, right_{right} {}

std::any Binary::accept(ExprVisitor<std::any>& visitor) {
    return visitor.visitBinary(*this);
}