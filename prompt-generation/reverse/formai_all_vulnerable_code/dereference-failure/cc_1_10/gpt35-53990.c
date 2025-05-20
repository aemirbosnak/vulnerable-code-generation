//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// define struct for warehouse items
typedef struct {
    int itemID;
    char itemName[50];
    double itemPrice;
    int itemQuantity;
} WarehouseItem;

// define struct for warehouse
typedef struct {
    WarehouseItem* items;
    int numItems;
} Warehouse;

// function to add new item to warehouse
void addItem(Warehouse* warehouse, int itemID, char itemName[50], double itemPrice, int itemQuantity) {
    // reallocate memory for items array in warehouse
    warehouse->items = (WarehouseItem*)realloc(warehouse->items, (warehouse->numItems + 1) * sizeof(WarehouseItem));
    // add new item to items array
    warehouse->items[warehouse->numItems].itemID = itemID;
    strcpy(warehouse->items[warehouse->numItems].itemName, itemName);
    warehouse->items[warehouse->numItems].itemPrice = itemPrice;
    warehouse->items[warehouse->numItems].itemQuantity = itemQuantity;
    // increment number of items in warehouse
    warehouse->numItems++;
}

// function to remove item from warehouse
void removeItem(Warehouse* warehouse, int itemID) {
    int i, j;
    // search for item with matching ID
    for (i = 0; i < warehouse->numItems; i++) {
        if (warehouse->items[i].itemID == itemID) {
            // move all items after i down by one index to close gap
            for (j = i; j < warehouse->numItems - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            // reallocate memory for items array in warehouse
            warehouse->items = (WarehouseItem*)realloc(warehouse->items, (warehouse->numItems - 1) * sizeof(WarehouseItem));
            // decrement number of items in warehouse
            warehouse->numItems--;
            printf("Item with ID %d removed from warehouse.\n", itemID);
            return;
        }
    }
    // print error message if item with given ID is not found
    printf("Error: Item with ID %d is not in warehouse.\n", itemID);
}

// function to display all items in warehouse
void displayWarehouse(Warehouse* warehouse) {
    int i;
    printf("Items in warehouse:\n");
    for (i = 0; i < warehouse->numItems; i++) {
        printf("ID: %d  Name: %s  Price: %.2f  Quantity: %d\n", warehouse->items[i].itemID, warehouse->items[i].itemName, warehouse->items[i].itemPrice, warehouse->items[i].itemQuantity);
    }
}

int main() {
    Warehouse warehouse;
    warehouse.items = NULL;
    warehouse.numItems = 0;

    // add initial items to warehouse
    addItem(&warehouse, 1001, "Pencils", 0.50, 100);
    addItem(&warehouse, 1002, "Notebooks", 1.00, 50);
    addItem(&warehouse, 1003, "Pens", 0.75, 75);

    // display initial warehouse state
    displayWarehouse(&warehouse);

    // add new items to warehouse
    addItem(&warehouse, 1004, "Erasers", 0.25, 200);
    addItem(&warehouse, 1005, "Markers", 1.50, 25);

    // display changed warehouse state
    displayWarehouse(&warehouse);

    // remove an item from warehouse
    removeItem(&warehouse, 1002);

    // display changed warehouse state
    displayWarehouse(&warehouse);

    // free memory allocated for items array in warehouse
    free(warehouse.items);

    return 0;
}