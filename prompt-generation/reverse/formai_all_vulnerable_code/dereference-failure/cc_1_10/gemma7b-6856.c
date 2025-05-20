//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* InsertItem(Item* head) {
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

void PrintItems(Item* head) {
    while (head) {
        printf("%s - %d - %.2lf\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

int main() {
    Item* head = NULL;

    // Insert items
    head = InsertItem(head);
    head = InsertItem(head);
    head = InsertItem(head);

    // Print items
    PrintItems(head);

    return 0;
}