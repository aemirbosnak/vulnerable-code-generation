//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a warehouse item.
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Structure to represent the warehouse.
struct Warehouse {
    struct Item items[100];
    int num_items;
};

// Function to create a new warehouse.
struct Warehouse* create_warehouse() {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    if (warehouse == NULL) {
        printf("Error: Could not allocate memory for warehouse.\n");
        return NULL;
    }
    warehouse->num_items = 0;
    return warehouse;
}

// Function to add an item to the warehouse.
void add_item(struct Warehouse* warehouse, struct Item item) {
    if (warehouse->num_items >= 100) {
        printf("Error: Warehouse is full.\n");
        return;
    }
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Function to remove an item from the warehouse.
void remove_item(struct Warehouse* warehouse, char* name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            break;
        }
    }
    if (i == warehouse->num_items) {
        printf("Error: Item not found.\n");
        return;
    }
    for (; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->num_items--;
}

// Function to print the warehouse inventory.
void print_inventory(struct Warehouse* warehouse) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Main function.
int main() {
    // Create a new warehouse.
    struct Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse.
    struct Item item1 = {"Apple", 10, 1.0};
    add_item(warehouse, item1);
    struct Item item2 = {"Banana", 20, 2.0};
    add_item(warehouse, item2);
    struct Item item3 = {"Orange", 30, 3.0};
    add_item(warehouse, item3);

    // Print the warehouse inventory.
    printf("Warehouse inventory:\n");
    print_inventory(warehouse);

    // Remove an item from the warehouse.
    remove_item(warehouse, "Banana");

    // Print the warehouse inventory again.
    printf("\nWarehouse inventory after removing banana:\n");
    print_inventory(warehouse);

    // Free the memory allocated for the warehouse.
    free(warehouse);

    return 0;
}