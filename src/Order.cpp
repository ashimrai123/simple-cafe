#include "../include/Order.h"
#include <iostream>
using namespace std;

Order::Order() : total(0.0) {}

void Order::addItem(const MenuItem &item)
{
    orderedItems.push_back(item);
    total += item.price;
}

void Order::generateReceipt() const
{
    cout << "---- Receipt ----\n";
    for (const auto &item : orderedItems)
    {
        cout << item.name << " - $" << item.price << endl;
    }
    cout << "Total: $" << total << endl;
}

double Order::getTotal() const
{
    return total;
}
