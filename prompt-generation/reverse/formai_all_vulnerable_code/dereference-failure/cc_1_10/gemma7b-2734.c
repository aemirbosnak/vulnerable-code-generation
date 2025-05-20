//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    int value;
    struct Item* next;
} Item;

Item* insertItem(Item* head, int value) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void greedyAlgorithm(Item* head) {
    Item* currentItem = head;
    int totalValue = 0;
    int i = 0;

    while (currentItem) {
        totalValue += currentItem->value;
        i++;

        if (i % MAX_ITEMS == 0) {
            printf("Iteration %d: Total Value: %d\n", i, totalValue);
            totalValue = 0;
        }

        currentItem = currentItem->next;
    }

    printf("Final Total Value: %d\n", totalValue);
}

int main() {
    Item* head = NULL;
    insertItem(head, 10);
    insertItem(head, 20);
    insertItem(head, 30);
    insertItem(head, 40);
    insertItem(head, 50);
    insertItem(head, 60);

    greedyAlgorithm(head);

    return 0;
}