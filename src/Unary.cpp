//
// Created by Dustin on 5/25/25.
//

#include "../include/Unary.h"

Unary::Unary(std::shared_ptr<Expression> right, Token _operator)
    : right_{right}, operator_{_operator} {}