//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Item {
    int item_id;
    int quantity;
    struct Item* next;
} Item;

void insertItem(Item* head, int item_id, int quantity) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    newNode->item_id = item_id;
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Item* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

int main() {
    Item* head = NULL;

    // Simulate post-apocalyptic scavenging
    insertItem(head, 1, 5);
    insertItem(head, 2, 3);
    insertItem(head, 3, 2);
    insertItem(head, 4, 4);

    // Greedy Algorithm - take as much as you can from the first item
    Item* currentItem = head;
    int totalQuantity = 0;
    while (currentItem) {
        int itemQuantity = currentItem->quantity;
        if (itemQuantity > totalQuantity) {
            totalQuantity = itemQuantity;
        }
        currentItem = currentItem->next;
    }

    // Display the total quantity
    printf("Total quantity taken: %d\n", totalQuantity);

    return 0;
}