//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int quantity;
    double price;
} Item;

typedef struct {
    Item* items;
    int num_items;
} Warehouse;

Warehouse* create_warehouse() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->items = NULL;
    warehouse->num_items = 0;
    return warehouse;
}

void add_item(Warehouse* warehouse, char* name, int quantity, double price) {
    warehouse->items = realloc(warehouse->items, (warehouse->num_items + 1) * sizeof(Item));
    warehouse->items[warehouse->num_items].name = strdup(name);
    warehouse->items[warehouse->num_items].quantity = quantity;
    warehouse->items[warehouse->num_items].price = price;
    warehouse->num_items++;
}

Item* find_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

void remove_item(Warehouse* warehouse, char* name) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        free(warehouse->items[index].name);
        for (int i = index; i < warehouse->num_items - 1; i++) {
            warehouse->items[i] = warehouse->items[i + 1];
        }
        warehouse->num_items--;
        warehouse->items = realloc(warehouse->items, warehouse->num_items * sizeof(Item));
    }
}

void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf(" - %s: %d @ $%.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void destroy_warehouse(Warehouse* warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->items[i].name);
    }
    free(warehouse->items);
    free(warehouse);
}

int main() {
    Warehouse* warehouse = create_warehouse();

    add_item(warehouse, "apples", 10, 1.0);
    add_item(warehouse, "oranges", 5, 1.5);
    add_item(warehouse, "bananas", 15, 2.0);

    print_warehouse(warehouse);

    Item* apples = find_item(warehouse, "apples");
    if (apples != NULL) {
        apples->quantity += 10;
    }

    remove_item(warehouse, "oranges");

    print_warehouse(warehouse);

    destroy_warehouse(warehouse);

    return 0;
}