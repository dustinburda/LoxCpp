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
    Literal(std::variant<std::string, int, double> literal);
private:
    std::variant<std::string, int, double> literal_;
};


#endif //LOXCPP_LITERAL_H
