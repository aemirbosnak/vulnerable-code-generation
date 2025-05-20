//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

typedef struct {
    Item *items;
    int num_items;
    int capacity;
} Warehouse;

Warehouse *create_warehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = malloc(sizeof(Item) * capacity);
    warehouse->num_items = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

void add_item(Warehouse *warehouse, char *name, int quantity, float price) {
    if (warehouse->num_items >= warehouse->capacity) {
        warehouse->capacity *= 2;
        warehouse->items = realloc(warehouse->items, sizeof(Item) * warehouse->capacity);
    }
    warehouse->items[warehouse->num_items].name = strdup(name);
    warehouse->items[warehouse->num_items].quantity = quantity;
    warehouse->items[warehouse->num_items].price = price;
    warehouse->num_items++;
}

void remove_item(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            free(warehouse->items[i].name);
            for (int j = i + 1; j < warehouse->num_items; j++) {
                warehouse->items[j - 1] = warehouse->items[j];
            }
            warehouse->num_items--;
            return;
        }
    }
    printf("Item not found.\n");
}

void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf(" - %s (%d, $%.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    Warehouse *warehouse = create_warehouse(10);
    add_item(warehouse, "Apples", 100, 0.50);
    add_item(warehouse, "Bananas", 50, 0.75);
    add_item(warehouse, "Oranges", 25, 1.00);
    print_warehouse(warehouse);
    remove_item(warehouse, "Bananas");
    print_warehouse(warehouse);
    return 0;
}