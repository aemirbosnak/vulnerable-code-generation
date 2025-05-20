//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell {
    int data;
    struct MemoryCell* next;
} MemoryCell;

void initializeMemory(MemoryCell** head) {
    *head = NULL;
}

void addToMemory(MemoryCell** head, int data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

int retrieveFromMemory(MemoryCell* head, int index) {
    MemoryCell* currentCell = head;
    int i = 0;

    for (i = 0; currentCell && i < index; i++) {
        currentCell = currentCell->next;
    }

    if (currentCell) {
        return currentCell->data;
    } else {
        return -1;
    }
}

int main() {
    MemoryCell* head = NULL;
    initializeMemory(&head);

    addToMemory(&head, 10);
    addToMemory(&head, 20);
    addToMemory(&head, 30);
    addToMemory(&head, 40);
    addToMemory(&head, 50);

    int retrievedData = retrieveFromMemory(head, 2);

    if (retrievedData != -1) {
        printf("Retrieved data: %d\n", retrievedData);
    } else {
        printf("Error retrieving data\n");
    }

    return 0;
}