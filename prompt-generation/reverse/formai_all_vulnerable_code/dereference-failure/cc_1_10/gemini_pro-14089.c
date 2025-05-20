//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
} item_t;

typedef struct {
    char *name;
    int capacity;
    item_t **items;
} warehouse_t;

warehouse_t *create_warehouse(const char *name, int capacity) {
    warehouse_t *warehouse = malloc(sizeof(warehouse_t));
    warehouse->name = strdup(name);
    warehouse->capacity = capacity;
    warehouse->items = malloc(sizeof(item_t *) * capacity);
    return warehouse;
}

void free_warehouse(warehouse_t *warehouse) {
    for (int i = 0; i < warehouse->capacity; i++) {
        if (warehouse->items[i] != NULL) {
            free(warehouse->items[i]->name);
            free(warehouse->items[i]);
        }
    }
    free(warehouse->name);
    free(warehouse->items);
    free(warehouse);
}

item_t *create_item(const char *name, int quantity) {
    item_t *item = malloc(sizeof(item_t));
    item->name = strdup(name);
    item->quantity = quantity;
    return item;
}

void free_item(item_t *item) {
    free(item->name);
    free(item);
}

int add_item_to_warehouse(warehouse_t *warehouse, item_t *item) {
    for (int i = 0; i < warehouse->capacity; i++) {
        if (warehouse->items[i] == NULL) {
            warehouse->items[i] = item;
            return 0;
        }
    }
    return -1;
}

item_t *remove_item_from_warehouse(warehouse_t *warehouse, const char *name) {
    for (int i = 0; i < warehouse->capacity; i++) {
        if (warehouse->items[i] != NULL && strcmp(warehouse->items[i]->name, name) == 0) {
            item_t *item = warehouse->items[i];
            warehouse->items[i] = NULL;
            return item;
        }
    }
    return NULL;
}

void print_warehouse(warehouse_t *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    for (int i = 0; i < warehouse->capacity; i++) {
        if (warehouse->items[i] != NULL) {
            printf(" - %s: %d\n", warehouse->items[i]->name, warehouse->items[i]->quantity);
        }
    }
}

int main() {
    warehouse_t *warehouse = create_warehouse("My Warehouse", 10);

    item_t *item1 = create_item("Item 1", 10);
    item_t *item2 = create_item("Item 2", 20);
    item_t *item3 = create_item("Item 3", 30);

    add_item_to_warehouse(warehouse, item1);
    add_item_to_warehouse(warehouse, item2);
    add_item_to_warehouse(warehouse, item3);

    print_warehouse(warehouse);

    item_t *item4 = remove_item_from_warehouse(warehouse, "Item 2");
    free_item(item4);

    print_warehouse(warehouse);

    free_warehouse(warehouse);

    return 0;
}