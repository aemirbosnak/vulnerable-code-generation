//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Item structure
typedef struct item {
    int id;
    char *name;
    int quantity;
    float price;
} Item;

// Warehouse structure
typedef struct warehouse {
    int num_items;
    Item *items;
} Warehouse;

// Function to create a new item
Item *create_item(int id, char *name, int quantity, float price) {
    Item *item = malloc(sizeof(Item));
    item->id = id;
    item->name = name;
    item->quantity = quantity;
    item->price = price;
    return item;
}

// Function to create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = 0;
    warehouse->items = NULL;
    return warehouse;
}

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, Item *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items++] = *item;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->num_items--;
            break;
        }
    }
}

// Function to get the total value of the warehouse
float get_total_value(Warehouse *warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total_value += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return total_value;
}

// Function to print the warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("ID: %d\n", warehouse->items[i].id);
        printf("Name: %s\n", warehouse->items[i].name);
        printf("Quantity: %d\n", warehouse->items[i].quantity);
        printf("Price: %.2f\n", warehouse->items[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item *item1 = create_item(1, "Item 1", 10, 10.0);
    add_item(warehouse, item1);

    Item *item2 = create_item(2, "Item 2", 20, 20.0);
    add_item(warehouse, item2);

    Item *item3 = create_item(3, "Item 3", 30, 30.0);
    add_item(warehouse, item3);

    // Print the warehouse
    print_warehouse(warehouse);

    // Get the total value of the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the warehouse
    print_warehouse(warehouse);

    // Free the allocated memory
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i].name);
    }
    free(warehouse->items);
    free(item1);
    free(item2);
    free(item3);
    free(warehouse);

    return 0;
}