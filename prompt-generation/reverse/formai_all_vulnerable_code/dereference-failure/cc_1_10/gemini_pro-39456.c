//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Warehouse structure
typedef struct Warehouse {
    Item items[100];
    int num_items;
} Warehouse;

// Function to create a new warehouse
Warehouse* create_warehouse() {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Function to add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i + 1];
        }
        warehouse->num_items--;
    }
}

// Function to print the warehouse inventory
void print_inventory(Warehouse* warehouse) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Apple", 10, 0.50};
    add_item(warehouse, item1);
    Item item2 = {"Orange", 20, 0.75};
    add_item(warehouse, item2);
    Item item3 = {"Banana", 30, 1.00};
    add_item(warehouse, item3);

    // Print the warehouse inventory
    print_inventory(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Orange");

    // Print the warehouse inventory again
    print_inventory(warehouse);

    return 0;
}