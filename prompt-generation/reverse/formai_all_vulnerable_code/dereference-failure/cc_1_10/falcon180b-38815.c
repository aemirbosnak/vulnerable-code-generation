//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 10000 // Size of the heap

// Node structure for linked list implementation of heap
typedef struct node {
    size_t size; // Size of the block
    int free; // Flag indicating whether this block is available or not
    struct node *next; // Pointer to the next block in the list
} Node;

Node *freeList = (void*)0; // Initialize free list to NULL

// Function to initialize the heap
void init() {
    freeList = (Node*)malloc(sizeof(Node)); // Allocate memory for the first node
    freeList->size = HEAP_SIZE - sizeof(Node);
    freeList->free = 1;
    freeList->next = (void*)0;
}

// Function to allocate memory from the heap
void *myMalloc(size_t numBytes) {
    Node *current = freeList;
    while (current!= NULL && current->size < numBytes) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }

    if (current->size == numBytes) {
        current->free = 0;
        return (void*)(++current);
    } else {
        Node *remainder = (void*)((void*)current + numBytes + sizeof(Node));
        remainder->size = current->size - numBytes - sizeof(Node);
        remainder->free = 1;
        remainder->next = current->next;
        current->size = numBytes;
        current->free = 0;
        return (void*)(++current);
    }
}

// Function to free memory back to the heap
void myFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Node* block = (Node*)ptr;
    --block;

    block->free = 1;

    Node* current = freeList;
    while (current->next!= NULL && current->next <= block) {
        current = current->next;
    }

    if (current->next == NULL) {
        current->next = block;
    } else {
        block->next = current->next;
        current->next = block;
    }
}

int main() {
    init();

    int* p1 = (int*)myMalloc(sizeof(int));
    *p1 = 10;

    int* p2 = (int*)myMalloc(sizeof(int));
    *p2 = 20;

    printf("%d %d\n", *p1, *p2);

    myFree(p1);
    myFree(p2);

    return 0;
}