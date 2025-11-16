#include <cmath>
#include <iostream>

const double E = 1e-10;

bool equal(double a, double b);
double f1(double angle);
double f2(double angle);

int main() {
    double angle;
    std::cout << "Введите угол в радианах: ";
    std::cin >> angle;

    try {
        double res1 = f1(angle);
        std::cout << "F1(angle) = " << res1 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка в F1: " << e.what() << std::endl;
    }

    try {
        double res2 = f2(angle);
        std::cout << "F2(angle) = " << res2 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка в F2: " << e.what() << std::endl;
    }

    return 0;
}

bool equal(double a, double b) {
    return std::fabs(a - b) < E;
}
/*

*/
double f1(double angle) {
    double a2 = 2.0 * angle;
    if (equal(std::cos(a2), 1.0)) {
        throw std::invalid_argument("знаменатель равен нулю");
    }
    return (1.0 + std::sin(a2)) / (1.0 - std::cos(a2));
}

double f2(double angle) {
    double tg = std::tan(angle);
    if (equal(tg * tg, 1.0)) {
        throw std::invalid_argument("знаменатель равен нулю");
    }
    return (1.0 + tg * tg) / (1.0 - tg * tg);
}