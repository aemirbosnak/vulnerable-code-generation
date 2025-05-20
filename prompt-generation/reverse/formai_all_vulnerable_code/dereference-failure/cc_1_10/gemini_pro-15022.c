//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

typedef struct {
    Item *items;
    int itemCount;
    float totalValue;
} Warehouse;

Warehouse *createWarehouse(int itemCount) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = malloc(sizeof(Item) * itemCount);
    warehouse->itemCount = itemCount;
    warehouse->totalValue = 0;
    return warehouse;
}

void addItem(Warehouse *warehouse, char *name, int quantity, float price) {
    warehouse->items[warehouse->itemCount].name = strdup(name);
    warehouse->items[warehouse->itemCount].quantity = quantity;
    warehouse->items[warehouse->itemCount].price = price;
    warehouse->totalValue += quantity * price;
    warehouse->itemCount++;
}

void printWarehouse(Warehouse *warehouse) {
    printf("Warehouse has %d items with a total value of %.2f\n", warehouse->itemCount, warehouse->totalValue);
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item %d: %s (%d units at %.2f each)\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void freeWarehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        free(warehouse->items[i].name);
    }
    free(warehouse->items);
    free(warehouse);
}

int main() {
    // Create a new warehouse with 3 items
    Warehouse *warehouse = createWarehouse(3);

    // Add some items to the warehouse
    addItem(warehouse, "Apples", 10, 1.50);
    addItem(warehouse, "Bananas", 20, 2.00);
    addItem(warehouse, "Oranges", 30, 2.50);

    // Print the warehouse
    printWarehouse(warehouse);

    // Free the warehouse
    freeWarehouse(warehouse);

    return 0;
}