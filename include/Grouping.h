//
// Created by Dustin on 5/25/25.
//

#ifndef LOXCPP_GROUPING_H
#define LOXCPP_GROUPING_H

#include "Expression.h"


class Grouping : public Expression {
public:
    Grouping(Expression expr);
private:
    Expression expr_;
};


#endif //LOXCPP_GROUPING_H
