//Gemma-7B DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_DESCRIPTION_LENGTH 1024

typedef struct Item {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    struct Item* next;
} Item;

Item* addItem(Item* head, char* name, char* description, int quantity) {
    Item* newNode = malloc(sizeof(Item));
    strcpy(newNode->name, name);
    strcpy(newNode->description, description);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Item* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void listItems(Item* head) {
    Item* current = head;
    while (current) {
        printf("%s - %s (Q: %d)\n", current->name, current->description, current->quantity);
        current = current->next;
    }
}

int main() {
    Item* head = NULL;

    addItem(head, "Water", "The most precious resource in the post-apocalypse.", 10);
    addItem(head, "Food", "A scarce resource, but essential for survival.", 5);
    addItem(head, "Weapons", "For protection against raiders.", 2);

    listItems(head);

    return 0;
}