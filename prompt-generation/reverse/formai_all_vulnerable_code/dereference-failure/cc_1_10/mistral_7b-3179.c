//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define HEAP_SIZE (1024 * 1024)

typedef struct block {
    size_t size;
    struct block *next;
} block_t;

block_t *freelist = NULL;
char heap[HEAP_SIZE];

void *my_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    char *mem = malloc(total_size);

    if (!mem) {
        perror("Error allocating memory");
        return NULL;
    }

    memset(mem, 0, total_size);

    block_t *new_block = (block_t *) ((char *) mem + total_size);
    new_block->size = total_size;
    new_block->next = freelist;
    freelist = new_block;

    return (void *) mem;
}

void *my_malloc(size_t size) {
    char *ptr = malloc(size + sizeof(block_t));

    if (!ptr) {
        perror("Error allocating memory");
        return NULL;
    }

    block_t *new_block = (block_t *) ((char *) ptr + size);
    new_block->size = size;
    new_block->next = freelist;
    freelist = new_block;

    return (void *) ptr;
}

void my_free(void *ptr) {
    if (!ptr || freelist == NULL) {
        perror("Error freeing memory");
        return;
    }

    char *mem = (char *) ptr;
    block_t *prev = NULL;
    block_t *current = freelist;

    while (current != NULL) {
        if ((char *) current >= mem && ((char *) current <= mem + MAX_SIZE)) {
            if (prev == NULL) {
                freelist = current->next;
            } else {
                prev->next = current->next;
            }
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    int i;
    int *array;

    array = (int *) my_calloc(10, sizeof(int));

    for (i = 0; i < 10; i++) {
        array[i] = i * 2;
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    my_free(array);

    return 0;
}