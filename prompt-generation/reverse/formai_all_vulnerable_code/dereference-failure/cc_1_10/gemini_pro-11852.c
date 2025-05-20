//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse structure
typedef struct {
    char *name;
    int quantity;
    float price;
} item_t;

// Define the warehouse management system structure
typedef struct {
    item_t *items;
    int num_items;
} warehouse_t;

// Create a new warehouse
warehouse_t *create_warehouse() {
    warehouse_t *warehouse = malloc(sizeof(warehouse_t));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

// Destroy a warehouse
void destroy_warehouse(warehouse_t *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i].name);
    }
    free(warehouse->items);
    free(warehouse);
}

// Add an item to a warehouse
void add_item(warehouse_t *warehouse, char *name, int quantity, float price) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(item_t));
    warehouse->items[warehouse->num_items].name = strdup(name);
    warehouse->items[warehouse->num_items].quantity = quantity;
    warehouse->items[warehouse->num_items].price = price;
    warehouse->num_items++;
}

// Remove an item from a warehouse
void remove_item(warehouse_t *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            free(warehouse->items[i].name);
            for (int j = i + 1; j < warehouse->num_items; j++) {
                warehouse->items[j - 1] = warehouse->items[j];
            }
            warehouse->num_items--;
            return;
        }
    }
}

// Get the quantity of an item in a warehouse
int get_quantity(warehouse_t *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return warehouse->items[i].quantity;
        }
    }
    return 0;
}

// Get the price of an item in a warehouse
float get_price(warehouse_t *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return warehouse->items[i].price;
        }
    }
    return 0.0;
}

// Print the contents of a warehouse
void print_warehouse(warehouse_t *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse_t *warehouse = create_warehouse();

    // Add some items to the warehouse
    add_item(warehouse, "Item 1", 10, 10.0);
    add_item(warehouse, "Item 2", 20, 20.0);
    add_item(warehouse, "Item 3", 30, 30.0);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 2");

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    // Destroy the warehouse
    destroy_warehouse(warehouse);

    return 0;
}