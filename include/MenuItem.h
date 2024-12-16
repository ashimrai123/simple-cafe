#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem
{
public:
    int id;
    std::string name;
    double price;

    MenuItem(int id, const std::string &name, double price);
};

#endif
