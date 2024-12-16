#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/DatabaseConnection.h"

int main()
{

    // Access the environment variable DB_CONNECTION_STRING
    const char *connInfo = std::getenv("DB_CONNECTION_STRING");

    // Instantiate the DatabaseConnection object
    DatabaseConnection db(connInfo); // This will automatically attempt to connect to the database in the constructor

    // No need for a separate connect check, since it's handled in the constructor
    std::cout << "Database connection should be successful at this point.\n";

    std::vector<std::string> menuItems = {"Coffee", "Tea", "Sandwich", "Cake"};
    std::vector<double> prices = {2.5, 1.5, 5.0, 3.0};

    int choice = -1; // Ensures the loop starts
    double total = 0.0;
    std::vector<std::string> order;

    while (choice != 0)
    {
        std::cout << "---- Cafe Menu ----\n";
        for (int i = 0; i < menuItems.size(); ++i)
        {
            std::cout << i + 1 << ". " << menuItems[i] << " - $" << prices[i] << std::endl;
        }

        std::cout << "Enter item ID to order (or 0 to finish): ";
        std::cin >> choice;

        if (choice > 0 && choice <= menuItems.size())
        {
            std::cout << menuItems[choice - 1] << " added to order.\n";
            order.push_back(menuItems[choice - 1]);
            total += prices[choice - 1];

            // Log the current order
            std::cout << "Current order: ";
            for (const auto &item : order)
            {
                std::cout << item << " ";
            }
            std::cout << std::endl;

            // Insert the order into the database
            std::string table = "orders";
            std::string columns = "item_name, price";
            std::string values = "'" + menuItems[choice - 1] + "', " + std::to_string(prices[choice - 1]);

            bool success = db.insertData(table, columns, values);
            if (!success)
            {
                std::cerr << "Failed to insert order into database.\n";
                std::cerr << "SQL Query: " << "INSERT INTO " + table + " (" + columns + ") VALUES (" + values + ")\n";
            }
        }
    }

    // Show receipt
    std::cout << "---- Receipt ----\n";
    for (const auto &item : order)
    {
        // Use std::find to find the item in the menuItems vector
        auto it = std::find(menuItems.begin(), menuItems.end(), item);
        if (it != menuItems.end())
        {
            // Calculate the index of the item
            size_t index = std::distance(menuItems.begin(), it);
            std::cout << item << " - $" << prices[index] << std::endl;
        }
    }
    std::cout << "Total: $" << total << "\n";

    return 0;
}
