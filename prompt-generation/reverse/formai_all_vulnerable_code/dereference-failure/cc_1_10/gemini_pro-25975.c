//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a warehouse item
typedef struct {
    int id;
    char *name;
    int quantity;
    float price;
} item_t;

// Define a struct to represent a warehouse
typedef struct {
    int num_items;
    item_t *items;
} warehouse_t;

// Function to create a new warehouse
warehouse_t *create_warehouse(int num_items) {
    warehouse_t *warehouse = malloc(sizeof(warehouse_t));
    warehouse->num_items = num_items;
    warehouse->items = malloc(sizeof(item_t) * num_items);
    return warehouse;
}

// Function to add an item to a warehouse
void add_item(warehouse_t *warehouse, item_t item) {
    warehouse->items[warehouse->num_items++] = item;
}

// Function to remove an item from a warehouse
void remove_item(warehouse_t *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i] = warehouse->items[--warehouse->num_items];
            break;
        }
    }
}

// Function to get the total value of a warehouse
float get_total_value(warehouse_t *warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].price * warehouse->items[i].quantity;
    }
    return total_value;
}

// Function to print the contents of a warehouse
void print_warehouse(warehouse_t *warehouse) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item ID: %d\n", warehouse->items[i].id);
        printf("Item name: %s\n", warehouse->items[i].name);
        printf("Item quantity: %d\n", warehouse->items[i].quantity);
        printf("Item price: %f\n", warehouse->items[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new warehouse with 5 items
    warehouse_t *warehouse = create_warehouse(5);

    // Add 5 items to the warehouse
    item_t item1 = {1, "Item 1", 10, 10.0};
    item_t item2 = {2, "Item 2", 20, 20.0};
    item_t item3 = {3, "Item 3", 30, 30.0};
    item_t item4 = {4, "Item 4", 40, 40.0};
    item_t item5 = {5, "Item 5", 50, 50.0};
    add_item(warehouse, item1);
    add_item(warehouse, item2);
    add_item(warehouse, item3);
    add_item(warehouse, item4);
    add_item(warehouse, item5);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Get the total value of the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the warehouse: %f\n", total_value);

    // Remove an item from the warehouse
    remove_item(warehouse, 3);

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse->items);
    free(warehouse);

    return 0;
}