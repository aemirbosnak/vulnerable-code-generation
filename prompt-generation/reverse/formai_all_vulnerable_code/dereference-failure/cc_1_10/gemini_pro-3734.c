//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the structure of the warehouse
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Create a new warehouse
Warehouse* create_warehouse() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
    // Check if the warehouse is full
    if (warehouse->num_items == MAX_ITEMS) {
        printf("The warehouse is full!\n");
        return;
    }

    // Add the item to the warehouse
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Find an item in the warehouse
Item* find_item(Warehouse* warehouse, char* name) {
    // Iterate over the items in the warehouse
    for (int i = 0; i < warehouse->num_items; i++) {
        // Check if the item's name matches the given name
        if (strcmp(warehouse->items[i].name, name) == 0) {
            // Return the item
            return &warehouse->items[i];
        }
    }

    // The item was not found
    return NULL;
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    // Find the item in the warehouse
    Item* item = find_item(warehouse, name);

    // Check if the item was found
    if (item == NULL) {
        printf("The item was not found!\n");
        return;
    }

    // Remove the item from the warehouse
    for (int i = 0; i < warehouse->num_items; i++) {
        if (&warehouse->items[i] == item) {
            // Move the remaining items down one index
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }

            // Decrement the number of items in the warehouse
            warehouse->num_items--;

            // Return
            return;
        }
    }
}

// Print the warehouse
void print_warehouse(Warehouse* warehouse) {
    // Iterate over the items in the warehouse
    for (int i = 0; i < warehouse->num_items; i++) {
        // Print the item's name, quantity, and price
        printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Apple", 10, 1.0};
    add_item(warehouse, item1);
    Item item2 = {"Orange", 5, 1.5};
    add_item(warehouse, item2);
    Item item3 = {"Banana", 15, 2.0};
    add_item(warehouse, item3);

    // Find an item in the warehouse
    Item* item = find_item(warehouse, "Orange");

    // Check if the item was found
    if (item != NULL) {
        // Print the item's name, quantity, and price
        printf("Found item: %s %d %.2f\n", item->name, item->quantity, item->price);
    } else {
        printf("Item not found!\n");
    }

    // Remove an item from the warehouse
    remove_item(warehouse, "Banana");

    // Print the warehouse
    print_warehouse(warehouse);

    // Free the warehouse
    free(warehouse);

    return 0;
}