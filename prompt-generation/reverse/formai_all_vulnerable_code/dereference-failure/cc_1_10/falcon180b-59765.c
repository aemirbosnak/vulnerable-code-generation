//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1000 // size of the heap

// node structure for linked list
typedef struct node {
    size_t size; // size of the block
    int free; // flag indicating whether this block is available or not
    struct node *next; // pointer to the next block in the list
} node_t;

// initialize the heap
void init_heap() {
    node_t *head = (void*)0; // start of the heap
    head->size = HEAP_SIZE - sizeof(node_t);
    head->free = 1;
    head->next = (void*)0;
}

// our custom malloc function
void *my_malloc(size_t num_bytes) {
    node_t *current = (node_t*)0; // start from the beginning of the heap
    while (current->size < num_bytes ||!current->free) {
        current = current->next;
        if (current == (void*)0) { // reached the end of the heap without finding a suitable block
            printf("Out of memory!\n");
            exit(1);
        }
    }

    current->free = 0; // mark the block as used
    return (void*)(++current); // return the address of the next node, since the current node is being used
}

// our custom free function
void my_free(void *ptr) {
    if (ptr == (void*)0) return; // do nothing if ptr is NULL

    node_t *current = (node_t*)ptr;
    current->free = 1; // mark the block as available
}

// example usage
int main() {
    init_heap();

    char *str1 = my_malloc(10); // allocate 10 bytes
    strcpy(str1, "Hello");

    char *str2 = my_malloc(20); // allocate 20 bytes
    strcpy(str2, "World!");

    printf("%s\n", str1); // prints "Hello"
    printf("%s\n", str2); // prints "World!"

    my_free(str1); // free the first block
    my_free(str2); // free the second block

    return 0;
}