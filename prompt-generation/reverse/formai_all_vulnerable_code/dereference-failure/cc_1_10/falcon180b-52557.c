//Falcon-180B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    void *data;
    size_t size;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->data = (void*)0;
    freeList->size = 0;
}

void *myMalloc(size_t numBytes) {
    Block *p, *prev;
    void *victim;

    p = freeList;
    while ((((p->size) < numBytes) || ((p->size) == 0)) && (p!= freeList)) {
        prev = p;
        p = p->data;
    }

    if ((p->size) == numBytes) {
        victim = p;
        p = (Block*)((char*)p + numBytes + sizeof(size_t));
        p->size = 0;
    } else if ((p->size) > (numBytes + sizeof(size_t))) {
        victim = (char*)p + numBytes + sizeof(size_t);
        p->size = numBytes;
    } else {
        victim = 0;
    }

    if (victim!= 0) {
        memset(victim, 0, p->size - numBytes);
        p->data = victim;
    } else {
        p->data = (void*)0;
    }

    return (void*)((char*)p + sizeof(size_t));
}

void myFree(void* ptr) {
    if (ptr!= 0) {
        Block *p = (Block*)ptr;
        p = (Block*)((char*)p - sizeof(size_t));

        p->data = (void*)0;
        p->size = 0;

        Block *q = freeList;
        while ((q->data!= p) && (q!= freeList)) {
            q = q->data;
        }

        if (q!= freeList) {
            q->data = p;
        } else {
            freeList = p;
        }
    }
}

int main() {
    init();

    char* str1 = (char*)myMalloc(10);
    strcpy(str1, "Hello");
    printf("str1: %s\n", str1);

    char* str2 = (char*)myMalloc(15);
    strcpy(str2, "World!");
    printf("str2: %s\n", str2);

    myFree(str1);
    myFree(str2);

    return 0;
}