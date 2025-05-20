//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP_SIZE 1000

typedef struct node {
    size_t size;
    bool free;
    struct node *next;
} node_t;

node_t *free_list = (void*)0;
char heap[HEAP_SIZE];

void init() {
    free_list = (node_t*)heap;
    free_list->size = HEAP_SIZE - sizeof(node_t);
    free_list->free = true;
    free_list->next = (void*)0;
}

void *malloc(size_t num_bytes) {
    node_t *current = free_list;
    while (current->size < num_bytes && current->next!= NULL) {
        current = current->next;
    }

    if (current->size == num_bytes) {
        current->free = false;
        return (void*)(++current);
    } else if (current->size > num_bytes + sizeof(node_t)) {
        node_t *new_block = (void*)((char*)current + num_bytes + sizeof(node_t));
        new_block->size = current->size - num_bytes - sizeof(node_t);
        new_block->free = true;
        new_block->next = current->next;
        current->size = num_bytes;
        current->free = false;
        return (void*)(++current);
    }

    return NULL;
}

void free(void *ptr) {
    if (ptr >= heap && ptr < (char*)free_list + sizeof(node_t)) {
        node_t *current = (node_t*)ptr;
        --current;
        current->free = true;
    }
}

int main() {
    init();

    void *p1 = malloc(10);
    void *p2 = malloc(20);
    void *p3 = malloc(30);

    printf("Memory allocated successfully!\n");

    free(p1);
    free(p3);
    free(p2);

    return 0;
}