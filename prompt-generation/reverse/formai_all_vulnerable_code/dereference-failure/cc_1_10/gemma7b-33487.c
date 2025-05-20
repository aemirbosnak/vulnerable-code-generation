//Gemma-7B DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>

// Define a struct to store memory management information
typedef struct MemInfo {
    void* ptr;
    int size;
    struct MemInfo* next;
} MemInfo;

MemInfo* head = NULL;

void* alloc(int size) {
    MemInfo* newMem = malloc(sizeof(MemInfo) + size);
    newMem->size = size;
    newMem->ptr = (void*) ((char*)newMem + sizeof(MemInfo));
    newMem->next = NULL;

    if (head == NULL) {
        head = newMem;
    } else {
        head->next = newMem;
        head = newMem;
    }

    return newMem->ptr;
}

void free(void* ptr) {
    MemInfo* current = head;
    MemInfo* previous = NULL;

    while (current) {
        if (current->ptr == ptr) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    void* ptr = alloc(20);
    ptr = alloc(30);
    free(ptr);
    free(ptr);

    return 0;
}