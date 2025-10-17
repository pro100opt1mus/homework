#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

// Приоритет операций: '+' и '-' имеют 1, '*' и '/' – 2.
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Применяет операцию op к операндам a и b.
double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;  // можно добавить проверку деления на ноль
    default:  return 0;
    }
}

double evaluateExpression(const string& expr) {
    stack<double> values;  // стек для чисел
    stack<char> ops;       // стек для операторов
    istringstream iss(expr);
    string token;

    while (iss >> token) {
        // Если токен – число, кладём его в стек чисел
        if (isdigit(token[0])) {
            values.push(stod(token));
        }
        else {
            // Токен – оператор
            char op = token[0];
            // Выполняем операции из стека с приоритетом не ниже op
            while (!ops.empty() && precedence(ops.top()) >= precedence(op)) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char opTop = ops.top(); ops.pop();
                values.push(applyOp(a, b, opTop));
            }
            ops.push(op);
        }
    }
    // Выполняем оставшиеся операции
    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char opTop = ops.top(); ops.pop();
        values.push(applyOp(a, b, opTop));
    }
    return values.top();
}

int main() {
    string expression;
    cout << "Введите выражение: ";
    getline(cin, expression);
    double result = evaluateExpression(expression);
    cout << "Результат: " << result << endl;
    return 0;
}

