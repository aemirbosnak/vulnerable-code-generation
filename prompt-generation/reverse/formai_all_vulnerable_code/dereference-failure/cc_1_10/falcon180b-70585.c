//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    int size;
    int capacity;
    Item *items;
} Warehouse;

void initWarehouse(Warehouse *warehouse, int capacity) {
    warehouse->size = 0;
    warehouse->capacity = capacity;
    warehouse->items = (Item *)malloc(capacity * sizeof(Item));
}

void addItem(Warehouse *warehouse, int id, char *name, int quantity, float price) {
    if (warehouse->size >= warehouse->capacity) {
        printf("Warehouse is full.\n");
        return;
    }

    Item item;
    item.id = id;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;

    warehouse->items[warehouse->size] = item;
    warehouse->size++;
}

void removeItem(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->size--;
            for (int j = i; j < warehouse->size; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            break;
        }
    }
}

void displayItems(Warehouse *warehouse) {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < warehouse->size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse, 100);

    addItem(&warehouse, 1, "Apple", 50, 0.5);
    addItem(&warehouse, 2, "Orange", 30, 0.8);
    addItem(&warehouse, 3, "Banana", 70, 0.3);

    displayItems(&warehouse);

    removeItem(&warehouse, 1);

    displayItems(&warehouse);

    return 0;
}