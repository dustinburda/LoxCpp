//
// Created by Dustin on 5/31/25.
//


#include "../include/ExprVisitor.h"


std::any getLiteralValue(std::variant<std::string, double, bool> literal) {
    std::any literal_value;
    if (auto* val = std::get_if<double>(&literal)) {
        literal_value = *val;
    } else if (auto* val = std::get_if<std::string>(&literal)) {
        literal_value = *val;
    } else if (auto* val = std::get_if<bool>(&literal)) {
        literal_value = * val;
    }

    return literal_value;
}