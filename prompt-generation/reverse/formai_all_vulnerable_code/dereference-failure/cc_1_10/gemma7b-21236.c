//Gemma-7B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct MemoryBlock {
    struct MemoryBlock* next;
    void* data;
    int size;
} MemoryBlock;

MemoryBlock* head = NULL;

void* alloc(int size) {
    if (head == NULL) {
        head = (MemoryBlock*)malloc(sizeof(MemoryBlock));
        head->next = NULL;
        head->data = (void*)malloc(size);
        head->size = size;
    } else {
        MemoryBlock* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = (MemoryBlock*)malloc(sizeof(MemoryBlock));
        current->next->next = NULL;
        current->next->data = (void*)malloc(size);
        current->next->size = size;
    }

    return head->data;
}

void free(void* ptr) {
    MemoryBlock* current = head;
    MemoryBlock* previous = NULL;

    while (current) {
        if (current->data == ptr) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    alloc(20);
    alloc(30);
    alloc(10);
    free(alloc(20));
    free(alloc(30));

    return 0;
}