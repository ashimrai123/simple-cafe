#ifndef CAFESYSTEM_H
#define CAFESYSTEM_H

#include "Menu.h"
#include "Order.h"

class CafeManagementSystem
{
    Menu menu;

public:
    void run();
    void customerMenu();
    void adminMenu();
    void saveSalesData(double amount);
};

#endif
