//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_WAREHOUSE_NAME_LENGTH 50

typedef struct item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} item;

typedef struct warehouse {
    char name[MAX_WAREHOUSE_NAME_LENGTH];
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse(char *name) {
    warehouse *new_warehouse = malloc(sizeof(warehouse));
    strcpy(new_warehouse->name, name);
    new_warehouse->num_items = 0;
    return new_warehouse;
}

// Add an item to a warehouse
void add_item(warehouse *warehouse, item *item) {
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items] = *item;
        warehouse->num_items++;
    } else {
        printf("Error: Warehouse is full.\n");
    }
}

// Remove an item from a warehouse
void remove_item(warehouse *warehouse, char *name) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

// Get the total value of a warehouse
float get_total_value(warehouse *warehouse) {
    int i;
    float total_value = 0;

    for (i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price;
    }

    return total_value;
}

// Print the contents of a warehouse
void print_warehouse(warehouse *warehouse) {
    int i;

    printf("Warehouse: %s\n", warehouse->name);
    printf("Items:\n");

    for (i = 0; i < warehouse->num_items; i++) {
        printf("  %s: %d @ $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }

    printf("Total value: $%.2f\n", get_total_value(warehouse));
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *warehouse = create_warehouse("My Warehouse");

    // Add some items to the warehouse
    item item1 = {"Item 1", 10, 10.00};
    add_item(warehouse, &item1);

    item item2 = {"Item 2", 20, 20.00};
    add_item(warehouse, &item2);

    item item3 = {"Item 3", 30, 30.00};
    add_item(warehouse, &item3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 2");

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    return 0;
}