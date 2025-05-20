//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a struct for warehouse items
struct WarehouseItem {
    char* name;
    int quantity;
    double price;
};

// Function to add a new item to the warehouse
void addItem(struct WarehouseItem* items, char* name, int quantity, double price) {
    struct WarehouseItem newItem = {name, quantity, price};
    items = (items == NULL)? &newItem : realloc(items, sizeof(struct WarehouseItem) * (items->quantity + 1));
    items->quantity++;
    items->price += price;
}

// Function to remove an item from the warehouse
void removeItem(struct WarehouseItem* items, char* name) {
    int i;
    for (i = 0; i < items->quantity; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items->quantity--;
            break;
        }
    }
}

// Function to update the price of an item in the warehouse
void updatePrice(struct WarehouseItem* items, char* name, double newPrice) {
    int i;
    for (i = 0; i < items->quantity; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items->price -= items[i].price;
            items[i].price = newPrice;
            break;
        }
    }
}

// Function to print the current state of the warehouse
void printWarehouse(struct WarehouseItem* items) {
    int i;
    for (i = 0; i < items->quantity; i++) {
        printf("%s - %d units - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    struct WarehouseItem items = {NULL, 0, 0};
    
    // Add some items to the warehouse
    addItem(&items, "Widget A", 10, 2.5);
    addItem(&items, "Widget B", 5, 3.0);
    addItem(&items, "Widget C", 20, 4.5);
    
    // Print the current state of the warehouse
    printf("Initial state:\n");
    printWarehouse(&items);
    
    // Remove an item from the warehouse
    removeItem(&items, "Widget C");
    
    // Print the updated state of the warehouse
    printf("Updated state:\n");
    printWarehouse(&items);
    
    // Update the price of an item in the warehouse
    updatePrice(&items, "Widget B", 3.5);
    
    // Print the updated state of the warehouse again
    printf("Updated state after price update:\n");
    printWarehouse(&items);
    
    return 0;
}