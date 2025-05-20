//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_ITEM_NAME_LENGTH 50

// Define the structure of an item
typedef struct item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Function to create a new warehouse
warehouse* create_warehouse() {
    warehouse* new_warehouse = (warehouse*)malloc(sizeof(warehouse));
    new_warehouse->num_items = 0;
    return new_warehouse;
}

// Function to add an item to the warehouse
void add_item(warehouse* warehouse, item* item) {
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items] = *item;
        warehouse->num_items++;
    } else {
        printf("Error: Warehouse is full.\n");
    }
}

// Function to remove an item from the warehouse
void remove_item(warehouse* warehouse, char* item_name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

// Function to search for an item in the warehouse
item* search_item(warehouse* warehouse, char* item_name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

// Function to print the warehouse
void print_warehouse(warehouse* warehouse) {
    int i;
    printf("Warehouse:\n");
    for (i = 0; i < warehouse->num_items; i++) {
        printf("  %s (%d, $%.2f)\n",
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* my_warehouse = create_warehouse();

    // Add some items to the warehouse
    item item1 = {"Apple", 10, 0.50};
    item item2 = {"Orange", 15, 0.75};
    item item3 = {"Banana", 20, 1.00};
    add_item(my_warehouse, &item1);
    add_item(my_warehouse, &item2);
    add_item(my_warehouse, &item3);

    // Remove an item from the warehouse
    remove_item(my_warehouse, "Orange");

    // Search for an item in the warehouse
    item* item4 = search_item(my_warehouse, "Banana");

    // Print the warehouse
    print_warehouse(my_warehouse);

    return 0;
}