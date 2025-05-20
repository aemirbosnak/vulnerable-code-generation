//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
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
    warehouse_t* warehouse = (warehouse_t*)malloc(sizeof(warehouse_t));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(warehouse_t* warehouse, item_t item) {
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items] = item;
        warehouse->num_items++;
    } else {
        printf("Error: Warehouse is full.\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse_t* warehouse, char* name) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i + 1];
        }
        warehouse->num_items--;
    } else {
        printf("Error: Item not found.\n");
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse_t* warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return total_value;
}

// Print the contents of the warehouse
void print_warehouse(warehouse_t* warehouse) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s (%d, $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("Total value: $%.2f\n", get_total_value(warehouse));
}

// Main function
int main() {
    // Create a new warehouse
    warehouse_t* warehouse = create_warehouse();

    // Add some items to the warehouse
    item_t item1 = {"Apples", 10, 1.50};
    add_item(warehouse, item1);
    item_t item2 = {"Oranges", 20, 2.00};
    add_item(warehouse, item2);
    item_t item3 = {"Bananas", 30, 2.50};
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Apples");

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}