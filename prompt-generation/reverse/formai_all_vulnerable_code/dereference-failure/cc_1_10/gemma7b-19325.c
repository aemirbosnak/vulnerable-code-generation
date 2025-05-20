//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct MemoryCell {
    int data;
    struct MemoryCell* next;
} MemoryCell;

MemoryCell* CreateMemory(int size) {
    MemoryCell* head = malloc(sizeof(MemoryCell) * size);
    head->next = NULL;
    return head;
}

void InsertMemory(MemoryCell* head, int data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (head) {
        head->next = newCell;
    } else {
        head = newCell;
    }
}

int RetrieveMemory(MemoryCell* head, int index) {
    MemoryCell* currentCell = head;
    int i = 0;

    while (currentCell && i < index) {
        currentCell = currentCell->next;
        i++;
    }

    return currentCell->data;
}

int main() {
    MemoryCell* memory = CreateMemory(MAX_MEMORY);

    InsertMemory(memory, 10);
    InsertMemory(memory, 20);
    InsertMemory(memory, 30);
    InsertMemory(memory, 40);

    printf("Data at index 2: %d\n", RetrieveMemory(memory, 2));

    return 0;
}