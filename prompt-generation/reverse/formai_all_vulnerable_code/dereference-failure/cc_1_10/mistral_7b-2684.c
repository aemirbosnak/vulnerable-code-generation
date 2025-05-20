//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct {
    size_t size;
    void *ptr;
    struct stat_block *next;
} stat_block;

stat_block *memory_pool = NULL;
size_t total_allocated = 0;
size_t total_freed = 0;

void *my_malloc(size_t size) {
    stat_block *new_block, *current;

    if (size == 0) {
        printf("Error: Invalid size.\n");
        return NULL;
    }

    new_block = (stat_block *) malloc(sizeof(stat_block) + size);
    if (new_block == NULL) {
        printf("Error: Out of memory.\n");
        return NULL;
    }

    new_block->size = size;
    new_block->ptr = (void *) ((char *) new_block + sizeof(stat_block));

    total_allocated += size;

    if (memory_pool == NULL) {
        memory_pool = new_block;
        memory_pool->next = NULL;
    } else {
        current = memory_pool;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_block;
    }

    return new_block->ptr;
}

void my_free(void *ptr) {
    stat_block *current, *prev;

    if (ptr == NULL) {
        printf("Error: Invalid pointer.\n");
        return;
    }

    current = memory_pool;
    prev = NULL;

    while (current != NULL) {
        if (current->ptr == ptr) {
            if (prev == NULL) {
                memory_pool = current->next;
            } else {
                prev->next = current->next;
            }

            total_freed += current->size;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    int *array, i;
    char *str;

    array = (int *) my_malloc(10 * sizeof(int));
    for (i = 0; i < 10; i++) {
        array[i] = i;
    }

    str = (char *) my_malloc(20);
    strcpy(str, "Hello, World!");

    printf("Total Allocated: %zu bytes\n", total_allocated);
    printf("Total Freed: %zu bytes\n", total_freed);

    my_free(array);
    my_free(str);

    printf("Total Allocated: %zu bytes\n", total_allocated);
    printf("Total Freed: %zu bytes\n", total_freed);

    return 0;
}