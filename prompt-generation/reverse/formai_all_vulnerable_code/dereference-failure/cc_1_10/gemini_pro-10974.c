//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the structure of the warehouse
typedef struct Warehouse {
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
        printf("The warehouse is full.\n");
    }
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

// Get the total value of the items in the warehouse
float get_total_value(Warehouse* warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].price * warehouse->items[i].quantity;
    }
    return total_value;
}

// Print the items in the warehouse
void print_items(Warehouse* warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", warehouse->items[i].name);
        printf("Quantity: %d\n", warehouse->items[i].quantity);
        printf("Price: %.2f\n", warehouse->items[i].price);
        printf("\n");
    }
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

    // Remove an item from the warehouse
    remove_item(warehouse, "Banana");

    // Get the total value of the items in the warehouse
    float total_value = get_total_value(warehouse);

    // Print the items in the warehouse
    printf("Items in the warehouse:\n");
    print_items(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}