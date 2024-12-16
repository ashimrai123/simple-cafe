#include "../include/CafeSystem.h"
#include <iostream>
#include <fstream>
#include <libpq-fe.h>

using namespace std;

void CafeManagementSystem::run()
{
    menu.loadMenuFromFile("data/menu.txt");
    int choice;
    do
    {
        cout << "\n1. Customer Menu\n2. Admin Menu\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            customerMenu();
            break;
        case 2:
            adminMenu();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

void CafeManagementSystem::customerMenu()
{
    Order order;
    int choice;
    do
    {
        menu.displayMenu();
        cout << "Enter item ID to order (or 0 to finish): ";
        cin >> choice;

        if (choice == 0)
            break;

        MenuItem *item = menu.findItemById(choice);
        if (item)
        {
            order.addItem(*item);
            cout << item->name << " added to order.\n";
        }
        else
        {
            cout << "Invalid item ID. Try again.\n";
        }
    } while (true);

    order.generateReceipt();
    saveSalesData(order.getTotal());
}

void CafeManagementSystem::adminMenu()
{
    cout << "Admin functionality coming soon...\n";
}

void CafeManagementSystem::saveSalesData(double amount)
{
    ofstream file("data/sales.txt", ios::app);
    if (file.is_open())
    {
        file << "Sale: $" << amount << endl;
        file.close();
    }
}
