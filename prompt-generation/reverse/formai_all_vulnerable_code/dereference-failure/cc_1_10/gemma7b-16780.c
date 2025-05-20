//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

void create_item(Item** head) {
    *head = (Item*)malloc(sizeof(Item));
    (*head)->name[0] = '\0';
    (*head)->quantity = 0;
    (*head)->next = NULL;
}

void add_item(Item** head, char name, int quantity) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    new_item->name[0] = '\0';
    new_item->quantity = quantity;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
        *head = new_item;
    }
}

int main() {
    Item* inventory = NULL;

    // Create and add items to the inventory
    create_item(&inventory);
    add_item(&inventory, "Sword", 1);
    add_item(&inventory, "Shield", 1);
    add_item(&inventory, "Potion", 2);

    // Use the items
    printf("You have %d items in your inventory:", inventory->quantity);
    printf("\n");

    for (Item* item = inventory; item; item = item->next) {
        printf("%s: %d\n", item->name, item->quantity);
    }

    return 0;
}