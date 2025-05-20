//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int quantity) {
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

int searchItem(Item* head, char* name) {
    Item* current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->quantity;
        }

        current = current->next;
    }

    return -1;
}

int main() {
    Item* head = NULL;

    insertItem(head, "Sword", 10);
    insertItem(head, "Shield", 5);
    insertItem(head, "Potion", 2);
    insertItem(head, "Bow", 3);
    insertItem(head, "Arrows", 15);

    int quantity = searchItem(head, "Potion");

    if (quantity == -1) {
        printf("Item not found.\n");
    } else {
        printf("Quantity of item: %d\n", quantity);
    }

    return 0;
}