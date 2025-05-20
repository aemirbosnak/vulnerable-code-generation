//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[256];
    int quantity;
    struct Item* next;
} Item;

Item* item_insert(Item* head, char* name, int quantity) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        Item* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_item;
    }

    return head;
}

void item_delete(Item* head, char* name) {
    Item* current = head;
    Item* previous = NULL;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    Item* head = NULL;

    // Insert items
    item_insert(head, "Paranoia Pills", 20);
    item_insert(head, "Tinfoil Hats", 10);
    item_insert(head, "Tin Foil", 5);

    // Delete items
    item_delete(head, "Tinfoil Hats");

    // Print items
    Item* current = head;
    while (current) {
        printf("%s - %d\n", current->name, current->quantity);
        current = current->next;
    }

    return 0;
}