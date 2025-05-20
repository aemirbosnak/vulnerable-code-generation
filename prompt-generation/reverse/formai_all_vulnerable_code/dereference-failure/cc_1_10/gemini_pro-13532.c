//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
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
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

// Find an item in the warehouse
Item* find_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
    printf("The warehouse contains the following items:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s (%d, $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Get the total value of the items in the warehouse
float get_total_value(Warehouse* warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return total_value;
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

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Get the total value of the items in the warehouse
    float total_value = get_total_value(warehouse);
    printf("The total value of the items in the warehouse is $%.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(warehouse, "Orange");

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}