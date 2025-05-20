//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 1000
#define MAX_BLOCK_SIZE 100

typedef struct block {
    size_t size;
    char data[MAX_BLOCK_SIZE];
    struct block *next;
} block_t;

block_t *free_list = NULL;

void init() {
    free_list = (block_t*)malloc(sizeof(block_t));
    free_list->size = 0;
    free_list->next = NULL;
}

void *my_malloc(size_t size) {
    block_t *current = free_list;
    while (current!= NULL && current->size < size) {
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }

    if (current->size == size) {
        block_t *temp = current->next;
        current->next = NULL;
        return current->data;
    } else if (current->size > size) {
        block_t *temp = (block_t*)malloc(sizeof(block_t));
        temp->size = current->size - size;
        temp->next = current->next;
        current->size = size;
        current->next = temp;
        return (void*)((char*)current->data + size);
    }

    return NULL;
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    block_t *current = free_list;
    while (current->next!= NULL && current->next!= ptr) {
        current = current->next;
    }

    if (current->next == NULL) {
        fprintf(stderr, "Invalid pointer!\n");
        exit(1);
    }

    current->next = current->next->next;
}

int main() {
    init();

    void *ptr1 = my_malloc(50);
    void *ptr2 = my_malloc(100);
    void *ptr3 = my_malloc(25);

    memset(ptr1, 'A', 50);
    memset(ptr2, 'B', 100);
    memset(ptr3, 'C', 25);

    printf("Ptr1: %s\n", (char*)ptr1);
    printf("Ptr2: %s\n", (char*)ptr2);
    printf("Ptr3: %s\n", (char*)ptr3);

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    return 0;
}