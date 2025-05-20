//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 5

typedef struct MemoryCell {
    char data;
    struct MemoryCell* next;
} MemoryCell;

MemoryCell* initializeMemory() {
    MemoryCell* head = malloc(sizeof(MemoryCell));
    head->data = '\0';
    head->next = NULL;
    return head;
}

void insertIntoMemory(MemoryCell* head, char data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (head->next == NULL) {
        head->next = newCell;
    } else {
        head->next->next = newCell;
    }
}

int retrieveFromMemory(MemoryCell* head, char key) {
    for (MemoryCell* currentCell = head->next; currentCell; currentCell = currentCell->next) {
        if (currentCell->data == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    MemoryCell* memory = initializeMemory();
    insertIntoMemory(memory, 'a');
    insertIntoMemory(memory, 'b');
    insertIntoMemory(memory, 'c');

    if (retrieveFromMemory(memory, 'b')) {
        printf("b is in the memory\n");
    }

    return 0;
}