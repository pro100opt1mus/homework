#include <clocale>
#include <iostream>

#include "menu_elements.h"
#include "menu_item.h"
#include "elem_func.h"

int main() {
    std::cout << "Добро пожаловать!\n";
    const pro100opt1mus::MenuItem *current = &pro100opt1mus::MAIN_LEVEL0;

    do {
        current = current->itemFunction(current);
    } while (true);
}