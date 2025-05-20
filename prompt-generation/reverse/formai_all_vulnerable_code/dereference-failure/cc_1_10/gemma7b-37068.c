//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_ Shelves 10

typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

typedef struct Shelf {
    Item* items;
    struct Shelf* next;
} Shelf;

Shelf* createShelf() {
    Shelf* newShelf = malloc(sizeof(Shelf));
    newShelf->items = NULL;
    newShelf->next = NULL;
    return newShelf;
}

void addItem(Shelf* shelf, char* name, int quantity) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (shelf->items == NULL) {
        shelf->items = newItem;
    } else {
        Item* currentItem = shelf->items;
        while (currentItem->next) {
            currentItem = currentItem->next;
        }
        currentItem->next = newItem;
    }
}

void showItems(Shelf* shelf) {
    Item* currentItem = shelf->items;
    while (currentItem) {
        printf("%s - %d\n", currentItem->name, currentItem->quantity);
        currentItem = currentItem->next;
    }
}

int main() {
    Shelf* warehouse = createShelf();

    addItem(warehouse, "Apple", 10);
    addItem(warehouse, "Banana", 20);
    addItem(warehouse, "Orange", 15);

    showItems(warehouse);

    return 0;
}