//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 0xDEADBEEF

struct Node {
    int data;
    struct Node *next;
};

void* memAlloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        printf("Error: Could not allocate memory of size %zu\n", size);
        exit(EXIT_FAILURE);
    }
    // Add some magic to the memory
    *((int*)mem) = MAGIC_NUMBER;
    return mem;
}

void memFree(void* mem) {
    if (mem == NULL) {
        printf("Error: Trying to free null memory\n");
        return;
    }
    // Check if the memory has our magic number
    if (*((int*)mem) != MAGIC_NUMBER) {
        printf("Error: Memory is not ours\n");
        return;
    }
    // Free the memory
    free(mem);
}

int main() {
    // Allocate some memory
    void* mem = memAlloc(sizeof(struct Node));
    if (mem == NULL) {
        return 1;
    }
    // Create a node with some data
    struct Node* node = mem;
    node->data = 42;
    node->next = memAlloc(sizeof(struct Node));
    if (node->next == NULL) {
        memFree(mem);
        return 1;
    }
    // Add some more nodes
    node->next->data = 13;
    node->next->next = memAlloc(sizeof(struct Node));
    if (node->next->next == NULL) {
        memFree(mem);
        return 1;
    }
    node->next->next->data = 27;
    node->next->next->next = NULL;

    // Free the memory
    memFree(mem);

    return 0;
}