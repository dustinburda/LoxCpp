//
// Created by Dustin on 5/25/25.
//

#ifndef LOXCPP_LITERAL_H
#define LOXCPP_LITERAL_H

#include "Expression.h"

#include <string>
#include <variant>

class Literal : public Expression {
public:
    ~Literal() override {}
    Literal(std::variant<std::string, int, double> literal);
    std::any accept(ExprVisitor<std::any>& visitor) override;

    std::variant<std::string, int, double> literal_;
};


#endif //LOXCPP_LITERAL_H
