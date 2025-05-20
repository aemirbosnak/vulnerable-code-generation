//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[20];
    int quantity;
    float price;
    struct Item* next;
};

struct Warehouse {
    struct Item* head;
    int totalItems;
    float totalValue;
};

void insertItem(struct Warehouse* warehouse, char* name, int quantity, float price) {
    struct Item* newNode = malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
    } else {
        warehouse->head->next = newNode;
    }

    warehouse->totalItems++;
    warehouse->totalValue += quantity * price;
}

void printInventory(struct Warehouse* warehouse) {
    struct Item* currentItem = warehouse->head;

    printf("Inventory:\n");
    while (currentItem) {
        printf("%s: %d, $%.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }

    printf("\nTotal items: %d\n", warehouse->totalItems);
    printf("Total value: $%.2f\n", warehouse->totalValue);
}

int main() {
    struct Warehouse warehouse;
    warehouse.head = NULL;
    warehouse.totalItems = 0;
    warehouse.totalValue = 0.0f;

    insertItem(&warehouse, "Apple", 10, 1.20);
    insertItem(&warehouse, "Banana", 20, 0.80);
    insertItem(&warehouse, "Orange", 15, 0.90);

    printInventory(&warehouse);

    return 0;
}