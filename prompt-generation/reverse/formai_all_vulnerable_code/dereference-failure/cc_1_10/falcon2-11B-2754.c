//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int quantity;
} Item;

typedef struct {
    char* warehouse;
    char* location;
    Item* items;
} Warehouse;

int main() {
    Warehouse warehouse;
    warehouse.warehouse = "My Warehouse";
    warehouse.location = "Location A";
    warehouse.items = (Item*)malloc(10 * sizeof(Item));
    Item item;
    item.name = "Product 1";
    item.quantity = 50;
    item.name = "Product 2";
    item.quantity = 30;
    item.name = "Product 3";
    item.quantity = 40;
    item.name = "Product 4";
    item.quantity = 10;
    item.name = "Product 5";
    item.quantity = 15;
    item.name = "Product 6";
    item.quantity = 20;
    item.name = "Product 7";
    item.quantity = 25;
    item.name = "Product 8";
    item.quantity = 30;
    item.name = "Product 9";
    item.quantity = 35;
    item.name = "Product 10";
    item.quantity = 40;
    warehouse.items[0] = item;
    warehouse.items[1] = item;
    warehouse.items[2] = item;
    warehouse.items[3] = item;
    warehouse.items[4] = item;
    warehouse.items[5] = item;
    warehouse.items[6] = item;
    warehouse.items[7] = item;
    warehouse.items[8] = item;
    warehouse.items[9] = item;

    printf("Warehouse: %s\nLocation: %s\n", warehouse.warehouse, warehouse.location);
    for (int i = 0; i < 10; i++) {
        printf("Product %d: %s, Quantity: %d\n", i+1, warehouse.items[i].name, warehouse.items[i].quantity);
    }
    return 0;
}