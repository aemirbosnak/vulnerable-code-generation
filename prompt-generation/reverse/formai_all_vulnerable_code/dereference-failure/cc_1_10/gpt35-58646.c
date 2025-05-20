//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WarehouseItem {
    char name[50];
    int qty;
    float price;
} WarehouseItem;

typedef struct Warehouse {
    WarehouseItem *items;
    int numItems;
} Warehouse;

void printItem(WarehouseItem item) {
    printf("%s - Qty: %d, Price: $%.2f\n", item.name, item.qty, item.price);
}

void printWarehouse(Warehouse wh) {
    printf("Warehouse Contents:\n");
    for (int i = 0; i < wh.numItems; i++) {
        printItem(wh.items[i]);
    }
    printf("\n");
}

void addItem(Warehouse *wh, char *name, int qty, float price) {
    WarehouseItem item = {0};
    strcpy(item.name, name);
    item.qty = qty;
    item.price = price;

    wh->items = (WarehouseItem*) realloc(wh->items, (wh->numItems + 1) * sizeof(WarehouseItem));
    wh->items[wh->numItems] = item;
    wh->numItems += 1;
}

WarehouseItem* findItem(Warehouse *wh, char *name) {
    for (int i = 0; i < wh->numItems; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            return &wh->items[i];
        }
    }
    return NULL;
}

void removeItem(Warehouse *wh, char *name) {
    for (int i = 0; i < wh->numItems; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            for (int j = i; j < wh->numItems - 1; j++) {
                wh->items[j] = wh->items[j + 1];
            }
            wh->numItems -= 1;
            wh->items = (WarehouseItem*) realloc(wh->items, wh->numItems * sizeof(WarehouseItem));
            return;
        }
    }
}

void updateItem(Warehouse *wh, char *name, int qty, float price) {
    WarehouseItem *item = findItem(wh, name);
    if (item != NULL) {
        item->qty = qty;
        item->price = price;
    }
}

int main() {
    Warehouse wh = {0};
    addItem(&wh, "Widget", 10, 4.99);
    addItem(&wh, "Gizmo", 5, 9.99);
    addItem(&wh, "Thingamajig", 3, 14.99);

    printWarehouse(wh);

    WarehouseItem *item = findItem(&wh, "Gizmo");
    if (item != NULL) {
        printf("Found Gizmo:\n");
        printItem(*item);
    }

    updateItem(&wh, "Widget", 20, 7.99);
    removeItem(&wh, "Thingamajig");

    printWarehouse(wh);

    return 0;
}