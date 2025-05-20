//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Custom memory management functions
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void my_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}

// Memory block
typedef struct {
    size_t size;
    void* data;
} MemoryBlock;

// Memory pool
typedef struct {
    size_t capacity;
    size_t used;
    MemoryBlock* blocks;
} MemoryPool;

// Create a memory pool
MemoryPool* mp_create(size_t capacity) {
    MemoryPool* mp = my_malloc(sizeof(MemoryPool));
    mp->capacity = capacity;
    mp->used = 0;
    mp->blocks = my_malloc(sizeof(MemoryBlock) * capacity);
    return mp;
}

// Destroy a memory pool
void mp_destroy(MemoryPool* mp) {
    for (size_t i = 0; i < mp->used; i++) {
        my_free(mp->blocks[i].data);
    }
    my_free(mp->blocks);
    my_free(mp);
}

// Allocate memory from a memory pool
void* mp_alloc(MemoryPool* mp, size_t size) {
    if (mp->used == mp->capacity) {
        return NULL;
    }

    MemoryBlock* block = &mp->blocks[mp->used];
    block->size = size;
    block->data = my_malloc(size);
    if (block->data == NULL) {
        return NULL;
    }

    mp->used++;
    return block->data;
}

// Free memory to a memory pool
void mp_free(MemoryPool* mp, void* ptr) {
    for (size_t i = 0; i < mp->used; i++) {
        MemoryBlock* block = &mp->blocks[i];
        if (block->data == ptr) {
            my_free(block->data);
            block->size = 0;
            block->data = NULL;
            mp->used--;
            return;
        }
    }
}

// Usage example
int main() {
    // Create a memory pool
    MemoryPool* mp = mp_create(10);

    // Allocate memory from the memory pool
    int* arr = mp_alloc(mp, sizeof(int) * 10);
    if (arr == NULL) {
        perror("mp_alloc");
        exit(EXIT_FAILURE);
    }

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Free the allocated memory
    mp_free(mp, arr);

    // Destroy the memory pool
    mp_destroy(mp);

    return 0;
}