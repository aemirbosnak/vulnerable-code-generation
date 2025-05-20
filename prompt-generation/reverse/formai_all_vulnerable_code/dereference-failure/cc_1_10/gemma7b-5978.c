//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* insertItem(Item* head) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    scanf("Enter item name: ", newNode->name);
    scanf("Enter item quantity: ", &newNode->quantity);
    scanf("Enter item price: ", &newNode->price);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void printItems(Item* head) {
    while (head) {
        printf("%s - %d - %.2lf\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

int main() {
    Item* head = NULL;

    printf("Welcome to the C Warehouse Management System!\n");

    // Insert items
    insertItem(head);
    insertItem(head);
    insertItem(head);

    // Print items
    printItems(head);

    return 0;
}