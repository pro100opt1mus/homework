#include <iostream>
#include "expression_calculations.hpp"

int main() {
    std::string expression;
    std::cout << "Введите выражение: ";
    std::getline(std::cin, expression);
    
    try {
        double result = evaluateExpression(expression);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}


