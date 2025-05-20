//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_QUANTITY 1000

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_WAREHOUSE_SIZE];
    int numItems;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* w = malloc(sizeof(Warehouse));
    w->numItems = 0;
    return w;
}

void addItem(Warehouse* w, char* name, int quantity) {
    if (w->numItems >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse full, cannot add item.\n");
        return;
    }

    Item* i = &w->items[w->numItems];
    strcpy(i->name, name);
    i->quantity = quantity;
    w->numItems++;
}

void removeItem(Warehouse* w, char* name) {
    for (int i = 0; i < w->numItems; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->items[i].quantity = 0;
            w->numItems--;
            return;
        }
    }

    printf("Item not found in warehouse.\n");
}

void displayItems(Warehouse* w) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < w->numItems; i++) {
        printf("%s: %d\n", w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    Warehouse* w = createWarehouse();

    addItem(w, "Swords", 100);
    addItem(w, "Shields", 50);
    addItem(w, "Armor", 25);

    displayItems(w);

    removeItem(w, "Swords");

    displayItems(w);

    return 0;
}