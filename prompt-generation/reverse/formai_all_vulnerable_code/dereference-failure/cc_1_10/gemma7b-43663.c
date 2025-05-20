//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 5

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

    if (head == NULL) {
        head = newCell;
    } else {
        head->next = newCell;
    }
}

int retrieveMemory(MemoryCell* head, int index) {
    MemoryCell* currentCell = head;
    int i = 0;

    for (i = 0; currentCell && i < index; i++) {
        currentCell = currentCell->next;
    }

    if (currentCell) {
        return currentCell->value;
    } else {
        return -1;
    }
}

int main() {
    MemoryCell* memory = createMemory(MAX_MEMORY);

    insertMemory(memory, 10);
    insertMemory(memory, 20);
    insertMemory(memory, 30);
    insertMemory(memory, 40);
    insertMemory(memory, 50);

    int retrievedValue = retrieveMemory(memory, 2);

    if (retrievedValue != -1) {
        printf("Retrieved value: %d\n", retrievedValue);
    } else {
        printf("Error retrieving value\n");
    }

    return 0;
}