//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

typedef struct Warehouse {
    Item *items;
    int num_items;
    int capacity;
} Warehouse;

void initWarehouse(Warehouse *warehouse, int capacity) {
    warehouse->items = (Item *)malloc(capacity * sizeof(Item));
    warehouse->num_items = 0;
    warehouse->capacity = capacity;
}

int addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->num_items >= warehouse->capacity) {
        printf("Warehouse is full.\n");
        return -1;
    }
    strcpy(warehouse->items[warehouse->num_items].name, name);
    warehouse->items[warehouse->num_items].quantity = quantity;
    warehouse->num_items++;
    return 0;
}

int deleteItem(Warehouse *warehouse, const char *name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            memmove(&warehouse->items[i], &warehouse->items[i + 1],
                    (warehouse->num_items - i - 1) * sizeof(Item));
            warehouse->num_items--;
            return 0;
        }
    }
    printf("Item not found.\n");
    return -1;
}

Item *searchItem(Warehouse *warehouse, const char *name) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

void printWarehouse(const Warehouse *warehouse) {
    int i;
    printf("Warehouse contents:\n");
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse, MAX_ITEMS);
    addItem(&warehouse, "Widget", 10);
    addItem(&warehouse, "Gadget", 5);
    addItem(&warehouse, "Thingamajig", 7);
    printWarehouse(&warehouse);
    Item *item = searchItem(&warehouse, "Gadget");
    if (item != NULL) {
        item->quantity += 3;
        printf("Updated Gadget quantity: %d\n", item->quantity);
    }
    deleteItem(&warehouse, "Thingamajig");
    printWarehouse(&warehouse);
    return 0;
}