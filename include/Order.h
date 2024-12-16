#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <vector>

class Order
{
    std::vector<MenuItem> orderedItems;
    double total;

public:
    Order();
    void addItem(const MenuItem &item);
    void generateReceipt() const;
    double getTotal() const;
};

#endif
