//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
    int id;               // Item ID
    char name[256];       // Item name
    int quantity;         // Item quantity
    double price;         // Item price
} Item;

// Warehouse structure
typedef struct Warehouse {
    Item *items;          // Array of items
    int num_items;        // Number of items in the warehouse
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items] = *item;
    warehouse->num_items++;
}

// Find an item by ID
Item *find_item_by_id(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            warehouse->items = realloc(warehouse->items, warehouse->num_items * sizeof(Item));
            return;
        }
    }
}

// Print the warehouse inventory
void print_inventory(Warehouse *warehouse) {
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%d %s %d %.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {1, "Apple", 10, 1.0};
    Item item2 = {2, "Orange", 5, 1.5};
    Item item3 = {3, "Banana", 15, 2.0};
    add_item(warehouse, &item1);
    add_item(warehouse, &item2);
    add_item(warehouse, &item3);

    // Print the warehouse inventory
    print_inventory(warehouse);

    // Find an item by ID
    Item *item = find_item_by_id(warehouse, 2);
    if (item != NULL) {
        printf("Found item: %d %s %d %.2f\n", item->id, item->name, item->quantity, item->price);
    } else {
        printf("Item not found!\n");
    }

    // Remove an item from the warehouse
    remove_item(warehouse, 3);

    // Print the warehouse inventory
    print_inventory(warehouse);

    // Free the warehouse
    free(warehouse->items);
    free(warehouse);

    return 0;
}