//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct item {
    char *name;
    int quantity;
    float price;
};

struct warehouse {
    struct item *items;
    int num_items;
};

void add_item(struct warehouse *warehouse, struct item *item) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(struct item));
    warehouse->items[warehouse->num_items++] = *item;
}

void remove_item(struct warehouse *warehouse, int index) {
    for (int i = index; i < warehouse->num_items - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->num_items--;
}

void print_warehouse(struct warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    struct warehouse warehouse;
    warehouse.items = NULL;
    warehouse.num_items = 0;

    struct item item1;
    item1.name = "Item 1";
    item1.quantity = 10;
    item1.price = 10.00;

    struct item item2;
    item2.name = "Item 2";
    item2.quantity = 20;
    item2.price = 20.00;

    add_item(&warehouse, &item1);
    add_item(&warehouse, &item2);

    print_warehouse(&warehouse);

    remove_item(&warehouse, 0);

    print_warehouse(&warehouse);

    return 0;
}