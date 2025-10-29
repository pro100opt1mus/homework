#include <iostream>
#include <string>

const std::string DAY_NAMES[7] = {
    "Воскресенье", "Понедельник", "Вторник", "Среда",
    "Четверг", "Пятница", "Суббота"
};

int main() {
    int day, month, year;
    
    std::cout << "Введите день: ";
    std::cin >> day;
    
    std::cout << "Введите месяц: ";
    std::cin >> month;
    
    std::cout << "Введите год: ";
    std::cin >> year;

    if (month < 3) {
        month += 12;
        year--;
    }
    
    const int century = year / 100;
    const int year_in_century = year % 100;
    
    int day_of_week = (
        day + 
        (13 * month - 1) / 5 + 
        year_in_century + 
        year_in_century / 4 + 
        century / 4 - 
        2 * century
    ) % 7;
    
    if (day_of_week < 0) {
        day_of_week += 7;
    }

    std::cout << "День недели: " << DAY_NAMES[day_of_week] << std::endl;

    std::cout << "Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}