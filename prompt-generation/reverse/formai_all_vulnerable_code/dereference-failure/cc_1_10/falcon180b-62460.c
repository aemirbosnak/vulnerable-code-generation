//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    Block *p, *prev;
    char *bp;
    size_t i;

    for (i = 0; i < 1000000; i += 16) {
        if ((bp = malloc(16)) == NULL) {
            printf("Out of memory!\n");
            exit(1);
        }
        p = (void*)bp;
        p->size = 16;
        p->free = 1;
        p->next = freeList;
        freeList = p;
    }
}

void *myMalloc(size_t num) {
    Block *p, *prev;
    void *bp;

    if ((p = freeList) == NULL || p->size < num) {
        if ((bp = malloc(num)) == NULL) {
            printf("Out of memory!\n");
            exit(1);
        }
        p = (void*)bp;
        p->size = num;
        p->free = 0;
        p->next = freeList;
        freeList = p;
    } else {
        freeList = p->next;
        p->size = num;
        p->free = 0;
    }

    return (char*)p + sizeof(Block);
}

void myFree(void* ptr) {
    if (ptr == NULL)
        return;
    Block *p = (void*)ptr - sizeof(Block);
    p->free = 1;
    p->next = freeList;
    freeList = p;
}

int main() {
    int i;
    void *ptr;

    init();

    for (i = 0; i < 10; i++) {
        ptr = myMalloc(16);
        printf("Allocated block %d at %p\n", i, ptr);
    }

    for (i = 0; i < 10; i++) {
        myFree(ptr);
        ptr = myMalloc(16);
        printf("Reallocated block %d at %p\n", i, ptr);
    }

    return 0;
}