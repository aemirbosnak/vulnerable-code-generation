//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

void createItem(Item** head) {
    *head = (Item*)malloc(sizeof(Item));
    (*head)->name[0] = '\0';
    (*head)->quantity = 0;
    (*head)->next = NULL;
}

void addItem(Item** head, char name, int quantity) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    newItem->name[0] = '\0';
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

void showItems(Item* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->quantity);
        head = head->next;
    }
}

int main() {
    Item* inventory = NULL;
    createItem(&inventory);

    addItem(inventory, "Sword", 1);
    addItem(inventory, "Shield", 1);
    addItem(inventory, "Potion", 5);

    showItems(inventory);

    return 0;
}