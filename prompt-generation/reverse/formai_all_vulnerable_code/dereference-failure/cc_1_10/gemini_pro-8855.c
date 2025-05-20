//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int quantity;
} item_t;

typedef struct {
    char *name;
    int capacity;
    item_t *items;
    int num_items;
} warehouse_t;

warehouse_t *create_warehouse(char *name, int capacity) {
    warehouse_t *warehouse = malloc(sizeof(warehouse_t));
    warehouse->name = name;
    warehouse->capacity = capacity;
    warehouse->items = malloc(sizeof(item_t) * capacity);
    warehouse->num_items = 0;
    return warehouse;
}

void destroy_warehouse(warehouse_t *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i].name);
    }
    free(warehouse->items);
    free(warehouse->name);
    free(warehouse);
}

item_t *create_item(char *name, int quantity) {
    item_t *item = malloc(sizeof(item_t));
    item->name = name;
    item->quantity = quantity;
    return item;
}

void destroy_item(item_t *item) {
    free(item->name);
    free(item);
}

int add_item(warehouse_t *warehouse, item_t *item) {
    if (warehouse->num_items == warehouse->capacity) {
        return -1;
    }
    warehouse->items[warehouse->num_items++] = *item;
    return 0;
}

int remove_item(warehouse_t *warehouse, char *name, int quantity) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity >= quantity) {
                warehouse->items[i].quantity -= quantity;
                return 0;
            }
            else {
                return -1;
            }
        }
    }
    return -1;
}

void print_warehouse(warehouse_t *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("Capacity: %d\n", warehouse->capacity);
    printf("Items:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  - %s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    warehouse_t *warehouse = create_warehouse("My Warehouse", 10);
    item_t *item1 = create_item("Item 1", 5);
    item_t *item2 = create_item("Item 2", 10);
    item_t *item3 = create_item("Item 3", 15);
    add_item(warehouse, item1);
    add_item(warehouse, item2);
    add_item(warehouse, item3);
    print_warehouse(warehouse);
    remove_item(warehouse, "Item 2", 5);
    print_warehouse(warehouse);
    destroy_item(item1);
    destroy_item(item2);
    destroy_item(item3);
    destroy_warehouse(warehouse);
    return 0;
}