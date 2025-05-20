//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the maximum weight of an item
#define MAX_WEIGHT 100

// Define the structure of an item
typedef struct {
    char name[MAX_NAME_LENGTH];
    int weight;
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
        printf("Error: Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

// Get the total weight of the items in the warehouse
int get_total_weight(Warehouse* warehouse) {
    int total_weight = 0;
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        total_weight += warehouse->items[i].weight;
    }
    return total_weight;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        printf("Item %d: %s (%d kg)\n", i + 1, warehouse->items[i].name, warehouse->items[i].weight);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Item 1", 10};
    add_item(warehouse, item1);
    Item item2 = {"Item 2", 20};
    add_item(warehouse, item2);
    Item item3 = {"Item 3", 30};
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    printf("Warehouse contents:\n");
    print_warehouse(warehouse);

    // Get the total weight of the items in the warehouse
    int total_weight = get_total_weight(warehouse);
    printf("Total weight: %d kg\n", total_weight);

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 2");

    // Print the contents of the warehouse
    printf("Warehouse contents after removing 'Item 2':\n");
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}