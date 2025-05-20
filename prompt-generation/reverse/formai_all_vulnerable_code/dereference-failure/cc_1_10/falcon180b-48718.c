//Falcon-180B DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    Block *p = (void*)malloc(sizeof(Block) + 4096);
    p->size = 4096 - sizeof(Block);
    p->free = true;
    p->next = freeList;
    freeList = p;
}

void *myMalloc(size_t numBytes) {
    Block *p = freeList;
    while (p!= NULL) {
        if (p->size >= numBytes) {
            if (p->size == numBytes) {
                p = p->next;
            } else {
                Block *q = (void*)malloc(sizeof(Block) + numBytes);
                q->size = numBytes;
                q->free = false;
                q->next = p->next;
                p->size -= numBytes + sizeof(Block);
                p->next = q;
                return (void*)(p + 1);
            }
        } else {
            p = p->next;
        }
    }
    printf("No memory left!\n");
    return NULL;
}

void myFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    Block* blk = (Block*)ptr - 1;
    blk->free = true;
}

int main() {
    init();
    void* p1 = myMalloc(1024);
    printf("Allocated %d bytes at %p\n", 1024, p1);
    void* p2 = myMalloc(2048);
    printf("Allocated %d bytes at %p\n", 2048, p2);
    myFree(p1);
    printf("Freed %d bytes at %p\n", 1024, p1);
    void* p3 = myMalloc(4096);
    printf("Allocated %d bytes at %p\n", 4096, p3);
    myFree(p2);
    printf("Freed %d bytes at %p\n", 2048, p2);
    myFree(p3);
    printf("Freed %d bytes at %p\n", 4096, p3);
    return 0;
}