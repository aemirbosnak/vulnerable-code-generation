//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WarehouseItem {
    int ID;
    char itemName[50];
    int quantity;
    float price;
};

struct Warehouse {
    struct WarehouseItem* items;
    int capacity;
    int itemCount;
};

void initWarehouse(struct Warehouse* warehouse) {
    warehouse->capacity = 10;
    warehouse->itemCount = 0;
    warehouse->items = (struct WarehouseItem*)malloc(warehouse->capacity * sizeof(struct WarehouseItem));
}

void addItem(struct Warehouse* warehouse, struct WarehouseItem item) {
    if (warehouse->itemCount >= warehouse->capacity) {
        warehouse->capacity *= 2;
        warehouse->items = (struct WarehouseItem*)realloc(warehouse->items, warehouse->capacity * sizeof(struct WarehouseItem));
    }
    warehouse->items[warehouse->itemCount] = item;
    warehouse->itemCount++;
}

void removeItem(struct Warehouse* warehouse, int id) {
    int index = -1;
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].ID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item with ID %d not found in warehouse.\n", id);
        return;
    }

    for (int i = index; i < warehouse->itemCount - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->itemCount--;
}

void displayWarehouse(struct Warehouse* warehouse) {
    printf("Warehouse inventory:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        struct WarehouseItem item = warehouse->items[i];
        printf("Item ID: %d | Item Name: %s | Quantity: %d | Price: $%.2f\n", item.ID, item.itemName, item.quantity, item.price);
    }
}

int main() {
    struct Warehouse warehouse;
    initWarehouse(&warehouse);

    struct WarehouseItem item1 = { 1, "Shoes", 20, 49.99 };
    addItem(&warehouse, item1);
    struct WarehouseItem item2 = { 2, "Bags", 15, 29.99 };
    addItem(&warehouse, item2);
    struct WarehouseItem item3 = { 3, "Hats", 30, 9.99 };
    addItem(&warehouse, item3);

    removeItem(&warehouse, 4);
    removeItem(&warehouse, 2);

    displayWarehouse(&warehouse);

    return 0;
}