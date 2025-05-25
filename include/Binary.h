//
// Created by Dustin on 5/24/25.
//

#ifndef LOXCPP_BINARY_H
#define LOXCPP_BINARY_H

#include <memory>

#include "Expression.h"
#include "Token.h"

class Binary : public Expression{
public:
    Binary(std::shared_ptr<Expression> left, Token _operator, std::shared_ptr<Expression> right);

private:
    std::shared_ptr<Expression> left_;
    std::shared_ptr<Expression> right_;
    Token operator_;
};


#endif //LOXCPP_BINARY_H
