//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int quantity, double price) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        Item* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newItem;
    }

    return head;
}

int main() {
    Item* head = NULL;

    // Insert items
    insertItem(head, "Apple", 10, 1.2);
    insertItem(head, "Banana", 5, 1.5);
    insertItem(head, "Orange", 7, 1.3);
    insertItem(head, "Grape", 2, 1.7);

    // Print items
    Item* currentItem = head;
    while (currentItem) {
        printf("%s: %d, $%.2lf\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }

    return 0;
}