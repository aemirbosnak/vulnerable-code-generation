//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct MemoryCell {
    int data;
    struct MemoryCell* next;
} MemoryCell;

MemoryCell* head = NULL;

void addToMemory(int data) {
    MemoryCell* newCell = (MemoryCell*)malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (head == NULL) {
        head = newCell;
    } else {
        head->next = newCell;
        head = newCell;
    }
}

void readMemory(int address) {
    MemoryCell* currentCell = head;

    while (currentCell && currentCell->data != address) {
        currentCell = currentCell->next;
    }

    if (currentCell) {
        printf("Read: %d\n", currentCell->data);
    } else {
        printf("Error: Address not found.\n");
    }
}

int main() {
    addToMemory(10);
    addToMemory(20);
    addToMemory(30);
    addToMemory(40);

    readMemory(20);
    readMemory(50);

    return 0;
}