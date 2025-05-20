//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block_t;

void init(void) {
    block_t *head = (void*)0x100000;
    head->size = 0xfffff - sizeof(block_t);
    head->free = 1;
    head->next = NULL;
}

void *malloc(size_t size) {
    block_t *head = (void*)0x100000;
    block_t *cur = head;
    while (cur!= NULL) {
        if (cur->size == size && cur->free) {
            cur->free = 0;
            return (void*)(cur + 1);
        }
        cur = cur->next;
    }
    return NULL;
}

void free(void *ptr) {
    block_t *head = (void*)0x100000;
    block_t *cur = head;
    while (cur!= NULL) {
        if ((void*)cur == ptr) {
            cur->free = 1;
            return;
        }
        cur = cur->next;
    }
}

int main() {
    int i;
    void *ptr;
    init();
    for (i = 0; i < 10; i++) {
        ptr = malloc(i * sizeof(int));
        if (ptr!= NULL) {
            printf("Allocated %d bytes at %p\n", i * sizeof(int), ptr);
        } else {
            printf("Failed to allocate %d bytes\n", i * sizeof(int));
        }
    }
    for (i = 0; i < 10; i++) {
        free(malloc(i * sizeof(int)));
    }
    return 0;
}