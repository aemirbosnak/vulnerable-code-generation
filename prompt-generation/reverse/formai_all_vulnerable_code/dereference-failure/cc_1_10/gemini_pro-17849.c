//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item struct
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Warehouse struct
typedef struct Warehouse {
    Item *items;
    int num_items;
} Warehouse;

// Function to create a warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

// Function to add an item to a warehouse
void add_item(Warehouse *warehouse, Item item) {
    warehouse->items = (Item *)realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Function to remove an item from a warehouse
void remove_item(Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

// Function to find an item in a warehouse
Item *find_item(Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

// Function to print a warehouse
void print_warehouse(Warehouse *warehouse) {
    int i;
    printf("Items in warehouse:\n");
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s (%d, $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Food", 10, 5.00};
    Item item2 = {"Water", 20, 2.50};
    Item item3 = {"Medicine", 5, 10.00};
    add_item(warehouse, item1);
    add_item(warehouse, item2);
    add_item(warehouse, item3);

    // Print the warehouse
    print_warehouse(warehouse);

    // Find an item in the warehouse
    Item *found_item = find_item(warehouse, "Medicine");
    if (found_item != NULL) {
        printf("Found item: %s (%d, $%.2f)\n", found_item->name, found_item->quantity, found_item->price);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the warehouse
    remove_item(warehouse, "Water");

    // Print the warehouse
    print_warehouse(warehouse);

    // Free the warehouse
    free(warehouse->items);
    free(warehouse);

    return 0;
}