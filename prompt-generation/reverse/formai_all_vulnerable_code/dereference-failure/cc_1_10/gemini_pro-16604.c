//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct item {
    int id;
    char *name;
    int quantity;
    float price;
} Item;

typedef struct warehouse {
    Item *items;
    int num_items;
} Warehouse;

// Function prototypes
Warehouse *create_warehouse();
void add_item(Warehouse *warehouse, Item *item);
void remove_item(Warehouse *warehouse, int id);
Item *find_item(Warehouse *warehouse, int id);
void print_warehouse(Warehouse *warehouse);

// Main function
int main() {
    // Create a warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some items to the warehouse
    Item item1 = {1, "Item 1", 10, 10.0};
    add_item(warehouse, &item1);
    Item item2 = {2, "Item 2", 20, 20.0};
    add_item(warehouse, &item2);
    Item item3 = {3, "Item 3", 30, 30.0};
    add_item(warehouse, &item3);

    // Print the warehouse
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the warehouse again
    print_warehouse(warehouse);

    // Find an item in the warehouse
    Item *item = find_item(warehouse, 1);
    if (item != NULL) {
        printf("Found item: %s\n", item->name);
    } else {
        printf("Item not found.\n");
    }

    // Free the warehouse memory
    free(warehouse->items);
    free(warehouse);

    return 0;
}

// Function definitions
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

void add_item(Warehouse *warehouse, Item *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items] = *item;
    warehouse->num_items++;
}

void remove_item(Warehouse *warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            break;
        }
    }
    if (i < warehouse->num_items) {
        for (i; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i + 1];
        }
        warehouse->num_items--;
        warehouse->items = realloc(warehouse->items, warehouse->num_items * sizeof(Item));
    }
}

Item *find_item(Warehouse *warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

void print_warehouse(Warehouse *warehouse) {
    int i;
    printf("Warehouse:\n");
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%d %s %d %.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}