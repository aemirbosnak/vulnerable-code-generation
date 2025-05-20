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

void addItem(Item** head, char* name, int quantity) {
    Item* newNode = malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void updateQuantity(Item* item, int newQuantity) {
    item->quantity = newQuantity;
}

void removeItem(Item** head, char* name) {
    Item* prev = NULL;
    Item* current = *head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

int main() {
    Item* head = NULL;

    addItem(&head, "Apple", 10);
    addItem(&head, "Banana", 20);
    addItem(&head, "Orange", 30);

    updateQuantity(head->next, 15);

    removeItem(&head, "Orange");

    for (Item* current = head; current; current = current->next) {
        printf("%s: %d\n", current->name, current->quantity);
    }

    return 0;
}