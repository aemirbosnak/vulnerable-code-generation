//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    double price;
} item_t;

typedef struct {
    char *name;
    int size;
    item_t *items;
} warehouse_t;

void add_item(warehouse_t *warehouse, item_t *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->size + 1) * sizeof(item_t));
    warehouse->items[warehouse->size++] = *item;
}

void remove_item(warehouse_t *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->size; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->size--;
            memmove(&warehouse->items[i], &warehouse->items[i+1], (warehouse->size - i) * sizeof(item_t));
            return;
        }
    }
}

void print_warehouse(warehouse_t *warehouse) {
    int i;
    printf("Warehouse: %s\n", warehouse->name);
    printf("  Size: %d\n", warehouse->size);
    printf("  Items:\n");
    for (i = 0; i < warehouse->size; i++) {
        printf("    %s: %d @ $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    warehouse_t warehouse = { "My Warehouse", 0, NULL };

    item_t item1 = { "Item 1", 10, 10.00 };
    item_t item2 = { "Item 2", 20, 20.00 };
    item_t item3 = { "Item 3", 30, 30.00 };

    add_item(&warehouse, &item1);
    add_item(&warehouse, &item2);
    add_item(&warehouse, &item3);

    print_warehouse(&warehouse);

    remove_item(&warehouse, "Item 2");

    print_warehouse(&warehouse);

    return 0;
}