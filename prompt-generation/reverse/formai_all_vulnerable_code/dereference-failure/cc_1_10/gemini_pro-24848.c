//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse.
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse.
typedef struct {
    char name[50];  // The name of the item.
    int quantity;   // The quantity of the item in stock.
    float price;    // The price of the item.
} Item;

// Define the structure of the warehouse.
typedef struct {
    Item items[MAX_ITEMS];  // The array of items in the warehouse.
    int num_items;          // The number of items in the warehouse.
} Warehouse;

// Create a new warehouse.
Warehouse* create_warehouse() {
    Warehouse* warehouse = (Warehouse*) malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse.
void add_item(Warehouse* warehouse, Item item) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Remove an item from the warehouse.
void remove_item(Warehouse* warehouse, char* name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            break;
        }
    }

    if (i < warehouse->num_items) {
        for (int j = i; j < warehouse->num_items - 1; j++) {
            warehouse->items[j] = warehouse->items[j + 1];
        }
        warehouse->num_items--;
    }
}

// Get the quantity of an item in the warehouse.
int get_quantity(Warehouse* warehouse, char* name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return warehouse->items[i].quantity;
        }
    }

    return 0;
}

// Set the quantity of an item in the warehouse.
void set_quantity(Warehouse* warehouse, char* name, int quantity) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            return;
        }
    }

    // If the item is not found, add it to the warehouse with the specified quantity.
    Item item = { .name = name, .quantity = quantity, .price = 0 };
    add_item(warehouse, item);
}

// Get the price of an item in the warehouse.
float get_price(Warehouse* warehouse, char* name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return warehouse->items[i].price;
        }
    }

    return 0;
}

// Set the price of an item in the warehouse.
void set_price(Warehouse* warehouse, char* name, float price) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].price = price;
            return;
        }
    }

    // If the item is not found, add it to the warehouse with the specified price.
    Item item = { .name = name, .quantity = 0, .price = price };
    add_item(warehouse, item);
}

// Print the inventory of the warehouse.
void print_inventory(Warehouse* warehouse) {
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  %s: %d units, $%.2f each\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function.
int main() {
    // Create a new warehouse.
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse.
    Item item1 = { .name = "Apple", .quantity = 10, .price = 1.0 };
    add_item(warehouse, item1);
    Item item2 = { .name = "Orange", .quantity = 5, .price = 2.0 };
    add_item(warehouse, item2);

    // Print the inventory of the warehouse.
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  %s: %d units, $%.2f each\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }

    // Get the quantity of an item in the warehouse.
    int quantity = get_quantity(warehouse, "Apple");
    printf("Quantity of Apples: %d\n", quantity);

    // Set the quantity of an item in the warehouse.
    set_quantity(warehouse, "Apple", 15);

    // Get the price of an item in the warehouse.
    float price = get_price(warehouse, "Orange");
    printf("Price of Oranges: $%.2f\n", price);

    // Set the price of an item in the warehouse.
    set_price(warehouse, "Orange", 2.5);

    // Print the updated inventory of the warehouse.
    printf("Updated Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  %s: %d units, $%.2f each\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }

    // Free the memory allocated for the warehouse.
    free(warehouse);

    return 0;
}