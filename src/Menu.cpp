#include "../include/Menu.h"
#include <fstream>
#include <iostream>
using namespace std;

void Menu::loadMenuFromFile(const string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        int id;
        string name;
        double price;
        while (file >> id >> ws && getline(file, name, ',') && file >> price)
        {
            items.emplace_back(id, name, price);
        }
        file.close();
    }
    else
    {
        cout << "Error: Could not open menu file.\n";
    }
}

void Menu::displayMenu() const
{
    cout << "---- Cafe Menu ----\n";
    for (const auto &item : items)
    {
        cout << item.id << ". " << item.name << " - $" << item.price << endl;
    }
}

MenuItem *Menu::findItemById(int id)
{
    for (auto &item : items)
    {
        if (item.id == id)
            return &item;
    }
    return nullptr;
}
