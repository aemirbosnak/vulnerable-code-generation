//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the structure for each item in the warehouse
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    char location[10];
    struct Item* next;
} Item;

// define the structure for the linked list of items in the warehouse
typedef struct Warehouse {
    Item* head;
    int size;
} Warehouse;

// function to create a new item
Item* createItem(char name[], int quantity, float price, char location[]) {
    Item* newItem = (Item*) malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    strcpy(newItem->location, location);
    newItem->next = NULL;
    return newItem;
}

// function to add an item to the warehouse
void addItem(Warehouse* warehouse, char name[], int quantity, float price, char location[]) {
    Item* newItem = createItem(name, quantity, price, location);
    if (warehouse->head == NULL) {
        warehouse->head = newItem;
    } else {
        Item* currItem = warehouse->head;
        while (currItem->next != NULL) {
            currItem = currItem->next;
        }
        currItem->next = newItem;
    }
    warehouse->size++;
}

// function to remove an item from the warehouse
void removeItem(Warehouse* warehouse, char name[]) {
    if (warehouse->head == NULL) {
        printf("Warehouse is empty, cannot remove item.\n");
        return;
    }
    Item* prevItem = NULL;
    Item* currItem = warehouse->head;
    while (currItem != NULL && strcmp(currItem->name, name) != 0) {
        prevItem = currItem;
        currItem = currItem->next;
    }
    if (currItem == NULL) {
        printf("Item not found in warehouse.\n");
        return;
    }
    if (prevItem == NULL) {
        warehouse->head = currItem->next;
    } else {
        prevItem->next = currItem->next;
    }
    free(currItem);
    warehouse->size--;
}

// function to display the items in the warehouse
void displayItems(Warehouse* warehouse) {
    if (warehouse->head == NULL) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("%-20s%-10s%-10s%s\n", "Name", "Quantity", "Price", "Location");
    Item* currItem = warehouse->head;
    while (currItem != NULL) {
        printf("%-20s%-10d%-10.2f%s\n", currItem->name, currItem->quantity, currItem->price, currItem->location);
        currItem = currItem->next;
    }
}

int main() {
    Warehouse* warehouse = (Warehouse*) malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->size = 0;
    
    // add some items to the warehouse
    addItem(warehouse, "Book", 10, 12.99, "Aisle 1");
    addItem(warehouse, "Shirt", 20, 24.99, "Aisle 2");
    addItem(warehouse, "Phone", 5, 699.99, "Aisle 3");
    addItem(warehouse, "TV", 2, 999.99, "Aisle 4");
    
    // display the items in the warehouse
    displayItems(warehouse);
    
    // remove an item from the warehouse
    removeItem(warehouse, "Phone");
    
    // display the items in the warehouse again
    displayItems(warehouse);
    
    return 0;
}