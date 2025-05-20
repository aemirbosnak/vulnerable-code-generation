//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryItem {
    char data[MAX_MEMORY_SIZE];
    struct MemoryItem* next;
} MemoryItem;

void initMemoryGame(MemoryItem** head) {
    *head = NULL;
    srand(time(NULL));
}

void addMemoryItem(MemoryItem** head, char* item) {
    MemoryItem* newNode = (MemoryItem*)malloc(sizeof(MemoryItem));
    memcpy(newNode->data, item, MAX_MEMORY_SIZE);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int guessMemoryItem(MemoryItem* head, char* item) {
    while (head) {
        if (strcmp(head->data, item) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    MemoryItem* head = NULL;

    initMemoryGame(&head);

    char* item1 = "apple";
    addMemoryItem(&head, item1);

    char* item2 = "banana";
    addMemoryItem(&head, item2);

    char* item3 = "orange";
    addMemoryItem(&head, item3);

    if (guessMemoryItem(head, item2) == 1) {
        printf("Item found: %s\n", item2);
    } else {
        printf("Item not found: %s\n", item2);
    }

    return 0;
}