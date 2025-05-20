//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1024 * 1024 // 1MB heap

// Linked list node structure
typedef struct node {
    size_t size; // Size of the allocated memory block
    int free; // Flag indicating whether this block is available or not
    struct node *next; // Pointer to the next node in the list
} Node;

Node *freeList = (void*)0; // Initialize free list to NULL

// Function to initialize our heap
void init() {
    char *heap = malloc(HEAP_SIZE);
    if (!heap) {
        printf("Failed to allocate heap\n");
        exit(1);
    }
    freeList = (Node*)heap; // Set the first node of the free list
    freeList->size = HEAP_SIZE - sizeof(Node);
    freeList->free = 1;
    freeList->next = NULL;
}

// Our custom memory allocation function (malloc)
void *myMalloc(size_t numBytes) {
    Node *curr = freeList;
    while (curr) {
        if (curr->size == numBytes && curr->free) {
            curr->free = 0;
            return (void*)(++curr);
        }
        curr = curr->next;
    }
    printf("Out of memory\n");
    return NULL;
}

// Our custom memory deallocation function (free)
void myFree(void *ptr) {
    if (ptr < (void*)freeList || ptr >= (void*)(freeList + HEAP_SIZE)) {
        printf("Invalid pointer\n");
        return;
    }
    Node *node = (Node*)ptr;
    --node;
    node->free = 1;
}

int main() {
    init();

    char *str1 = myMalloc(10);
    char *str2 = myMalloc(20);
    char *str3 = myMalloc(30);

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "How are you?");

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    myFree(str1);
    myFree(str2);
    myFree(str3);

    return 0;
}