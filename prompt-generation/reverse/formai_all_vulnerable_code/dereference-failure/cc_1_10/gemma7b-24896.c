//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LOCATION 10

typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

typedef struct Location {
    int number;
    Item* items;
    struct Location* next;
} Location;

Location* headLocation = NULL;

void addItem(char* name, int quantity) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (headLocation == NULL) {
        headLocation = (Location*)malloc(sizeof(Location));
        headLocation->number = 1;
        headLocation->items = newItem;
        headLocation->next = NULL;
    } else {
        Location* newLocation = (Location*)malloc(sizeof(Location));
        newLocation->number = headLocation->number + 1;
        newLocation->items = newItem;
        newLocation->next = NULL;

        headLocation->next = newLocation;
        headLocation = newLocation;
    }
}

void showItems() {
    Location* currentLocation = headLocation;
    while (currentLocation) {
        Item* currentItem = currentLocation->items;
        while (currentItem) {
            printf("%s - %d\n", currentItem->name, currentItem->quantity);
            currentItem = currentItem->next;
        }
        currentLocation = currentLocation->next;
    }
}

int main() {
    addItem("Apple", 10);
    addItem("Banana", 5);
    addItem("Orange", 7);

    showItems();

    return 0;
}