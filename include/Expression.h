//
// Created by Dustin on 5/24/25.
//

#ifndef LOXCPP_EXPRESSION_H
#define LOXCPP_EXPRESSION_H

#include <any>

#include "ExprVisitor.h"

class Expression {
public:
    virtual ~Expression() = default;
    virtual std::any accept(ExprVisitor<std::any>& visitor) = 0;
};


#endif //LOXCPP_EXPRESSION_H

