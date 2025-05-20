//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    struct item *next;
} Item;

void addItem(Item **list, char *name, int quantity) {
    Item *newItem = (Item *)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (*list == NULL) {
        *list = newItem;
    } else {
        Item *curr = *list;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = newItem;
    }
}

void printList(Item *list) {
    while (list!= NULL) {
        printf("%s - %d\n", list->name, list->quantity);
        list = list->next;
    }
}

void deleteItem(Item **list, char *name) {
    Item *curr = *list;
    Item *prev = NULL;

    while (curr!= NULL && strcmp(curr->name, name)!= 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Item not found.\n");
    } else {
        if (prev == NULL) {
            *list = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void updateQuantity(Item **list, char *name, int quantity) {
    Item *curr = *list;

    while (curr!= NULL && strcmp(curr->name, name)!= 0) {
        curr = curr->next;
    }

    if (curr!= NULL) {
        curr->quantity = quantity;
    } else {
        printf("Item not found.\n");
    }
}

int main() {
    Item *list = NULL;

    addItem(&list, "Apples", 50);
    addItem(&list, "Oranges", 30);
    addItem(&list, "Bananas", 20);

    printList(list);

    deleteItem(&list, "Oranges");

    printList(list);

    updateQuantity(&list, "Apples", 60);

    printList(list);

    return 0;
}