//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct item {
    char name[50];
    int quantity;
    float price;
} item_t;

typedef struct warehouse {
    item_t *items;
    int capacity;
    int size;
} warehouse_t;

warehouse_t *create_warehouse() {
    warehouse_t *warehouse = (warehouse_t *)malloc(sizeof(warehouse_t));
    warehouse->items = (item_t *)malloc(INITIAL_CAPACITY * sizeof(item_t));
    warehouse->capacity = INITIAL_CAPACITY;
    warehouse->size = 0;
    return warehouse;
}

void destroy_warehouse(warehouse_t *warehouse) {
    free(warehouse->items);
    free(warehouse);
}

void add_item(warehouse_t *warehouse, char *name, int quantity, float price) {
    if (warehouse->size >= warehouse->capacity) {
        warehouse->capacity *= 2;
        warehouse->items = (item_t *)realloc(warehouse->items, warehouse->capacity * sizeof(item_t));
    }

    strcpy(warehouse->items[warehouse->size].name, name);
    warehouse->items[warehouse->size].quantity = quantity;
    warehouse->items[warehouse->size].price = price;

    warehouse->size++;
}

void remove_item(warehouse_t *warehouse, int index) {
    if (index >= 0 && index < warehouse->size) {
        free(warehouse->items[index].name);
        warehouse->size--;

        for (int i = index; i < warehouse->size; i++) {
            strcpy(warehouse->items[i].name, warehouse->items[i + 1].name);
            warehouse->items[i].quantity = warehouse->items[i + 1].quantity;
            warehouse->items[i].price = warehouse->items[i + 1].price;
        }
    }
}

void print_items(warehouse_t *warehouse) {
    for (int i = 0; i < warehouse->size; i++) {
        printf("%s - %d units - $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    warehouse_t *warehouse = create_warehouse();

    add_item(warehouse, "Apples", 100, 0.50);
    add_item(warehouse, "Oranges", 50, 0.75);
    add_item(warehouse, "Bananas", 25, 0.25);

    print_items(warehouse);

    remove_item(warehouse, 1);

    print_items(warehouse);

    destroy_warehouse(warehouse);

    return 0;
}