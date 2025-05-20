//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP_SIZE 1000000 // size of the heap
#define HEAP_START (void*)0x10000000 // starting address of the heap

typedef struct block {
    size_t size;
    int free;
    struct block* next;
} block_t;

void* my_malloc(size_t num_bytes) {
    block_t* current = (block_t*)HEAP_START;
    while (current < (void*)0x20000000) { // heap ends at 0x20000000
        if (current->size == num_bytes &&!current->free) {
            current->free = true;
            return (void*)((int)current + sizeof(block_t));
        }
        current = current->next;
    }
    return NULL;
}

void my_free(void* ptr) {
    block_t* current = (block_t*)HEAP_START;
    while (current < (void*)0x20000000) {
        if (current->size == ((int)ptr - (int)current - sizeof(block_t))) {
            current->free = false;
            break;
        }
        current = current->next;
    }
}

int main() {
    void* ptr1 = my_malloc(10);
    void* ptr2 = my_malloc(20);
    void* ptr3 = my_malloc(30);

    printf("ptr1: %p\n", ptr1);
    printf("ptr2: %p\n", ptr2);
    printf("ptr3: %p\n", ptr3);

    my_free(ptr2);

    printf("ptr2 after free: %p\n", ptr2);

    return 0;
}