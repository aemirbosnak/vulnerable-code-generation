//Falcon-180B DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 100000 // size of the heap

// node structure for linked list implementation of heap
typedef struct node {
    size_t size;
    int free;
    struct node *next;
} Node;

Node *freeList = (void*)0; // initialize free list to NULL

// function to initialize the heap
void init() {
    freeList = (Node*)malloc(sizeof(Node)); // allocate first node
    freeList->size = HEAP_SIZE - sizeof(Node);
    freeList->free = 1;
    freeList->next = (void*)0;
}

// function to allocate memory from the heap
void *myMalloc(size_t numBytes) {
    Node *current = freeList;
    while ((current->size < numBytes) && (current->next!= NULL)) {
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = 0;
        return (void*)(++current);
    } else {
        return NULL;
    }
}

// function to free memory back to the heap
void myFree(void* ptr) {
    if (ptr!= NULL) {
        Node* block = (Node*)ptr;
        --block;
        block->free = 1;
    }
}

int main() {
    char* msg = (char*)myMalloc(50);
    if (msg!= NULL) {
        strcpy(msg, "Hello, post-apocalyptic world!");
        printf("%s\n", msg);
        myFree(msg);
    }

    return 0;
}