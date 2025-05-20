//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Sherlock's Warehouse
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

//The Yard
typedef struct {
    Item *items;
    int size;
    int capacity;
} Warehouse;

//Elementary, my dear Watson
Warehouse *createWarehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = malloc(sizeof(Item) * capacity);
    warehouse->size = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

//The Game is Afoot
void addItem(Warehouse *warehouse, Item *item) {
    if (warehouse->size == warehouse->capacity) {
        warehouse->items = realloc(warehouse->items, sizeof(Item) * warehouse->capacity * 2);
        warehouse->capacity *= 2;
    }
    warehouse->items[warehouse->size++] = *item;
}

//The Adventure of the Empty House
void removeItem(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->size; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->size - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->size--;
            break;
        }
    }
}

//The Sign of Four
float getTotalValue(Warehouse *warehouse) {
    float totalValue = 0;
    for (int i = 0; i < warehouse->size; i++) {
        totalValue += warehouse->items[i].price * warehouse->items[i].quantity;
    }
    return totalValue;
}

//The Valley of Fear
void printWarehouse(Warehouse *warehouse) {
    printf("Sherlock's Warehouse\n");
    printf("--------------------\n");
    for (int i = 0; i < warehouse->size; i++) {
        printf("%s: %d (%0.2f)\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("\n");
}

//The Final Problem
void destroyWarehouse(Warehouse *warehouse) {
    free(warehouse->items);
    free(warehouse);
}

//Let the games begin!
int main() {
    //Creating a new warehouse
    Warehouse *warehouse = createWarehouse(10);

    //Adding some items to the warehouse
    Item item1 = {"Pipe", 5, 10.0};
    addItem(warehouse, &item1);
    Item item2 = {"Violin", 1, 20.0};
    addItem(warehouse, &item2);
    Item item3 = {"Magnifying Glass", 3, 5.0};
    addItem(warehouse, &item3);

    //Printing the warehouse
    printWarehouse(warehouse);

    //Getting the total value of the warehouse
    printf("Total value: %0.2f\n", getTotalValue(warehouse));

    //Removing an item from the warehouse
    removeItem(warehouse, "Violin");

    //Printing the updated warehouse
    printWarehouse(warehouse);

    //Destroying the warehouse
    destroyWarehouse(warehouse);

    return 0;
}