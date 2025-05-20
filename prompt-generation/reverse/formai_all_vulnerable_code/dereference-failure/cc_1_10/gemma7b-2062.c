//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int quantity) {
    Item* newNode = malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void searchItem(Item* head, char* name) {
    Item* currentItem = head;

    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            printf("Item: %s, Quantity: %d\n", currentItem->name, currentItem->quantity);
            return;
        }

        currentItem = currentItem->next;
    }

    printf("Item not found.\n");
}

void updateItem(Item* head, char* name, int newQuantity) {
    Item* currentItem = head;

    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            currentItem->quantity = newQuantity;
            return;
        }

        currentItem = currentItem->next;
    }

    printf("Item not found.\n");
}

void deleteItem(Item* head, char* name) {
    Item* currentItem = head;
    Item* previousItem = NULL;

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

    printf("Item not found.\n");
}

int main() {
    Item* head = NULL;

    addItem(head, "Foo", 10);
    addItem(head, "Bar", 20);
    addItem(head, "Baz", 30);

    searchItem(head, "Foo");
    updateItem(head, "Bar", 25);
    deleteItem(head, "Baz");

    searchItem(head, "Foo");

    return 0;
}