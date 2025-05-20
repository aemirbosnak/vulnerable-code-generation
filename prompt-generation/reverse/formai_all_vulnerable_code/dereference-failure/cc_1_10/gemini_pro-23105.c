//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse structure
typedef struct Warehouse {
    char name[50];
    int num_aisles;
    int num_shelves;
    int num_bins;
    int num_items;
    struct Item **items;
} Warehouse;

// Define the item structure
typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

// Create a new warehouse
Warehouse *create_warehouse(char *name, int num_aisles, int num_shelves, int num_bins) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    strcpy(warehouse->name, name);
    warehouse->num_aisles = num_aisles;
    warehouse->num_shelves = num_shelves;
    warehouse->num_bins = num_bins;
    warehouse->num_items = 0;
    warehouse->items = NULL;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item *));
    warehouse->items[warehouse->num_items++] = item;
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, Item *item) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i]->name, item->name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            warehouse->items = realloc(warehouse->items, warehouse->num_items * sizeof(Item *));
            break;
        }
    }
}

// Print the warehouse inventory
void print_inventory(Warehouse *warehouse) {
    printf("Warehouse Inventory\n");
    printf("---------------------\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d units at $%.2f each\n", warehouse->items[i]->name, warehouse->items[i]->quantity, warehouse->items[i]->price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse("My Warehouse", 5, 10, 100);

    // Add some items to the warehouse
    Item *item1 = malloc(sizeof(Item));
    strcpy(item1->name, "Item 1");
    item1->quantity = 10;
    item1->price = 10.0;
    add_item(warehouse, item1);

    Item *item2 = malloc(sizeof(Item));
    strcpy(item2->name, "Item 2");
    item2->quantity = 20;
    item2->price = 20.0;
    add_item(warehouse, item2);

    Item *item3 = malloc(sizeof(Item));
    strcpy(item3->name, "Item 3");
    item3->quantity = 30;
    item3->price = 30.0;
    add_item(warehouse, item3);

    // Print the warehouse inventory
    print_inventory(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, item2);

    // Print the warehouse inventory again
    print_inventory(warehouse);

    return 0;
}