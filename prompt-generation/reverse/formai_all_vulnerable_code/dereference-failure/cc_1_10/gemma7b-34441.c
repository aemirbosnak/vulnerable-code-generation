//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int quantity) {
    Item* newNode = (Item*)malloc(sizeof(Item));
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

void updateQuantity(Item* head, char* name, int newQuantity) {
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

void printItems(Item* head) {
    Item* currentItem = head;

    while (currentItem) {
        printf("%s: %d\n", currentItem->name, currentItem->quantity);
        currentItem = currentItem->next;
    }
}

int main() {
    Item* head = NULL;

    addItem(head, "Apple", 10);
    addItem(head, "Banana", 5);
    addItem(head, "Orange", 7);

    printItems(head);

    updateQuantity(head, "Banana", 12);

    printItems(head);

    return 0;
}