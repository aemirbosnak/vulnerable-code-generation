//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct warehouse {
    char name[50];
    int capacity;
    int items;
    struct item *items_list;
};

struct item {
    char name[50];
    int quantity;
    double price;
};

void add_item(struct warehouse *warehouse, struct item *item) {
    warehouse->items++;
    warehouse->items_list = realloc(warehouse->items_list, warehouse->items * sizeof(struct item));
    warehouse->items_list[warehouse->items - 1] = *item;
}

void remove_item(struct warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->items; i++) {
        if (strcmp(warehouse->items_list[i].name, name) == 0) {
            warehouse->items--;
            warehouse->items_list = realloc(warehouse->items_list, warehouse->items * sizeof(struct item));
            memmove(&warehouse->items_list[i], &warehouse->items_list[i + 1], (warehouse->items - i) * sizeof(struct item));
            break;
        }
    }
}

int main() {
    struct warehouse warehouse1 = {"Warehouse 1", 100, 0, NULL};
    struct item item1 = {"Item 1", 10, 10.0};
    struct item item2 = {"Item 2", 20, 15.0};
    struct item item3 = {"Item 3", 30, 20.0};

    add_item(&warehouse1, &item1);
    add_item(&warehouse1, &item2);
    add_item(&warehouse1, &item3);

    printf("Warehouse 1:\n");
    printf("Name: %s\n", warehouse1.name);
    printf("Capacity: %d\n", warehouse1.capacity);
    printf("Items: %d\n", warehouse1.items);
    for (int i = 0; i < warehouse1.items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", warehouse1.items_list[i].name);
        printf("Quantity: %d\n", warehouse1.items_list[i].quantity);
        printf("Price: %.2f\n", warehouse1.items_list[i].price);
    }

    remove_item(&warehouse1, "Item 2");

    printf("\nWarehouse 1 after removing Item 2:\n");
    printf("Name: %s\n", warehouse1.name);
    printf("Capacity: %d\n", warehouse1.capacity);
    printf("Items: %d\n", warehouse1.items);
    for (int i = 0; i < warehouse1.items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", warehouse1.items_list[i].name);
        printf("Quantity: %d\n", warehouse1.items_list[i].quantity);
        printf("Price: %.2f\n", warehouse1.items_list[i].price);
    }

    return 0;
}