//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct {
    int id;             // The ID of the item
    char name[50];      // The name of the item
    int quantity;       // The quantity of the item in stock
    float price;        // The price of the item
} item_t;

// Define the structure of the warehouse
typedef struct {
    item_t items[MAX_ITEMS];  // The array of items in the warehouse
    int num_items;            // The number of items in the warehouse
} warehouse_t;

// Create a new warehouse
warehouse_t *create_warehouse() {
    warehouse_t *warehouse = malloc(sizeof(warehouse_t));
    if (warehouse == NULL) {
        return NULL;
    }

    warehouse->num_items = 0;

    return warehouse;
}

// Add an item to the warehouse
int add_item(warehouse_t *warehouse, item_t item) {
    if (warehouse->num_items >= MAX_ITEMS) {
        return -1;  // The warehouse is full
    }

    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;

    return 0;
}

// Remove an item from the warehouse
int remove_item(warehouse_t *warehouse, int id) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            break;
        }
    }

    if (i == warehouse->num_items) {
        return -1;  // The item was not found
    }

    warehouse->num_items--;
    for (; i < warehouse->num_items; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }

    return 0;
}

// Find an item in the warehouse
int find_item(warehouse_t *warehouse, int id) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            return i;
        }
    }

    return -1;  // The item was not found
}

// Print the contents of the warehouse
void print_warehouse(warehouse_t *warehouse) {
    int i;

    printf("Warehouse:\n");
    for (i = 0; i < warehouse->num_items; i++) {
        printf("  %d: %s (%d, $%.2f)\n",
            warehouse->items[i].id,
            warehouse->items[i].name,
            warehouse->items[i].quantity,
            warehouse->items[i].price);
    }
}

// Free the memory allocated for the warehouse
void free_warehouse(warehouse_t *warehouse) {
    free(warehouse);
}

// Main function
int main() {
    warehouse_t *warehouse = create_warehouse();

    // Add some items to the warehouse
    item_t item1 = {
        .id = 1,
        .name = "Item 1",
        .quantity = 10,
        .price = 10.0
    };
    add_item(warehouse, item1);

    item_t item2 = {
        .id = 2,
        .name = "Item 2",
        .quantity = 20,
        .price = 20.0
    };
    add_item(warehouse, item2);

    item_t item3 = {
        .id = 3,
        .name = "Item 3",
        .quantity = 30,
        .price = 30.0
    };
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the contents of the warehouse again
    printf("\n");
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free_warehouse(warehouse);

    return 0;
}