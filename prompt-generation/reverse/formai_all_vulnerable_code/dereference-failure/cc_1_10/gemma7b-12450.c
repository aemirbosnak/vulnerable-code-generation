//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a dystopian warehouse management system
struct Item {
    char name[20];
    int quantity;
    float price;
    struct Item* next;
};

struct Warehouse {
    struct Item* head;
    struct Item* tail;
    int numItems;
    float totalValue;
};

void initializeWarehouse(struct Warehouse* warehouse) {
    warehouse->head = NULL;
    warehouse->tail = NULL;
    warehouse->numItems = 0;
    warehouse->totalValue = 0.0f;
}

void addItem(struct Warehouse* warehouse, char* name, int quantity, float price) {
    struct Item* newItem = malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newItem;
        warehouse->tail = newItem;
    } else {
        warehouse->tail->next = newItem;
        warehouse->tail = newItem;
    }

    warehouse->numItems++;
    warehouse->totalValue += newItem->quantity * newItem->price;
}

void removeItem(struct Warehouse* warehouse, char* name) {
    struct Item* currentItem = warehouse->head;
    struct Item* previousItem = NULL;

    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            if (previousItem) {
                previousItem->next = currentItem->next;
                warehouse->tail = previousItem;
            } else {
                warehouse->head = currentItem->next;
                warehouse->tail = warehouse->head;
            }

            warehouse->numItems--;
            warehouse->totalValue -= currentItem->quantity * currentItem->price;
            free(currentItem);
            return;
        }

        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    printf("Item not found.\n");
}

int main() {
    struct Warehouse* warehouse = malloc(sizeof(struct Warehouse));
    initializeWarehouse(warehouse);

    addItem(warehouse, "Water", 10, 2.5f);
    addItem(warehouse, "Food", 20, 3.0f);
    addItem(warehouse, "Weapons", 5, 4.0f);
    addItem(warehouse, "Medical supplies", 15, 2.0f);

    removeItem(warehouse, "Weapons");

    printf("Items:");
    struct Item* currentItem = warehouse->head;
    while (currentItem) {
        printf(" %s (%d) @ $%.2f", currentItem->name, currentItem->quantity, currentItem->price);
    }

    printf("\nTotal value: $%.2f", warehouse->totalValue);

    free(warehouse);
    return 0;
}