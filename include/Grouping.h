//
// Created by Dustin on 5/25/25.
//

#ifndef LOXCPP_GROUPING_H
#define LOXCPP_GROUPING_H

#include <memory>

#include "Expression.h"

class Grouping : public Expression {
public:
    ~Grouping() override {}
    Grouping(std::shared_ptr<Expression> expr);
    std::any accept(ExprVisitor<std::any>& visitor) override;

    std::shared_ptr<Expression> expr_;
};


#endif //LOXCPP_GROUPING_H
