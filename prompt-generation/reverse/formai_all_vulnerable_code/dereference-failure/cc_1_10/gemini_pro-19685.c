//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
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
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full\n");
        return;
    }

    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    int index = -1;

    // Find the index of the item in the warehouse
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the item was not found, print an error message
    if (index == -1) {
        printf("Error: Item not found\n");
        return;
    }

    // Remove the item from the warehouse
    for (int i = index; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }

    warehouse->num_items--;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse Contents:\n");

    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item: %s\n", warehouse->items[i].name);
        printf("Quantity: %d\n", warehouse->items[i].quantity);
        printf("Price: %.2f\n", warehouse->items[i].price);
        printf("\n");
    }
}

// Free the memory allocated for the warehouse
void destroy_warehouse(Warehouse* warehouse) {
    free(warehouse);
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Apple", 10, 1.0};
    add_item(warehouse, item1);

    Item item2 = {"Banana", 20, 2.0};
    add_item(warehouse, item2);

    Item item3 = {"Orange", 30, 3.0};
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Banana");

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    destroy_warehouse(warehouse);

    return 0;
}