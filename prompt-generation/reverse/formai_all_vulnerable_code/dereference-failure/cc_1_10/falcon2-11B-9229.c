//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char* name;
    int quantity;
};

struct Warehouse {
    char* name;
    struct Item* items;
    int num_items;
};

struct Item* create_item(char* name, int quantity) {
    struct Item* item = (struct Item*)malloc(sizeof(struct Item));
    item->name = strdup(name);
    item->quantity = quantity;
    return item;
}

struct Warehouse* create_warehouse(char* name) {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    warehouse->name = strdup(name);
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

void add_item_to_warehouse(struct Warehouse* warehouse, struct Item* item) {
    warehouse->items = (struct Item*)realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(struct Item));
    warehouse->items[warehouse->num_items] = *item;
    warehouse->num_items++;
}

void print_warehouse(struct Warehouse* warehouse) {
    printf("%s\n", warehouse->name);
    printf("Items:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Name: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
    printf("\n");
}

int main() {
    struct Warehouse* warehouse = create_warehouse("Shocked Warehouse");

    struct Item* item1 = create_item("Item 1", 100);
    struct Item* item2 = create_item("Item 2", 200);
    struct Item* item3 = create_item("Item 3", 300);

    add_item_to_warehouse(warehouse, item1);
    add_item_to_warehouse(warehouse, item2);
    add_item_to_warehouse(warehouse, item3);

    print_warehouse(warehouse);

    return 0;
}