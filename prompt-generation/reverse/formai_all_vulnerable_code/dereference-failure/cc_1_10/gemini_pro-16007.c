//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

typedef struct item_t {
    int id;
    char* name;
    int quantity;
    struct item_t* next;
} item_t;

typedef struct warehouse_t {
    item_t* items;
} warehouse_t;

warehouse_t* create_warehouse() {
    warehouse_t* warehouse = malloc(sizeof(warehouse_t));
    warehouse->items = NULL;
    return warehouse;
}

void destroy_warehouse(warehouse_t* warehouse) {
    item_t* item = warehouse->items;
    while (item != NULL) {
        item_t* next = item->next;
        free(item->name);
        free(item);
        item = next;
    }
    free(warehouse);
}

item_t* create_item(int id, char* name, int quantity) {
    item_t* item = malloc(sizeof(item_t));
    item->id = id;
    item->name = strdup(name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void destroy_item(item_t* item) {
    free(item->name);
    free(item);
}

void add_item(warehouse_t* warehouse, item_t* item) {
    if (warehouse->items == NULL) {
        warehouse->items = item;
    } else {
        add_item(warehouse, warehouse->items);
    }
}

item_t* find_item_by_id(warehouse_t* warehouse, int id) {
    if (warehouse->items == NULL) {
        return NULL;
    } else if (warehouse->items->id == id) {
        return warehouse->items;
    } else {
        return find_item_by_id(warehouse, warehouse->items->next);
    }
}

void remove_item_by_id(warehouse_t* warehouse, int id) {
    if (warehouse->items == NULL) {
        return;
    } else if (warehouse->items->id == id) {
        item_t* next = warehouse->items->next;
        destroy_item(warehouse->items);
        warehouse->items = next;
    } else {
        remove_item_by_id(warehouse, warehouse->items->next);
    }
}

void print_warehouse(warehouse_t* warehouse) {
    item_t* item = warehouse->items;
    while (item != NULL) {
        printf("Item %d: %s (%d)\n", item->id, item->name, item->quantity);
        item = item->next;
    }
}

int main() {
    warehouse_t* warehouse = create_warehouse();

    item_t* item1 = create_item(1, "Item 1", 10);
    add_item(warehouse, item1);

    item_t* item2 = create_item(2, "Item 2", 20);
    add_item(warehouse, item2);

    item_t* item3 = create_item(3, "Item 3", 30);
    add_item(warehouse, item3);

    print_warehouse(warehouse);

    item_t* found_item = find_item_by_id(warehouse, 2);
    if (found_item != NULL) {
        printf("Found item: %s (%d)\n", found_item->name, found_item->quantity);
    }

    remove_item_by_id(warehouse, 2);

    print_warehouse(warehouse);

    destroy_warehouse(warehouse);

    return 0;
}