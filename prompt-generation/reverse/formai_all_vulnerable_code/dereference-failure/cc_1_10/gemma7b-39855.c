//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell {
    int value;
    struct MemoryCell* next;
} MemoryCell;

MemoryCell* createMemory(int size) {
    MemoryCell* head = malloc(sizeof(MemoryCell) * size);
    head->next = NULL;

    return head;
}

void insertMemory(MemoryCell* head, int value) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->value = value;
    newCell->next = NULL;

    if (head) {
        head->next = newCell;
    } else {
        head = newCell;
    }

    return;
}

int retrieveMemory(MemoryCell* head, int index) {
    MemoryCell* currentCell = head;
    for (int i = 0; i < index; i++) {
        currentCell = currentCell->next;
    }

    return currentCell->value;
}

int main() {
    srand(time(NULL));

    MemoryCell* memory = createMemory(MAX_MEMORY_SIZE);

    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        insertMemory(memory, rand() % 10);
    }

    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        printf("Value at index %d: %d\n", i, retrieveMemory(memory, i));
    }

    return 0;
}