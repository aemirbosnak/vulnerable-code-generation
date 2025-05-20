//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct {
    int id;
    char *name;
    int quantity;
    float price;
} Item;

// Warehouse structure
typedef struct {
    Item **items;
    int num_items;
} Warehouse;

// Function to create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
    warehouse->items = (Item **)malloc(100 * sizeof(Item *));
    warehouse->num_items = 0;
    return warehouse;
}

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i]->id == id) {
            free(warehouse->items[i]->name);
            free(warehouse->items[i]);
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

// Function to print the warehouse inventory
void print_inventory(Warehouse *warehouse) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item ID: %d\n", warehouse->items[i]->id);
        printf("Item Name: %s\n", warehouse->items[i]->name);
        printf("Item Quantity: %d\n", warehouse->items[i]->quantity);
        printf("Item Price: %.2f\n\n", warehouse->items[i]->price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item *item1 = (Item *)malloc(sizeof(Item));
    item1->id = 1;
    item1->name = strdup("Apple");
    item1->quantity = 100;
    item1->price = 1.0;
    add_item(warehouse, item1);

    Item *item2 = (Item *)malloc(sizeof(Item));
    item2->id = 2;
    item2->name = strdup("Orange");
    item2->quantity = 200;
    item2->price = 1.5;
    add_item(warehouse, item2);

    Item *item3 = (Item *)malloc(sizeof(Item));
    item3->id = 3;
    item3->name = strdup("Banana");
    item3->quantity = 300;
    item3->price = 2.0;
    add_item(warehouse, item3);

    // Print the warehouse inventory
    print_inventory(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the warehouse inventory again
    print_inventory(warehouse);

    // Free the memory allocated for the warehouse and its items
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i]->name);
        free(warehouse->items[i]);
    }
    free(warehouse->items);
    free(warehouse);

    return 0;
}