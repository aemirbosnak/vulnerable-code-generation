//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    void *next;
    char data[1];
} Block;

static Block *head = NULL;
static size_t total_allocated = 0;

void *my_malloc(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Error: size is zero.\n");
        return NULL;
    }

    size += sizeof(Block);
    Block *new_block = (Block *)malloc(size);

    if (new_block == NULL) {
        fprintf(stderr, "Error: out of memory.\n");
        return NULL;
    }

    new_block->size = size - sizeof(Block);
    new_block->next = head;
    head = new_block;
    total_allocated += size;

    return (void *)new_block->data;
}

void my_free(void *ptr) {
    Block *current = head;
    Block *previous = NULL;

    while (current != NULL) {
        if (current->data == ptr) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            total_allocated -= current->size;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void print_memory_usage() {
    printf("Total allocated memory: %zu bytes\n", total_allocated);
}

int main() {
    int *array1 = my_malloc(10 * sizeof(int));
    int *array2 = my_malloc(20 * sizeof(int));
    my_free(array1);

    for (int i = 0; i < 20; i++) {
        array2[i] = i * i;
    }

    print_memory_usage();

    my_free(array2);

    print_memory_usage();

    return 0;
}