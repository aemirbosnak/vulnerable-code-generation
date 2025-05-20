//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 1024

typedef struct MemoryCell {
    struct MemoryCell* next;
    int data;
} MemoryCell;

MemoryCell* createMemoryCell(int data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->next = NULL;
    newCell->data = data;
    return newCell;
}

void insertMemoryCell(MemoryCell* head, int data) {
    MemoryCell* newCell = createMemoryCell(data);
    if (head == NULL) {
        head = newCell;
    } else {
        head->next = newCell;
        head = newCell;
    }
}

void findMemoryCell(MemoryCell* head, int data) {
    while (head) {
        if (head->data == data) {
            printf("Data found: %d\n", data);
            return;
        }
        head = head->next;
    }
    printf("Data not found: %d\n", data);
}

int main() {
    MemoryCell* head = NULL;
    insertMemoryCell(head, 10);
    insertMemoryCell(head, 20);
    insertMemoryCell(head, 30);
    insertMemoryCell(head, 40);

    findMemoryCell(head, 20);
    findMemoryCell(head, 50);

    return 0;
}