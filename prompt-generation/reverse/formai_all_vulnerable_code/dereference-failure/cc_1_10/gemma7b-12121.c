//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Item {
    char name[MAX_SIZE];
    int quantity;
    struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int quantity) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void greedyAlgo(Item* head) {
    Item* currentItem = head;
    int totalQuantity = 0;
    char* currentItemNames[MAX_SIZE];

    while (currentItem) {
        int currentItemQuantity = currentItem->quantity;
        int i = 0;

        for (; i < currentItemQuantity && totalQuantity < 100; i++) {
            strcpy(currentItemNames[i], currentItem->name);
            totalQuantity++;
        }

        currentItem->quantity -= i;
        currentItem = currentItem->next;
    }

    printf("Total Quantity: %d\n", totalQuantity);
    printf("Items selected: ");

    for (int i = 0; i < totalQuantity; i++) {
        printf("%s, ", currentItemNames[i]);
    }

    printf("\n");
}

int main() {
    Item* head = NULL;

    insertItem(head, "A", 20);
    insertItem(head, "B", 10);
    insertItem(head, "C", 15);
    insertItem(head, "D", 5);

    greedyAlgo(head);

    return 0;
}