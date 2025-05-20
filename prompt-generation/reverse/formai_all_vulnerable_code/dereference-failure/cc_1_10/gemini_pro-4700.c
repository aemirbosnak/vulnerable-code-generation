//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the warehouse
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Structure to represent the warehouse
typedef struct Warehouse {
    Item *items;
    int num_items;
    int capacity;
} Warehouse;

// Function to create a new item
Item *create_item(char *name, int quantity, float price) {
    Item *item = malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
    return item;
}

// Function to create a new warehouse
Warehouse *create_warehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = malloc(sizeof(Item) * capacity);
    warehouse->num_items = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    if (warehouse->num_items == warehouse->capacity) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->num_items++] = *item;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return;
        }
    }
    printf("Item not found in warehouse.\n");
}

// Function to get the total value of the warehouse
float get_total_value(Warehouse *warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return total_value;
}

// Function to print the contents of the warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    // Create a warehouse with a capacity of 10 items
    Warehouse *warehouse = create_warehouse(10);

    // Add some items to the warehouse
    Item *item1 = create_item("Apple", 10, 1.0);
    add_item(warehouse, item1);
    Item *item2 = create_item("Banana", 20, 1.5);
    add_item(warehouse, item2);
    Item *item3 = create_item("Orange", 30, 2.0);
    add_item(warehouse, item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Calculate the total value of the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(warehouse, "Banana");

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse and its items
    free(warehouse->items);
    free(warehouse);
}