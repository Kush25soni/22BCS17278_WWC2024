#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

class Item {
private:
    int itemID;
    std::string name;
    std::string category;
    int quantity;
    int reorderLevel;

public:
    // Constructor
    Item(int id, const std::string& itemName, const std::string& itemCategory, int qty, int reorder)
        : itemID(id), name(itemName), category(itemCategory), quantity(qty), reorderLevel(reorder) {}

    // Accessors
    int getItemID() const { return itemID; }
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    int getQuantity() const { return quantity; }
    int getReorderLevel() const { return reorderLevel; }

    // Mutators
    void updateQuantity(int qty) { quantity = qty; }

    // Check if reorder is needed
    bool needsReorder() const { return quantity < reorderLevel; }

    // Display item details
    void display() const {
        std::cout << "ID: " << itemID << ", Name: " << name
                  << ", Category: " << category
                  << ", Quantity: " << quantity
                  << ", Reorder Level: " << reorderLevel << std::endl;
    }
};

class InventoryManager {
private:
    std::vector<Item> inventory;

public:
    void addItem() {
        int id, qty, reorder;
        std::string name, category;

        std::cout << "Enter Item ID: ";
        std::cin >> id;
        std::cin.ignore(); // Clear buffer
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Category: ";
        std::getline(std::cin, category);
        std::cout << "Enter Quantity: ";
        std::cin >> qty;
        std::cout << "Enter Reorder Level: ";
        std::cin >> reorder;

        inventory.emplace_back(id, name, category, qty, reorder);
        std::cout << "Item added successfully!\n";
    }

    void updateStock() {
        int id, qty;
        std::cout << "Enter Item ID to update: ";
        std::cin >> id;

        auto it = std::find_if(inventory.begin(), inventory.end(), [id](const Item& item) {
            return item.getItemID() == id;
        });

        if (it != inventory.end()) {
            std::cout << "Enter new quantity: ";
            std::cin >> qty;
            it->updateQuantity(qty);
            std::cout << "Stock updated successfully!\n";
        } else {
            std::cout << "Item not found.\n";
        }
    }

    void viewInventory() const {
        std::cout << "Current Inventory:\n";
        for (const auto& item : inventory) {
            item.display();
        }
    }

    void searchByName() const {
        std::string searchName;
        std::cout << "Enter item name to search: ";
        std::cin.ignore();
        std::getline(std::cin, searchName);

        for (const auto& item : inventory) {
            if (item.getName() == searchName) {
                item.display();
            }
        }
    }

    void exportInventory() const {
        std::ofstream outFile("inventory.txt");
        if (outFile.is_open()) {
            for (const auto& item : inventory) {
                outFile << item.getItemID() << ","
                        << item.getName() << ","
                        << item.getCategory() << ","
                        << item.getQuantity() << ","
                        << item.getReorderLevel() << "\n";
            }
            outFile.close();
            std::cout << "Inventory exported to inventory.txt successfully!\n";
        } else {
            std::cerr << "Error opening file for export.\n";
        }
    }

    void checkReorderAlerts() const {
        for (const auto& item : inventory) {
            if (item.needsReorder()) {
                std::cout << "ALERT: Item '" << item.getName()
                          << "' needs to be reordered.\n";
            }
        }
    }
};

int main() {
    InventoryManager manager;
    int choice;

    do {
        std::cout << "\nWarehouse Inventory Management System\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Update Stock\n";
        std::cout << "3. View Inventory\n";
        std::cout << "4. Search Item by Name\n";
        std::cout << "5. Export Inventory\n";
        std::cout << "6. Check Reorder Alerts\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addItem();
            break;
        case 2:
            manager.updateStock();
            break;
        case 3:
            manager.viewInventory();
            break;
        case 4:
            manager.searchByName();
            break;
        case 5:
            manager.exportInventory();
            break;
        case 6:
            manager.checkReorderAlerts();
            break;
        case 7:
            std::cout << "Exiting system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
