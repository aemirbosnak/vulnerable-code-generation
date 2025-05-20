//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int quantity, double price);
Item* findItem(Item* head, char* name);
void updateQuantity(Item* head, char* name, int quantity);
void removeItem(Item* head, char* name);

int main() {
    Item* head = NULL;

    // Add items to the inventory
    addItem(&head, "Apple", 10, 1.2);
    addItem(&head, "Banana", 5, 0.8);
    addItem(&head, "Orange", 7, 0.9);

    // Find and update item quantity
    updateQuantity(head, "Banana", 10);

    // Remove item from inventory
    removeItem(head, "Orange");

    // Print inventory
    Item* currentItem = head;
    while (currentItem) {
        printf("%s: %d, $%.2lf\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }

    return 0;
}

Item* addItem(Item* head, char* name, int quantity, double price) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = head;
    head = newNode;

    return head;
}

Item* findItem(Item* head, char* name) {
    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }

    return NULL;
}

void updateQuantity(Item* head, char* name, int quantity) {
    Item* item = findItem(head, name);
    if (item) {
        item->quantity = quantity;
    }
}

void removeItem(Item* head, char* name) {
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