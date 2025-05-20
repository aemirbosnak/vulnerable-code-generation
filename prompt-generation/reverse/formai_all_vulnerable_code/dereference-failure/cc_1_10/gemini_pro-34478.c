//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Warehouse structure
typedef struct Warehouse {
    char name[50];  // Warehouse name
    int capacity;  // Warehouse capacity in cubic meters
    int num_items;  // Number of items in the warehouse
    struct Item *items;  // Array of items in the warehouse
} Warehouse;

// Item structure
typedef struct Item {
    char name[50];  // Item name
    int size;  // Item size in cubic meters
    int quantity;  // Item quantity
} Item;

// Function to create a new warehouse
Warehouse *create_warehouse(char *name, int capacity) {
    Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
    strcpy(warehouse->name, name);
    warehouse->capacity = capacity;
    warehouse->num_items = 0;
    warehouse->items = NULL;
    return warehouse;
}

// Function to add an item to a warehouse
void add_item(Warehouse *warehouse, Item *item) {
    if (warehouse->num_items == 0) {
        warehouse->items = (Item *)malloc(sizeof(Item));
    } else {
        warehouse->items = (Item *)realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    }
    warehouse->items[warehouse->num_items] = *item;
    warehouse->num_items++;
}

// Function to remove an item from a warehouse
void remove_item(Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            break;
        }
    }
    if (i == warehouse->num_items) {
        printf("Item not found!\n");
        return;
    }
    for (i = i + 1; i < warehouse->num_items; i++) {
        warehouse->items[i - 1] = warehouse->items[i];
    }
    warehouse->num_items--;
}

// Function to print the contents of a warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("Capacity: %d cubic meters\n", warehouse->capacity);
    printf("Number of items: %d\n", warehouse->num_items);
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item: %s\n", warehouse->items[i].name);
        printf("Size: %d cubic meters\n", warehouse->items[i].size);
        printf("Quantity: %d\n", warehouse->items[i].quantity);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse("Acme Warehouse", 1000);

    // Add some items to the warehouse
    Item item1 = {"TV", 50, 10};
    add_item(warehouse, &item1);
    Item item2 = {"DVD player", 20, 20};
    add_item(warehouse, &item2);
    Item item3 = {"Refrigerator", 200, 5};
    add_item(warehouse, &item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "DVD player");

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}