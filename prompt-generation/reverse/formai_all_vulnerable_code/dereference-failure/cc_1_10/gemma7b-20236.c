//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int getRandomMemoryCell(MemoryCell* head) {
    srand(time(NULL));
    int index = rand() % MAX_MEMORY_SIZE;
    MemoryCell* currentCell = head;

    for (int i = 0; i < index; i++) {
        currentCell = currentCell->next;
    }

    return currentCell->data;
}

int main() {
    MemoryCell* head = NULL;
    initializeMemory(&head);

    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        addToMemory(&head, i + 1);
    }

    int guessNumber = getRandomMemoryCell(head);

    printf("The guess number is: %d\n", guessNumber);

    return 0;
}