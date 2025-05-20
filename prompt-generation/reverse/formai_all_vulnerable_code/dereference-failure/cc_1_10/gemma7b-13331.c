//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

Item* InsertItem(Item* head, char* name, int quantity, float price) {
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
    Item* currentItem = head;
    while (currentItem) {
        printf("%s: %d, £%.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }
}

int main() {
    Item* head = NULL;

    // Insert some items
    InsertItem(head, "A Pocket Watch", 3, 200.0);
    InsertItem(head, "A Silver Chain", 2, 150.0);
    InsertItem(head, "A Diamond Ring", 1, 500.0);

    // Print the inventory
    PrintInventory(head);

    return 0;
}