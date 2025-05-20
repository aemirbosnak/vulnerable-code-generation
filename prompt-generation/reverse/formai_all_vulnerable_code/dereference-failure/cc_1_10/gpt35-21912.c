//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure for Item
struct Item {
    char name[20];
    int quantity;
};

// Defining the structure for Warehouse
struct Warehouse {
    int numOfItems;
    struct Item *items;
};

// Function to add item to the warehouse
void addItem(struct Warehouse *w, char name[], int quantity) {
    struct Item *newItem = (struct Item*) malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;

    w->items = (struct Item*) realloc(w->items, (w->numOfItems+1) * sizeof(struct Item));
    w->items[w->numOfItems] = *newItem;
    w->numOfItems++;
    free(newItem);
}

// Function to remove item from the warehouse
void removeItem(struct Warehouse *w, char name[]) {
    int indexToRemove = -1;
    for(int i = 0; i < w->numOfItems; i++) {
        if(strcmp(w->items[i].name, name) == 0) {
            indexToRemove = i;
            break;
        }
    }
    if(indexToRemove != -1) {
        for(int i = indexToRemove; i < w->numOfItems-1; i++) {
            w->items[i] = w->items[i+1];
        }
        w->items = (struct Item*) realloc(w->items, (w->numOfItems-1) * sizeof(struct Item));
        w->numOfItems--;
    }
}

// Function to display all items in the warehouse
void displayWarehouse(struct Warehouse *w) {
    printf("Items in the warehouse:\n");
    for(int i = 0; i < w->numOfItems; i++) {
        printf("%s - %d\n", w->items[i].name, w->items[i].quantity);
    }
}

int main() {
    struct Warehouse w;
    w.numOfItems = 0;
    w.items = NULL;

    // Adding some initial items to the warehouse
    addItem(&w, "item1", 10);
    addItem(&w, "item2", 20);
    addItem(&w, "item3", 30);

    // Displaying the warehouse contents
    displayWarehouse(&w);

    // Adding a new item to the warehouse
    addItem(&w, "item4", 40);

    // Displaying the warehouse contents after adding a new item
    displayWarehouse(&w);

    // Removing an item from the warehouse
    removeItem(&w, "item2");

    // Displaying the warehouse contents after removing an item
    displayWarehouse(&w);

    return 0;
}