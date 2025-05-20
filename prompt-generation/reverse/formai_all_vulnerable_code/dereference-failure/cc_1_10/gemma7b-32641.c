//Gemma-7B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct MemoryManager {
    Node* head;
    int size;
    int alloc_size;
} MemoryManager;

MemoryManager* mm_init(int size) {
    MemoryManager* mm = (MemoryManager*)malloc(sizeof(MemoryManager));
    mm->head = NULL;
    mm->size = size;
    mm->alloc_size = 0;
    return mm;
}

void mm_insert(MemoryManager* mm, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (mm->head == NULL) {
        mm->head = newNode;
    } else {
        mm->head->next = newNode;
        mm->head = newNode;
    }

    mm->alloc_size++;
}

void mm_print(MemoryManager* mm) {
    Node* current = mm->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    MemoryManager* mm = mm_init(MAX_SIZE);

    mm_insert(mm, 10);
    mm_insert(mm, 20);
    mm_insert(mm, 30);
    mm_insert(mm, 40);

    mm_print(mm);

    mm_insert(mm, 50);

    mm_print(mm);

    return 0;
}