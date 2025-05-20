//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

// Define the structure of the warehouse
typedef struct {
    Item *items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items] = item;
        warehouse->num_items++;
    } else {
        printf("Error: Warehouse is full.\n");
    }
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i]->name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

// Get the total value of the warehouse
float get_total_value(Warehouse *warehouse) {
    float total_value = 0.0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i]->quantity * warehouse->items[i]->price;
    }
    return total_value;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse Contents:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %.2f\n", warehouse->items[i]->name, warehouse->items[i]->quantity, warehouse->items[i]->price);
    }
}

// Free the memory allocated for the warehouse
void free_warehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i]);
    }
    free(warehouse);
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item *item1 = malloc(sizeof(Item));
    item1->name = "Apple";
    item1->quantity = 10;
    item1->price = 1.0;
    add_item(warehouse, item1);

    Item *item2 = malloc(sizeof(Item));
    item2->name = "Orange";
    item2->quantity = 5;
    item2->price = 2.0;
    add_item(warehouse, item2);

    Item *item3 = malloc(sizeof(Item));
    item3->name = "Banana";
    item3->quantity = 15;
    item3->price = 1.5;
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    printf("Initial warehouse:\n");
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Orange");

    // Print the contents of the warehouse
    printf("Warehouse after removing 'Orange':\n");
    print_warehouse(warehouse);

    // Get the total value of the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Free the memory allocated for the warehouse
    free_warehouse(warehouse);

    return 0;
}