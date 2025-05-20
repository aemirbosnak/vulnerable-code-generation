//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LOCATION 20

typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

typedef struct Location {
    int number;
    Item* items;
    struct Location* next;
} Location;

Location* head = NULL;

void insertItem(char* name, int quantity) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        Item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

void locateItem(char* name) {
    Item* item = head;
    while (item) {
        if (strcmp(item->name, name) == 0) {
            printf("Item: %s, Quantity: %d\n", item->name, item->quantity);
            break;
        }
        item = item->next;
    }
    if (item == NULL) {
        printf("Item not found.\n");
    }
}

int main() {
    insertItem("Apple", 10);
    insertItem("Banana", 5);
    insertItem("Orange", 7);
    insertItem("Grape", 3);

    locateItem("Apple");
    locateItem("Banana");
    locateItem("Orange");
    locateItem("Grape");

    return 0;
}