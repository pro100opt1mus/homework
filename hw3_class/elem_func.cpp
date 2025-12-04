#include "menu_item.h"
#include "elem_func.h"
#include <iostream>
#include <cstdlib>

namespace {
    const pro100opt1mus::MenuItem* show_children(const pro100opt1mus::MenuItem* current) {
        for (int i = 1; i <current->children_count; i++) {
            std::cout << current->children[i]->title << std::endl;
        }
        std::cout << current->children[0]->title << std::endl;
        std::cout << "Выберите пункт > ";

        int user_input;
        std::cin >> user_input;
        std::cout << std::endl;
        
        return current->children[user_input];
    }
}

const pro100opt1mus::MenuItem* pro100opt1mus::show_global_menu(const MenuItem* current) {
    std::cout << "Главное меню: " << current->children_count << std::endl;
    return show_children(current);
}

const pro100opt1mus::MenuItem* pro100opt1mus::show_universities(const MenuItem* current) {
    std::cout << "Второй уровень меню" << std::endl;
    return show_children(current);
}

const pro100opt1mus::MenuItem* pro100opt1mus::exit(const MenuItem* current) {
    std::exit(0);
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_spbu(const MenuItem* current) {
    std::cout << "Третий уровень меню" << std::endl;
    return show_children(current);
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_itmo(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_politech(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_leti(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::universities_go_back(const MenuItem* current) {
    return current->parent->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_pm_pu(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_matmech(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::learn_lingv(const MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
}

const pro100opt1mus::MenuItem* pro100opt1mus::spbu_go_back(const MenuItem* current) {
    return current->parent->parent;
}
