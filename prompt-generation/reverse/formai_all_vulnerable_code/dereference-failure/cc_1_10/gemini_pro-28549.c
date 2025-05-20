//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

typedef struct {
    int id;
    char *name;
    Item *items;
    int num_items;
} Warehouse;

Warehouse *create_warehouse(char *name) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->id = rand();
    warehouse->name = strdup(name);
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

void add_item_to_warehouse(Warehouse *warehouse, Item *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items] = *item;
    warehouse->num_items++;
}

void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("ID: %d\n", warehouse->id);
    printf("Items:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  - %s: %d @ $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    srand(time(NULL));

    Warehouse *warehouse = create_warehouse("My Warehouse");

    Item item1 = {"Item 1", 10, 10.0};
    Item item2 = {"Item 2", 20, 20.0};
    Item item3 = {"Item 3", 30, 30.0};

    add_item_to_warehouse(warehouse, &item1);
    add_item_to_warehouse(warehouse, &item2);
    add_item_to_warehouse(warehouse, &item3);

    print_warehouse(warehouse);

    return 0;
}