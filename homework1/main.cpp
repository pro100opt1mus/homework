#include <iostream>
#include "expression_calculations.hpp"

int main() {
    std::string expr;
    std::cout << "Введите выражение: ";
    std::getline(std::cin, expr);

    try {
        double result = evaluateExpression(expr);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
