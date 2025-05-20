//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    struct Item* next;
} Item;

void insertItem(Item** head, int value) {
    Item* newNode = malloc(sizeof(Item));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void greedyAlgorithm(Item* head) {
    Item* currentItem = head;
    Item* previousItem = NULL;
    int totalValue = 0;

    while (currentItem) {
        int currentItemValue = currentItem->value;

        if (previousItem && currentItemValue < previousItem->value) {
            insertItem(&previousItem, currentItemValue);
            totalValue -= currentItemValue;
        } else {
            previousItem = currentItem;
            totalValue += currentItemValue;
        }
    }

    printf("Total value: %d\n", totalValue);
}

int main() {
    Item* head = NULL;
    insertItem(&head, 10);
    insertItem(&head, 20);
    insertItem(&head, 30);
    insertItem(&head, 40);
    insertItem(&head, 50);

    greedyAlgorithm(head);

    return 0;
}