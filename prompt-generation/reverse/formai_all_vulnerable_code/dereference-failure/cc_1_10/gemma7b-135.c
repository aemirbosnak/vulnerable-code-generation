//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[20];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* InsertItem(Item* head, char* name, int quantity, double price) {
    Item* newNode = (Item*)malloc(sizeof(Item));

    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void PrintInventory(Item* head) {
    Item* current = head;

    printf("Inventory:\n");
    while (current) {
        printf("%s: %d @ %.2lf\n", current->name, current->quantity, current->price);
        current = current->next;
    }
}

int main() {
    Item* head = NULL;

    InsertItem(head, "Apple", 10, 1.20);
    InsertItem(head, "Banana", 20, 1.50);
    InsertItem(head, "Orange", 15, 1.70);
    InsertItem(head, "Mango", 25, 1.90);

    PrintInventory(head);

    return 0;
}