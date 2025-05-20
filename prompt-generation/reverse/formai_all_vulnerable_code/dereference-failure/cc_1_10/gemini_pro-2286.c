//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char *name;
    int quantity;
    float price;
};

struct warehouse {
    struct item *items[MAX_ITEMS];
    int num_items;
};

// Create a new warehouse
struct warehouse *create_warehouse() {
    struct warehouse *warehouse = malloc(sizeof(struct warehouse));
    warehouse->num_items = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(struct warehouse *warehouse, char *name, int quantity, float price) {
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    struct item *item = malloc(sizeof(struct item));
    item->name = strdup(name);
    item->quantity = quantity;
    item->price = price;

    warehouse->items[warehouse->num_items++] = item;
}

// Remove an item from the warehouse
void remove_item(struct warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i]->name, name) == 0) {
            free(warehouse->items[i]->name);
            free(warehouse->items[i]);
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return;
        }
    }

    printf("Item not found!\n");
}

// Print the contents of the warehouse
void print_warehouse(struct warehouse *warehouse) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %f\n", warehouse->items[i]->name, warehouse->items[i]->quantity, warehouse->items[i]->price);
    }
}

// Free the warehouse
void free_warehouse(struct warehouse *warehouse) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i]->name);
        free(warehouse->items[i]);
    }

    free(warehouse);
}

int main() {
    struct warehouse *warehouse = create_warehouse();

    add_item(warehouse, "Cyberdeck", 1, 1000.00);
    add_item(warehouse, "Datachip", 10, 50.00);
    add_item(warehouse, "Neural Implant", 5, 200.00);

    print_warehouse(warehouse);

    remove_item(warehouse, "Datachip");

    printf("\n");

    print_warehouse(warehouse);

    free_warehouse(warehouse);

    return 0;
}