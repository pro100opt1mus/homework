#pragma once

#include "menu_item.h"

namespace pro100opt1mus {
    const MenuItem* show_global_menu(const MenuItem* current);

    const MenuItem* show_universities(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);

    const MenuItem* learn_spbu(const MenuItem* current);
    const MenuItem* learn_itmo(const MenuItem* current);
    const MenuItem* learn_politech(const MenuItem* current);
    const MenuItem* learn_leti(const MenuItem* current);
    const MenuItem* universities_go_back(const MenuItem* current);
    
    const MenuItem* learn_pm_pu(const MenuItem* current);
    const MenuItem* learn_matmech(const MenuItem* current);
    const MenuItem* learn_lingv(const MenuItem* current);
    const MenuItem* spbu_go_back(const MenuItem* current);
}
