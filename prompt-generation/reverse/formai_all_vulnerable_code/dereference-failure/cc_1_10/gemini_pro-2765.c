//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Item structure
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

// Warehouse structure
typedef struct Warehouse {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Function prototypes
Warehouse* create_warehouse();
void add_item(Warehouse* warehouse, Item item);
void remove_item(Warehouse* warehouse, char* name);
void print_warehouse(Warehouse* warehouse);

// Main function
int main() {
    // Create a warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {"Item 1", 10, 10.0};
    add_item(warehouse, item1);
    Item item2 = {"Item 2", 20, 20.0};
    add_item(warehouse, item2);
    Item item3 = {"Item 3", 30, 30.0};
    add_item(warehouse, item3);

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 2");

    // Print the warehouse
    print_warehouse(warehouse);

    // Free the warehouse
    free(warehouse);

    return 0;
}

// Function definitions

// Create a warehouse
Warehouse* create_warehouse() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse* warehouse, Item item) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Remove an item from the warehouse
void remove_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            // Shift the remaining items down
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->num_items--;
            return;
        }
    }
}

// Print the warehouse
void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}