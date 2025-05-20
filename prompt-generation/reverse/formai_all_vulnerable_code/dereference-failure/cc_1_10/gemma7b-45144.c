//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* head = NULL;

void addItem(char* name, int quantity) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        Item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

void removeItem(char* name) {
    Item* prev = NULL;
    Item* current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Item not found.\n");
}

void listItems() {
    Item* current = head;

    printf("Items:\n");
    while (current) {
        printf("%s - %d\n", current->name, current->quantity);
        current = current->next;
    }
}

int main() {
    addItem("Test Item 1", 10);
    addItem("Test Item 2", 20);
    addItem("Test Item 3", 30);

    listItems();

    removeItem("Test Item 2");

    listItems();

    return 0;
}