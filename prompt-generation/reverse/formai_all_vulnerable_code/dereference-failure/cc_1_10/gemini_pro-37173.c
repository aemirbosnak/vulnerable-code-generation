//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a warehouse item
typedef struct {
    int id;
    char *name;
    int quantity;
    float price;
} Item;

// Define the structure of a warehouse
typedef struct {
    Item *items;
    int num_items;
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

// Destroy a warehouse
void destroy_warehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i].name);
    }
    free(warehouse->items);
    free(warehouse);
}

// Add an item to a warehouse
void add_item(Warehouse *warehouse, Item item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Remove an item from a warehouse
void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->num_items--;
            break;
        }
    }
}

// Get an item from a warehouse
Item *get_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

// Print the contents of a warehouse
void print_warehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item %d: %s, quantity: %d, price: %.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {1, "Item 1", 10, 10.00};
    add_item(warehouse, item1);
    Item item2 = {2, "Item 2", 20, 20.00};
    add_item(warehouse, item2);
    Item item3 = {3, "Item 3", 30, 30.00};
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Get an item from the warehouse
    Item *item = get_item(warehouse, 2);
    if (item != NULL) {
        printf("Item %d: %s, quantity: %d, price: %.2f\n", item->id, item->name, item->quantity, item->price);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the warehouse
    remove_item(warehouse, 1);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Destroy the warehouse
    destroy_warehouse(warehouse);

    return 0;
}