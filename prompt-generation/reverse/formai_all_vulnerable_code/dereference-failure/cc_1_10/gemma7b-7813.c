//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY 10

typedef struct MemoryItem {
    char data;
    struct MemoryItem* next;
} MemoryItem;

void initializeMemory(MemoryItem** head) {
    *head = NULL;
}

void addToMemory(MemoryItem** head, char data) {
    MemoryItem* newNode = malloc(sizeof(MemoryItem));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int searchMemory(MemoryItem** head, char data) {
    MemoryItem* current = *head;

    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    MemoryItem* head = NULL;
    initializeMemory(&head);

    // Simulate adding items to the memory
    addToMemory(&head, 'a');
    addToMemory(&head, 'b');
    addToMemory(&head, 'c');
    addToMemory(&head, 'd');

    // Simulate searching for items in the memory
    if (searchMemory(&head, 'b')) {
        printf("Item found!\n");
    } else {
        printf("Item not found.\n");
    }

    return 0;
}