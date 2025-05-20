//Falcon-180B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define CHUNK_SIZE 1024

// Define a struct to hold the metadata of each chunk
typedef struct {
    size_t size;
    bool is_free;
    struct chunk* next;
} chunk_t;

// Define a global pointer to the first chunk
chunk_t* first_chunk = NULL;

// Function to initialize the memory management system
void init() {
    first_chunk = (void*)0;
    first_chunk->size = 0;
    first_chunk->is_free = true;
    first_chunk->next = NULL;
}

// Function to allocate memory
void* malloc(size_t size) {
    chunk_t* current_chunk = first_chunk;
    while (current_chunk!= NULL) {
        if (current_chunk->size >= size && current_chunk->is_free) {
            current_chunk->is_free = false;
            void* result = (void*)((uintptr_t)current_chunk + sizeof(chunk_t));
            return result;
        }
        current_chunk = current_chunk->next;
    }
    // If no suitable chunk is found, create a new one
    chunk_t* new_chunk = (void*)malloc(sizeof(chunk_t) + size);
    if (new_chunk == NULL) {
        return NULL;
    }
    new_chunk->size = size;
    new_chunk->is_free = false;
    new_chunk->next = first_chunk;
    first_chunk = new_chunk;
    return (void*)((uintptr_t)new_chunk + sizeof(chunk_t));
}

// Function to free memory
void free(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    chunk_t* chunk = (void*)((uintptr_t)ptr - sizeof(chunk_t));
    chunk->is_free = true;
}

int main() {
    init();
    void* ptr1 = malloc(100);
    void* ptr2 = malloc(200);
    void* ptr3 = malloc(300);
    free(ptr1);
    free(ptr3);
    printf("Allocated memory: %zu bytes\n", first_chunk->size);
    return 0;
}