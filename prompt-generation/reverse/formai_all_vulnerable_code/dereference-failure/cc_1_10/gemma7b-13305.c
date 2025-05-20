//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct MemoryCell {
    int data;
    struct MemoryCell* next;
} MemoryCell;

void initialize(MemoryCell** head) {
    *head = NULL;
}

void insert(MemoryCell** head, int data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

void search(MemoryCell** head, int data) {
    MemoryCell* currentCell = *head;

    while (currentCell) {
        if (currentCell->data == data) {
            printf("Found!\n");
            return;
        } else {
            currentCell = currentCell->next;
        }
    }

    printf("Not found.\n");
}

int main() {
    MemoryCell* head = NULL;

    initialize(&head);
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    search(&head, 20);
    search(&head, 50);

    return 0;
}