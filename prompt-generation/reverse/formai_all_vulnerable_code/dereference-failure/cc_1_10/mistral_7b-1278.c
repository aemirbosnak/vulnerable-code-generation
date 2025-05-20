//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 128
#define HEAP_SIZE 1024

typedef struct Block {
    size_t size;
    struct Block *next;
} Block;

Block *heap = NULL;
size_t heap_top = 0;

void *my_malloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Error: Invalid size\n");
        return NULL;
    }

    if (heap_top + size > HEAP_SIZE) {
        fprintf(stderr, "Error: Not enough memory\n");
        return NULL;
    }

    Block *new_block = (Block *)((char *)heap + heap_top);
    new_block->size = size;
    new_block->next = NULL;

    heap_top += size;

    return (void *)((char *)new_block + sizeof(Block));
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: Invalid pointer\n");
        return;
    }

    Block *current = heap;
    Block *prev = NULL;

    while (current != NULL) {
        if ((char *)current + sizeof(Block) == ptr) {
            if (prev == NULL) {
                heap = current->next;
            } else {
                prev->next = current->next;
            }

            heap_top -= current->size;
            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
}

int main() {
    int *a = (int *)my_malloc(sizeof(int) * 10);
    int *b = (int *)my_malloc(sizeof(int) * 20);

    if (a == NULL || b == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        my_free(a);
        if (a != b) {
            my_free(b);
        }
        return 1;
    }

    for (size_t i = 0; i < 10; i++) {
        a[i] = i;
    }

    for (size_t j = 0; j < 20; j++) {
        b[j] = j;
    }

    for (size_t i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (size_t j = 0; j < 20; j++) {
        printf("%d ", b[j]);
    }

    printf("\n");

    my_free(b);
    my_free(a);

    return 0;
}