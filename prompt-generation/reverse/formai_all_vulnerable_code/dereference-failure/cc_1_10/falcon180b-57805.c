//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 10000
#define MAX_ITEM_NAME_LENGTH 50

struct warehouse {
    int capacity;
    int items_count;
    struct item *items;
};

struct item {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
};

void init_warehouse(struct warehouse *warehouse) {
    warehouse->capacity = MAX_WAREHOUSE_SIZE;
    warehouse->items_count = 0;
    warehouse->items = NULL;
}

void add_item(struct warehouse *warehouse, char *name, int quantity) {
    struct item *item = malloc(sizeof(struct item));

    if (item == NULL) {
        printf("Error: Out of memory\n");
        return;
    }

    strcpy(item->name, name);
    item->quantity = quantity;

    if (warehouse->items_count >= warehouse->capacity) {
        printf("Error: Warehouse is full\n");
        free(item);
        return;
    }

    warehouse->items = realloc(warehouse->items, sizeof(struct item) * ++warehouse->items_count);
    warehouse->items[warehouse->items_count - 1] = *item;
}

void remove_item(struct warehouse *warehouse, char *name) {
    int i;

    for (i = 0; i < warehouse->items_count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            free(warehouse->items[i].name);
            free(warehouse->items + i);
            warehouse->items_count--;
            memmove(warehouse->items + i, warehouse->items + i + 1, sizeof(struct item) * (warehouse->items_count - i));
            break;
        }
    }
}

void print_items(struct warehouse *warehouse) {
    int i;

    for (i = 0; i < warehouse->items_count; i++) {
        printf("%s - %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    struct warehouse warehouse;

    init_warehouse(&warehouse);

    add_item(&warehouse, "Apples", 100);
    add_item(&warehouse, "Oranges", 200);
    add_item(&warehouse, "Bananas", 300);

    print_items(&warehouse);

    remove_item(&warehouse, "Apples");

    print_items(&warehouse);

    return 0;
}