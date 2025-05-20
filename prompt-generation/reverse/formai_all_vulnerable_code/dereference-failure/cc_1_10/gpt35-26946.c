//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct warehouse {
    Item *items;
    int num_items;
    int max_items;
} Warehouse;

void add_item(Warehouse *warehouse, Item *item) {
    if (warehouse->num_items == warehouse->max_items) {
        printf("Warehouse is full!\n");
        return;
    }

    bool item_exists = false;
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == item->id) {
            item_exists = true;
            index = i;
            break;
        }
    }

    if (item_exists) {
        printf("Item already exists in warehouse! Updating quantity...\n");
        warehouse->items[index].quantity += item->quantity;
    }
    else {
        warehouse->items[warehouse->num_items++] = *item;
        printf("Item added to warehouse!\n");
    }
}

void remove_item(Warehouse *warehouse, int id) {
    bool item_exists = false;
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            item_exists = true;
            index = i;
            break;
        }
    }

    if (item_exists) {
        printf("Item removed from warehouse!\n");
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i + 1];
        }
        warehouse->num_items--;
    }
    else {
        printf("Item not found in warehouse!\n");
    }
}

void print_items(Warehouse *warehouse) {
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%d\t%s\t\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    warehouse.items = malloc(sizeof(Item) * 10);
    warehouse.num_items = 0;
    warehouse.max_items = 10;

    Item item1 = {1, "Apple", 5};
    Item item2 = {2, "Banana", 7};
    Item item3 = {3, "Orange", 10};

    add_item(&warehouse, &item1);
    add_item(&warehouse, &item2);
    add_item(&warehouse, &item3);

    print_items(&warehouse);

    remove_item(&warehouse, 2);

    print_items(&warehouse);

    free(warehouse.items);

    return 0;
}