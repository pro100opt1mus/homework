#pragma once

namespace pro100opt1mus {
    struct MenuItem {
        const char *const title;
        const MenuItem* (*itemFunction)(const MenuItem *current);
        const MenuItem *const parent;
        const MenuItem *const *children;
        const int children_count;
    };
}
