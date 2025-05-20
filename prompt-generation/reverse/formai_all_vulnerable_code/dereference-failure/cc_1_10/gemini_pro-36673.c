//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Memory block structure
typedef struct mem_block {
    void *data;
    size_t size;
    struct mem_block *next;
} mem_block_t;

// Memory manager structure
typedef struct mem_manager {
    mem_block_t *free_list;
    pthread_mutex_t lock;
} mem_manager_t;

// Create a new memory manager
mem_manager_t *create_mem_manager() {
    mem_manager_t *mm = malloc(sizeof(mem_manager_t));
    if (mm == NULL) {
        return NULL;
    }

    mm->free_list = NULL;
    pthread_mutex_init(&mm->lock, NULL);

    return mm;
}

// Destroy a memory manager
void destroy_mem_manager(mem_manager_t *mm) {
    mem_block_t *block = mm->free_list;

    while (block != NULL) {
        mem_block_t *next = block->next;
        free(block->data);
        free(block);
        block = next;
    }

    pthread_mutex_destroy(&mm->lock);
    free(mm);
}

// Allocate memory from the memory manager
void *my_malloc(mem_manager_t *mm, size_t size) {
    pthread_mutex_lock(&mm->lock);

    mem_block_t *block = mm->free_list;

    // Find a free block of sufficient size
    while (block != NULL && block->size < size) {
        block = block->next;
    }

    // If no free block found, allocate a new one
    if (block == NULL) {
        block = malloc(sizeof(mem_block_t) + size);
        if (block == NULL) {
            pthread_mutex_unlock(&mm->lock);
            return NULL;
        }

        block->data = (void *) (block + 1);
        block->size = size;
        block->next = NULL;
    }

    // Remove the block from the free list
    if (block == mm->free_list) {
        mm->free_list = block->next;
    } else {
        mem_block_t *prev = mm->free_list;
        while (prev->next != block) {
            prev = prev->next;
        }
        prev->next = block->next;
    }

    pthread_mutex_unlock(&mm->lock);

    return block->data;
}

// Free memory to the memory manager
void my_free(mem_manager_t *mm, void *ptr) {
    pthread_mutex_lock(&mm->lock);

    mem_block_t *block = (mem_block_t *) ((char *) ptr - sizeof(mem_block_t));

    // Add the block to the free list
    block->next = mm->free_list;
    mm->free_list = block;

    pthread_mutex_unlock(&mm->lock);
}

// Example usage
int main() {
    mem_manager_t *mm = create_mem_manager();

    int *array = my_malloc(mm, sizeof(int) * 10);
    if (array == NULL) {
        return 1;
    }

    // Use the array

    my_free(mm, array);

    destroy_mem_manager(mm);

    return 0;
}