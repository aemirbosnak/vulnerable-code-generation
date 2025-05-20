//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int value;
    struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int value) {
    Item* newNode = malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void GreedyAlgortihms(Item* head) {
    int totalValue = 0;
    Item* currentItem = head;

    while (currentItem) {
        int itemValue = currentItem->value;
        totalValue += itemValue;
        printf("%s has a value of %d\n", currentItem->name, itemValue);

        if (totalValue >= MAX_ITEMS * itemValue) {
            break;
        }

        currentItem = currentItem->next;
    }

    printf("Total value: %d\n", totalValue);
}

int main() {
    Item* head = insertItem(NULL, "Sword", 50);
    insertItem(head, "Shield", 20);
    insertItem(head, "Helmet", 30);
    insertItem(head, "Armor", 40);
    insertItem(head, "Magic Stone", 60);

    GreedyAlgortihms(head);

    return 0;
}