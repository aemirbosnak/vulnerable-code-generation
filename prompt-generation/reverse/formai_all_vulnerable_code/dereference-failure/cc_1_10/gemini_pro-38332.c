//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item_t;

// Define the structure of the warehouse
typedef struct warehouse {
    item_t items[MAX_ITEMS];
    int num_items;
} warehouse_t;

// Create a new warehouse
warehouse_t* create_warehouse() {
    warehouse_t* warehouse = malloc(sizeof(warehouse_t));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(warehouse_t* warehouse, item_t item) {
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items] = item;
        warehouse->num_items++;
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse_t* warehouse, char* name) {
    int index = find_item_index(warehouse, name);
    if (index != -1) {
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i + 1];
        }
        warehouse->num_items--;
    } else {
        printf("Item not found!\n");
    }
}

// Find the index of an item in the warehouse
int find_item_index(warehouse_t* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Print the inventory of the warehouse
void print_inventory(warehouse_t* warehouse) {
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse_t* warehouse = create_warehouse();

    // Add some items to the warehouse
    item_t item1 = {"Apple", 10, 1.00};
    add_item(warehouse, item1);
    item_t item2 = {"Banana", 20, 1.50};
    add_item(warehouse, item2);
    item_t item3 = {"Orange", 30, 2.00};
    add_item(warehouse, item3);

    // Print the inventory of the warehouse
    print_inventory(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Apple");

    // Print the inventory of the warehouse
    print_inventory(warehouse);

    return 0;
}