#include <iostream>
#include <iomanip>

using namespace std;

// Простой калькулятор на C++
int main() {
    char operation;
    double num1, num2, result;
    
    cout << "=== ПРОСТОЙ КАЛЬКУЛЯТОР НА C++ ===" << endl;
    cout << "Введите первое число: ";
    cin >> num1;
    
    cout << "Введите оператор (+, -, *, /): ";
    cin >> operation;
    
    cout << "Введите второе число: ";
    cin >> num2;
    
    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
                return 1;
            }
            break;
        default:
            cout << "Ошибка: неверный оператор!" << endl;
            return 1;
    }
    
    cout << fixed << setprecision(2);
    cout << "Результат: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    return 0;
}
