#include "menu_elements.h"

#include "elem_func.h"

namespace {
    const pro100opt1mus::MenuItem* main_children[] = { 
        &pro100opt1mus::EXIT,
        &pro100opt1mus::UNIVERSITIES_LEVEL1
    };
}

namespace pro100opt1mus {
    const MenuItem MAIN_LEVEL0 = {
        nullptr, show_global_menu, nullptr, main_children, 2
    };
}

namespace {
        const pro100opt1mus::MenuItem* universities_children[] = { 
        &pro100opt1mus::UNIVERSITIES_GO_BACK,
        &pro100opt1mus::SPBGU_LEVEL2, 
        &pro100opt1mus::ITMO_LEVEL2, 
        &pro100opt1mus::POLITECH_LEVEL2, 
        &pro100opt1mus::LETI_LEVEL2
    };

    const pro100opt1mus::MenuItem* spbu_children[] = { 
        &pro100opt1mus::SPBU_GO_BACK,
        &pro100opt1mus::PMPU_LEVEL3, 
        &pro100opt1mus::MATMECH_LEVEL3, 
        &pro100opt1mus::LINGV_LEVEL3 
    };
}

namespace pro100opt1mus {

    const MenuItem UNIVERSITIES_LEVEL1 = {
        "1 - Посмотреть университеты Санкт-Петербурга", show_universities, &MAIN_LEVEL0, universities_children, 5
    };

    const MenuItem EXIT = {
        "0 - Выйти", exit, &MAIN_LEVEL0
    };

    const MenuItem SPBGU_LEVEL2 = {
        "1 - СПбГУ", learn_spbu, &UNIVERSITIES_LEVEL1, spbu_children, 4
    };

    const MenuItem ITMO_LEVEL2 = {
        "2 -ИТМО", learn_itmo, &UNIVERSITIES_LEVEL1
    };

    const MenuItem POLITECH_LEVEL2 = {
        "3 - Политех", learn_politech, &UNIVERSITIES_LEVEL1
    };

    const MenuItem LETI_LEVEL2 = {
        "4 - ЛЭТИ", learn_leti, &UNIVERSITIES_LEVEL1
    };

    const MenuItem UNIVERSITIES_GO_BACK= {
        "0 -Выйти в предыдущее меню", universities_go_back, &UNIVERSITIES_LEVEL1
    };

    const MenuItem PMPU_LEVEL3 = {
        "1 - Факультет ПМ-ПУ", learn_pm_pu, &SPBGU_LEVEL2
    };

    const MenuItem MATMECH_LEVEL3 = {
        "2 - Факультет МатМех", learn_matmech, &SPBGU_LEVEL2
    };

    const MenuItem LINGV_LEVEL3 = {
        "3 - Лингвистический факультет", learn_lingv, &SPBGU_LEVEL2
    };

    const MenuItem SPBU_GO_BACK= {
        "0 - Выйти в предыдущее меню", spbu_go_back, &SPBGU_LEVEL2
    };
}
