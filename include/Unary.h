//
// Created by Dustin on 5/25/25.
//

#ifndef LOXCPP_UNARY_H
#define LOXCPP_UNARY_H

#include <memory>

#include "Expression.h"
#include "Token.h"

class Unary : public Expression {
public:
    ~Unary() override {}
    Unary(std::shared_ptr<Expression> right, Token _operator);
    std::any accept(ExprVisitor<std::any>& visitor) override;

    std::shared_ptr<Expression> right_;
    Token operator_;
};


#endif //LOXCPP_UNARY_H
