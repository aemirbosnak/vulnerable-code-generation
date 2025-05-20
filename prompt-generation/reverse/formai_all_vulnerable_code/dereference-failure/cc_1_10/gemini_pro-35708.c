//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Warehouse structure
typedef struct Warehouse {
    char name[32];        // Warehouse name
    int capacity;         // Warehouse capacity
    int num_items;        // Number of items in the warehouse
    char items[1000][32]; // List of items in the warehouse
} Warehouse;

// Item structure
typedef struct Item {
    char name[32];        // Item name
    int quantity;         // Item quantity
    float price;          // Item price
} Item;

// Create a new warehouse
Warehouse* create_warehouse(char* name, int capacity) {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    strcpy(warehouse->name, name);
    warehouse->capacity = capacity;
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item* item) {
    if (warehouse->num_items < warehouse->capacity) {
        strcpy(warehouse->items[warehouse->num_items], item->name);
        warehouse->num_items++;
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* item_name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i], item_name) == 0) {
            warehouse->num_items--;
            memmove(warehouse->items[i], warehouse->items[i + 1], (warehouse->num_items - i) * sizeof(char*));
            break;
        }
    }
}

// Print the warehouse inventory
void print_inventory(Warehouse* warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("Capacity: %d\n", warehouse->capacity);
    printf("Number of items: %d\n", warehouse->num_items);
    printf("Items:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s\n", warehouse->items[i]);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse("Main Warehouse", 100);

    // Add some items to the warehouse
    Item item1 = {"Item 1", 10, 10.0};
    Item item2 = {"Item 2", 20, 20.0};
    Item item3 = {"Item 3", 30, 30.0};
    add_item(warehouse, &item1);
    add_item(warehouse, &item2);
    add_item(warehouse, &item3);

    // Print the warehouse inventory
    print_inventory(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 2");

    // Print the warehouse inventory
    print_inventory(warehouse);

    return 0;
}