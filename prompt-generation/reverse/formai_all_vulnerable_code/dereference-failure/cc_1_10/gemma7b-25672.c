//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* createItem(char* name, int quantity) {
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

void addItem(Item* head, char* name, int quantity) {
    Item* item = createItem(name, quantity);
    if (head == NULL) {
        head = item;
    } else {
        item->next = head;
        head = item;
    }
}

int getItemQuantity(Item* head, char* name) {
    Item* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->name, name) == 0) {
            return currentItem->quantity;
        }
        currentItem = currentItem->next;
    }
    return -1;
}

void paranoia(Item* head) {
    Item* currentItem = head;
    while (currentItem) {
        free(currentItem);
        currentItem = currentItem->next;
    }
    head = NULL;
}

int main() {
    Item* head = NULL;
    addItem(head, "Paranoia Pills", 10);
    addItem(head, "C4R Doomsday Device", 5);
    addItem(head, "Fake News", 2);
    addItem(head, "Anti-Gravity Boots", 3);

    int quantity = getItemQuantity(head, "Paranoia Pills");
    printf("Quantity of Paranoia Pills: %d\n", quantity);

    paranoia(head);
    quantity = getItemQuantity(head, "Paranoia Pills");
    printf("Quantity of Paranoia Pills after paranoia: %d\n", quantity);

    return 0;
}