//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct Item {
    int id;                // The unique identifier of the item
    char *name;            // The name of the item
    int quantity;          // The quantity of the item in the warehouse
    double price;          // The price of the item
} Item;

// Define the structure of the warehouse
typedef struct Warehouse {
    Item items[MAX_ITEMS]; // The array of items in the warehouse
    int num_items;          // The number of items in the warehouse
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item item) {
    // Check if the warehouse is full
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    // Add the item to the warehouse
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, int id) {
    // Find the item to remove
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    // Remove the item from the warehouse
    for (int i = index; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->num_items--;
}

// Print the items in the warehouse
void print_items(Warehouse *warehouse) {
    printf("Items in the warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  - %d: %s, quantity: %d, price: %.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {1, "Item 1", 10, 10.0};
    Item item2 = {2, "Item 2", 20, 20.0};
    Item item3 = {3, "Item 3", 30, 30.0};
    add_item(warehouse, item1);
    add_item(warehouse, item2);
    add_item(warehouse, item3);

    // Print the items in the warehouse
    print_items(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the items in the warehouse
    print_items(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}