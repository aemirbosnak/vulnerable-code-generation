//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[51];
    int quantity;
    float price;
} item_t;

typedef struct warehouse {
    item_t *items;
    int num_items;
    int capacity;
} warehouse_t;

warehouse_t *create_warehouse(int capacity) {
    warehouse_t *warehouse = malloc(sizeof(warehouse_t));
    warehouse->items = malloc(sizeof(item_t) * capacity);
    warehouse->num_items = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

void destroy_warehouse(warehouse_t *warehouse) {
    free(warehouse->items);
    free(warehouse);
}

int add_item(warehouse_t *warehouse, item_t item) {
    if (warehouse->num_items == warehouse->capacity) {
        return -1;
    }
    warehouse->items[warehouse->num_items++] = item;
    return 0;
}

int remove_item(warehouse_t *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return 0;
        }
    }
    return -1;
}

item_t *find_item(warehouse_t *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

void print_warehouse(warehouse_t *warehouse) {
    printf("Warehouse contains %d items:\n", warehouse->num_items);
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  %s: %d @ $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    // Create a warehouse with a capacity of 10 items.
    warehouse_t *warehouse = create_warehouse(10);

    // Add some items to the warehouse.
    item_t item1 = {"Widget", 10, 1.99};
    add_item(warehouse, item1);
    item_t item2 = {"Gadget", 5, 4.99};
    add_item(warehouse, item2);
    item_t item3 = {"Gizmo", 3, 2.99};
    add_item(warehouse, item3);

    // Print the warehouse contents.
    print_warehouse(warehouse);

    // Remove an item from the warehouse.
    remove_item(warehouse, "Gadget");

    // Print the warehouse contents again.
    print_warehouse(warehouse);

    // Find an item in the warehouse.
    item_t *item = find_item(warehouse, "Gizmo");
    if (item) {
        printf("Found item: %s\n", item->name);
    } else {
        printf("Item not found.\n");
    }

    // Destroy the warehouse.
    destroy_warehouse(warehouse);

    return 0;
}