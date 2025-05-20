//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LOCATIONS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Location *location;
} Item;

typedef struct Location {
    int number;
    struct Item **items;
} Location;

Item **items = NULL;
Location **locations = NULL;

void initializeItems(int numItems) {
    items = malloc(numItems * sizeof(Item));
    for (int i = 0; i < numItems; i++) {
        items[i] = malloc(sizeof(Item));
    }
}

void initializeLocations(int numLocations) {
    locations = malloc(numLocations * sizeof(Location));
    for (int i = 0; i < numLocations; i++) {
        locations[i] = malloc(sizeof(Location));
    }
}

void addItem(char *name, int quantity, int locationNumber) {
    initializeItems(quantity);
    initializeLocations(locationNumber);

    Item *newItem = items[0];
    strcpy(newItem->name, name);
    newItem->quantity = quantity;

    Location *newLocation = locations[locationNumber - 1];
    newLocation->items = newItem;
    newLocation->items[0] = newItem;

    printf("Item %s added to location %d.\n", name, locationNumber);
}

int main() {
    addItem("Test Item", 10, 1);
    addItem("Another Item", 5, 2);
    addItem("Third Item", 7, 1);

    for (int i = 0; i < MAX_ITEMS; i++) {
        for (int j = 0; j < MAX_LOCATIONS; j++) {
            Item *item = items[i];
            Location *location = locations[j];
            if (item && location && item->location == location) {
                printf("Item: %s, Quantity: %d, Location: %d\n", item->name, item->quantity, location->number);
            }
        }
    }

    return 0;
}