//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} item_t;

typedef struct {
    item_t *items;
    int num_items;
} warehouse_t;

void init_warehouse(warehouse_t *warehouse) {
    warehouse->items = (item_t *)malloc(MAX_ITEMS * sizeof(item_t));
    warehouse->num_items = 0;
}

void add_item(warehouse_t *warehouse, char *name, int quantity) {
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    strncpy(warehouse->items[warehouse->num_items].name, name, MAX_NAME_LEN);
    warehouse->items[warehouse->num_items].quantity = quantity;
    warehouse->num_items++;
}

void remove_item(warehouse_t *warehouse, char *name) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            free(warehouse->items[i].name);
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

void print_items(warehouse_t *warehouse) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    warehouse_t warehouse;
    init_warehouse(&warehouse);

    add_item(&warehouse, "Apples", 100);
    add_item(&warehouse, "Oranges", 200);
    add_item(&warehouse, "Bananas", 300);

    print_items(&warehouse);

    remove_item(&warehouse, "Bananas");

    print_items(&warehouse);

    return 0;
}