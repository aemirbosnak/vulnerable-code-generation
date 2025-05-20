//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
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
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items] = item;
        warehouse->num_items++;
    } else {
        printf("Error: Warehouse is full\n");
    }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return;
        }
    }
    printf("Error: Item not found\n");
}

// Get the quantity of an item in the warehouse
int get_quantity(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return warehouse->items[i].quantity;
        }
    }
    printf("Error: Item not found\n");
    return -1;
}

// Set the quantity of an item in the warehouse
void set_quantity(Warehouse* warehouse, char* name, int quantity) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            return;
        }
    }
    printf("Error: Item not found\n");
}

// Get the price of an item in the warehouse
float get_price(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return warehouse->items[i].price;
        }
    }
    printf("Error: Item not found\n");
    return -1.0;
}

// Set the price of an item in the warehouse
void set_price(Warehouse* warehouse, char* name, float price) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].price = price;
            return;
        }
    }
    printf("Error: Item not found\n");
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d units, $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Apple", 10, 0.50};
    add_item(warehouse, item1);

    Item item2 = {"Orange", 15, 0.75};
    add_item(warehouse, item2);

    Item item3 = {"Banana", 20, 1.00};
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Orange");

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Get the quantity of an item in the warehouse
    int quantity = get_quantity(warehouse, "Apple");
    printf("Quantity of Apple: %d\n", quantity);

    // Set the quantity of an item in the warehouse
    set_quantity(warehouse, "Apple", 15);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Get the price of an item in the warehouse
    float price = get_price(warehouse, "Banana");
    printf("Price of Banana: $%.2f\n", price);

    // Set the price of an item in the warehouse
    set_price(warehouse, "Banana", 1.25);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}