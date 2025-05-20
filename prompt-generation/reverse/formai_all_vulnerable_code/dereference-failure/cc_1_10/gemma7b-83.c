//Gemma-7B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct MemoryCell {
    struct MemoryCell* next;
    void* data;
} MemoryCell;

MemoryCell* head = NULL;

void allocateMemory(int size) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell) + size);
    newCell->next = head;
    head = newCell;
    newCell->data = (void*) ((char*)newCell + sizeof(MemoryCell));
}

void freeMemory(void* ptr) {
    MemoryCell* currentCell = head;
    MemoryCell* previousCell = NULL;

    while (currentCell) {
        if (currentCell->data == ptr) {
            if (previousCell) {
                previousCell->next = currentCell->next;
            } else {
                head = currentCell->next;
            }
            free(currentCell);
            return;
        }

        previousCell = currentCell;
        currentCell = currentCell->next;
    }

    printf("Error: Memory pointer not found.\n");
}

int main() {
    allocateMemory(10);
    allocateMemory(20);
    allocateMemory(30);

    freeMemory((void*) (head->data));

    return 0;
}