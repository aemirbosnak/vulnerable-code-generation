//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to store inventory item information
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

// Define a function to insert a new item into the inventory
void insertItem(Item* head, char* name, int quantity, float price) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Define a function to search for an item in the inventory
Item* searchItem(Item* head, char* name) {
    Item* currentItem = head;

    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }

    return NULL;
}

// Define a function to update the quantity of an item in the inventory
void updateQuantity(Item* head, char* name, int newQuantity) {
    Item* item = searchItem(head, name);

    if (item) {
        item->quantity = newQuantity;
    }
}

// Define a function to delete an item from the inventory
void deleteItem(Item* head, char* name) {
    Item* previousItem = NULL;
    Item* currentItem = head;

    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            if (previousItem) {
                previousItem->next = currentItem->next;
            } else {
                head = currentItem->next;
            }
            free(currentItem);
            return;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    return;
}

// Main function
int main() {
    Item* head = NULL;

    // Insert some items into the inventory
    insertItem(head, "Apple", 10, 1.20);
    insertItem(head, "Orange", 15, 1.50);
    insertItem(head, "Banana", 20, 1.80);

    // Search for an item in the inventory
    Item* item = searchItem(head, "Orange");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Update the quantity of an item in the inventory
    updateQuantity(head, "Apple", 12);

    // Search for the updated item in the inventory
    item = searchItem(head, "Apple");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Delete an item from the inventory
    deleteItem(head, "Banana");

    // Search for the deleted item in the inventory
    item = searchItem(head, "Banana");

    if (item == NULL) {
        printf("Item not found.\n");
    }

    return 0;
}