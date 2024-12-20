#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class InventoryItem {
public:
    int itemID;
    std::string name;
    std::string category;
    int quantity;
    int reorderLevel;

    InventoryItem(int id, const std::string& n, const std::string& c, int q, int r)
        : itemID(id), name(n), category(c), quantity(q), reorderLevel(r) {}

    void display() const {
        std::cout << "ID: " << itemID << ", Name: " << name
                  << ", Category: " << category << ", Quantity: " << quantity
                  << ", Reorder Level: " << reorderLevel << std::endl;
    }
};

class InventoryManagementSystem {
private:
    std::vector<InventoryItem> inventory;

public:
    void addItem() {
        int id, quantity, reorderLevel;
        std::string name, category;

        std::cout << "Enter Item ID: ";
        std::cin >> id;
        std::cin.ignore(); // Clear newline from input buffer
        std::cout << "Enter Item Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Item Category: ";
        std::getline(std::cin, category);
        std::cout << "Enter Item Quantity: ";
        std::cin >> quantity;
        std::cout << "Enter Reorder Level: ";
        std::cin >> reorderLevel;

        inventory.emplace_back(id, name, category, quantity, reorderLevel);
        std::cout << "Item added successfully!\n";
    }

    void updateStock() {
        int id, quantity;
        std::cout << "Enter Item ID to update: ";
        std::cin >> id;

        for (auto& item : inventory) {
            if (item.itemID == id) {
                std::cout << "Current Quantity: " << item.quantity << std::endl;
                std::cout << "Enter new quantity: ";
                std::cin >> quantity;
                item.quantity = quantity;
                std::cout << "Stock updated successfully!\n";
                return;
            }
        }
        std::cout << "Item not found!\n";
    }

    void viewInventory() const {
        std::cout << "Current Inventory:\n";
        for (const auto& item : inventory) {
            item.display();
            if (item.quantity < item.reorderLevel) {
                std::cout << "ALERT: Stock below reorder level for " << item.name << "!\n";
            }
        }
    }

    void searchItem() const {
        std::string name;
        std::cout << "Enter Item Name to search: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        for (const auto& item : inventory) {
            if (item.name == name) {
                item.display();
                return;
            }
        }
        std::cout << "Item not found!\n";
    }

    void exportInventory() const {
        std::ofstream outFile("inventory_report.txt");
        if (outFile.is_open()) {
            for (const auto& item : inventory) {
                outFile << item.itemID << "," << item.name << "," << item.category
                        << "," << item.quantity << "," << item.reorderLevel << "\n";
            }
            outFile.close();
            std::cout << "Inventory exported to inventory_report.txt\n";
        } else {
            std::cout << "Error opening file for writing!\n";
        }
    }

    void menu() {
        int choice;
        do {
            std::cout << "\nWarehouse Inventory Management System\n";
            std::cout << "1. Add Item\n";
            std::cout << "2. Update Stock\n";
            std::cout << "3. View Inventory\n";
            std::cout << "4. Search Item\n";
            std::cout << "5. Export Inventory\n";
            std::cout << "6. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: addItem(); break;
                case 2: updateStock(); break;
                case 3: viewInventory(); break;
                case 4: searchItem(); break;
                case 5: exportInventory(); break;
                case 6: std::cout << "Exiting...\n"; break;
                default: std::cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    InventoryManagementSystem ims;
    ims.menu();
    return 0;
}


**************************************PROCEDURE*******************************************************************

Class InventoryItem:

Represents an inventory item with properties like ID, name, category, quantity, and reorder level.
Has a display method to print item details.
Class InventoryManagementSystem:

Manages the inventory using a vector of InventoryItem objects.
Key methods:
addItem: Adds a new item to the inventory.
updateStock: Updates the stock quantity of an existing item.
viewInventory: Displays all items and alerts for low stock.
searchItem: Searches for an item by name.
exportInventory: Saves inventory data to a file.
menu Method:

Displays a menu with options to:
Add Item
Update Stock
View Inventory
Search Item
Export Inventory
Exit
Executes the selected operation in a loop until "Exit" is chosen.
Main Function:

Creates an instance of InventoryManagementSystem.
Starts the application by calling the menu.
    return 0;
}
