//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell {
    int value;
    struct MemoryCell* next;
} MemoryCell;

void initializeMemory(MemoryCell** head) {
    *head = NULL;
}

void insertMemoryCell(MemoryCell** head, int value) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->value = value;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

int searchMemory(MemoryCell* head, int value) {
    while (head) {
        if (head->value == value) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    MemoryCell* head = NULL;
    initializeMemory(&head);

    insertMemoryCell(&head, 10);
    insertMemoryCell(&head, 20);
    insertMemoryCell(&head, 30);
    insertMemoryCell(&head, 40);

    if (searchMemory(head, 30) == 1) {
        printf("The value 30 is found.\n");
    } else {
        printf("The value 30 is not found.\n");
    }

    return 0;
}