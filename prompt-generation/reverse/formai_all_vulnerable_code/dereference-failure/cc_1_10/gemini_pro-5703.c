//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an item in the warehouse
typedef struct Item {
    char *name;
    int quantity;
    float price;
} Item;

// Structure to represent the warehouse
typedef struct Warehouse {
    Item **items;
    int num_items;
} Warehouse;

// Function to create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    warehouse->items = (Item **)realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item *));
    warehouse->items[warehouse->num_items++] = item;
}

// Function to find an item in the warehouse
Item *find_item(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i]->name, name) == 0) {
            return warehouse->items[i];
        }
    }
    return NULL;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i]->name, name) == 0) {
            free(warehouse->items[i]);
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->num_items--;
            return;
        }
    }
}

// Function to print the inventory of the warehouse
void print_inventory(Warehouse *warehouse) {
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d, $%.2f\n", warehouse->items[i]->name, warehouse->items[i]->quantity, warehouse->items[i]->price);
    }
}

// Function to main
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item *item1 = (Item *)malloc(sizeof(Item));
    item1->name = "Magnifying glass";
    item1->quantity = 1;
    item1->price = 10.00;
    add_item(warehouse, item1);

    Item *item2 = (Item *)malloc(sizeof(Item));
    item2->name = "Pipe";
    item2->quantity = 1;
    item2->price = 5.00;
    add_item(warehouse, item2);

    Item *item3 = (Item *)malloc(sizeof(Item));
    item3->name = "Deerstalker hat";
    item3->quantity = 1;
    item3->price = 20.00;
    add_item(warehouse, item3);

    // Find an item in the warehouse
    Item *found_item = find_item(warehouse, "Magnifying glass");
    if (found_item != NULL) {
        printf("Found item: %s, %d, $%.2f\n", found_item->name, found_item->quantity, found_item->price);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the warehouse
    remove_item(warehouse, "Pipe");

    // Print the inventory of the warehouse
    print_inventory(warehouse);

    // Free the warehouse memory
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i]);
    }
    free(warehouse);

    return 0;
}