#include "expression_calculations.hpp"
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <cmath>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Деление на ноль!");
            return a / b;
        case '^': return pow(a, b);
        default: throw std::runtime_error("Неизвестный оператор!");
    }
}

double evaluateExpression(const std::string& expr) {
    std::stack<double> values;
    std::stack<char> ops;
    
    std::stringstream ss(expr);
    double num;
    char op;
    
    while (ss >> num) {
        values.push(num);
        
        if (ss >> op) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(op)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char o = ops.top(); ops.pop();
                values.push(applyOp(a, b, o));
            }
            ops.push(op);
        }
    }
    
    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char o = ops.top(); ops.pop();
        values.push(applyOp(a, b, o));
    }
    
    return values.top();
}




