//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

Block* g_heap = NULL;

void* my_malloc(size_t size) {
    if (size == 0) {
        printf("Error: size is zero\n");
        return NULL;
    }

    Block* new_block = (Block*) malloc(sizeof(Block) + size);

    if (new_block == NULL) {
        printf("Error: out of memory\n");
        return NULL;
    }

    new_block->size = size;
    new_block->next = g_heap;
    g_heap = new_block;

    return (void*) (new_block + 1);
}

void my_free(void* ptr) {
    Block* current = g_heap;
    Block* previous = NULL;

    while (current != NULL) {
        if (current + sizeof(Block) == ptr) {
            if (previous == NULL) {
                g_heap = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main(int argc, char* argv[]) {
    int* array = NULL;
    int i;

    for (i = 0; i < 10; i++) {
        array = (int*) my_malloc(sizeof(int));
        *array = i;
    }

    for (i = 0; i < 10; i++) {
        printf("Element %d: %d\n", i, *(array + i));
    }

    for (i = 0; i < 10; i++) {
        my_free(array + i);
    }

    printf("Memory is freed\n");

    return 0;
}