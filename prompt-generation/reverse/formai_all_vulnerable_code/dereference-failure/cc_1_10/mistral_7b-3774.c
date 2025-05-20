//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
} Inventory;

typedef struct {
    char itemName[50];
    int quantity;
    Inventory stock;
} Warehouse;

void addItemToWarehouse(Warehouse *warehouse, char *itemName, int quantity) {
    strcpy(warehouse->itemName, itemName);
    warehouse->quantity += quantity;
    Inventory *newStock = (Inventory *) malloc(sizeof(Inventory));
    strcpy(newStock->name, itemName);
    newStock->stock = quantity;
    warehouse->stock = *newStock;
}

void removeItemFromWarehouse(Warehouse *warehouse, char *itemName, int quantity) {
    if (strcmp(warehouse->itemName, itemName) != 0) {
        printf("Error: Item not found.\n");
        return;
    }

    if (warehouse->stock.stock < quantity) {
        printf("Error: Insufficient stock.\n");
        return;
    }

    warehouse->stock.stock -= quantity;
    warehouse->quantity -= quantity;
}

int main() {
    Warehouse myWarehouse;
    strcpy(myWarehouse.itemName, "Grains");
    myWarehouse.quantity = 100;
    myWarehouse.stock.stock = 150;

    printf("Current inventory: Item = %s, Stock = %d, Quantity = %d\n", myWarehouse.itemName, myWarehouse.stock.stock, myWarehouse.quantity);

    addItemToWarehouse(&myWarehouse, "Wheat", 50);
    addItemToWarehouse(&myWarehouse, "Barley", 75);

    printf("\nNew inventory:\n");
    printf("Item = %s, Stock = %d, Quantity = %d\n", myWarehouse.itemName, myWarehouse.stock.stock, myWarehouse.quantity);
    printf("Item = %s, Stock = %d, Quantity = %d\n", myWarehouse.stock.name, myWarehouse.stock.stock, myWarehouse.stock.stock);

    removeItemFromWarehouse(&myWarehouse, "Wheat", 25);

    printf("\nNew inventory after removing 25 units of Wheat:\n");
    printf("Item = %s, Stock = %d, Quantity = %d\n", myWarehouse.itemName, myWarehouse.stock.stock, myWarehouse.quantity);
    printf("Item = %s, Stock = %d, Quantity = %d\n", myWarehouse.stock.name, myWarehouse.stock.stock, myWarehouse.stock.stock);

    return 0;
}