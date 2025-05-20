//Falcon-180B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the memory block

struct Block {
    int size; // size of the block
    int free; // flag indicating whether the block is free or not
    struct Block *next; // pointer to the next block
};

void init() {
    struct Block *p = (void*)0; // initialize the first block
    p->size = MAX_SIZE;
    p->free = 1;
    p->next = (void*)0;
}

void *my_malloc(int size) {
    struct Block *p = (void*)0; // start from the first block
    while ((p->size < size) || (p->free == 0)) {
        p = p->next; // move to the next block
    }
    if (p->size == size) {
        p->free = 0; // mark the block as used
    } else {
        struct Block *q = (void*)malloc(size); // allocate a new block
        memcpy(q, p, sizeof(struct Block)); // copy the header
        q->size = size;
        p->size -= size;
        p->free = 1;
        q->next = p->next;
        p->next = q;
    }
    return (void*)(++p); // return the pointer to the allocated block
}

void my_free(void *ptr) {
    if (ptr == (void*)0) return; // do nothing if ptr is null
    struct Block *p = (void*)ptr - sizeof(struct Block); // get the header of the block
    p->free = 1; // mark the block as free
}

int main() {
    init(); // initialize the memory manager
    void *p1 = my_malloc(100); // allocate 100 bytes
    void *p2 = my_malloc(200); // allocate 200 bytes
    void *p3 = my_malloc(300); // allocate 300 bytes
    my_free(p2); // free 200 bytes
    printf("%d\n", my_malloc(400)); // allocate 400 bytes
    return 0;
}