#ifndef EXPRESSION_CALCULATIONS_HPP
#define EXPRESSION_CALCULATIONS_HPP

#include <string>

int precedence(char op);
double applyOp(double a, double b, char op);
double evaluateExpression(const std::string& expr);

#endif

