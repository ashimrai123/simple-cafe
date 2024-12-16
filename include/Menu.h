#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>

class Menu
{
    std::vector<MenuItem> items;

public:
    void loadMenuFromFile(const std::string &filename);
    void displayMenu() const;
    MenuItem *findItemById(int id);
};

#endif
