//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    struct Item* next;
} Item;

Item* head = NULL;

void insertItem(char* name, int quantity) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void updateQuantity(char* name, int newQuantity) {
    Item* item = head;
    while (item) {
        if (strcmp(item->name, name) == 0) {
            item->quantity = newQuantity;
            return;
        }
        item = item->next;
    }
    printf("Item not found.\n");
}

void listItems() {
    Item* item = head;
    printf("Items:\n");
    while (item) {
        printf("%s - %d\n", item->name, item->quantity);
        item = item->next;
    }
}

int main() {
    insertItem("Romeo", 20);
    insertItem("Juliet", 10);
    insertItem("Mercutio", 5);
    insertItem("Benvolio", 2);

    updateQuantity("Romeo", 30);
    updateQuantity("Mercutio", 10);

    listItems();

    return 0;
}