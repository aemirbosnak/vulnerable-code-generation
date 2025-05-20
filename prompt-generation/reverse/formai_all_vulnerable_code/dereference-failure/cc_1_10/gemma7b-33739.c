//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct MemoryCell {
    int data;
    struct MemoryCell* next;
} MemoryCell;

void initialize(MemoryCell** head) {
    *head = NULL;
}

void insert(MemoryCell** head, int data) {
    MemoryCell* newCell = (MemoryCell*)malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

int search(MemoryCell* head, int data) {
    while (head) {
        if (head->data == data) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    MemoryCell* head = NULL;
    initialize(&head);

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    if (search(head, 30) == 1) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    return 0;
}