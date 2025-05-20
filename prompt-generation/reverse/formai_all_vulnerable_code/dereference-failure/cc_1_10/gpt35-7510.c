//FormAI DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define MAX_CHUNKS 3
#define CHUNK_SIZE 5

// Node structure to hold the memory chunk information
struct MemoryChunk {
    int start_index;
    int end_index;
    struct MemoryChunk* next_chunk;
};

// State of the buffer
struct BufferState {
    char buffer[BUFFER_SIZE];
    int num_chunks;
    struct MemoryChunk* free_chunks;
    struct MemoryChunk* used_chunks;
};

// Function to initialize the buffer state
void init_buffer_state(struct BufferState* state) {
    state->num_chunks = MAX_CHUNKS;
    state->free_chunks = (struct MemoryChunk*) malloc(sizeof(struct MemoryChunk) * MAX_CHUNKS);
    state->used_chunks = NULL;

    // Initialize the free chunks
    int i;
    for (i = 0; i < MAX_CHUNKS; i++) {
        struct MemoryChunk* chunk = &state->free_chunks[i];
        chunk->start_index = i * CHUNK_SIZE;
        chunk->end_index = chunk->start_index + CHUNK_SIZE - 1;
        chunk->next_chunk = i == MAX_CHUNKS - 1 ? NULL : &state->free_chunks[i + 1];
    }
}

// Function to allocate memory from the buffer
char* my_malloc(struct BufferState* state, int size) {
    // Check if there are any free chunks available
    if (state->num_chunks == 0) {
        printf("No free memory available!\n");
        return NULL;
    }

    // Find the first free chunk that can fit the requested size
    struct MemoryChunk* chunk = state->free_chunks;
    while (chunk != NULL) {
        int chunk_size = chunk->end_index - chunk->start_index + 1;
        if (chunk_size >= size) {
            break;
        }
        chunk = chunk->next_chunk;
    }

    // If no free chunk is available, print error message and return NULL
    if (chunk == NULL) {
        printf("No free memory available that can fit the requested size!\n");
        return NULL;
    }

    // Update the buffer state and return a pointer to the allocated memory
    char* mem = &state->buffer[chunk->start_index];
    chunk->start_index += size;
    if (chunk->start_index > chunk->end_index) {
        // The chunk has been fully used, move it from free to used list
        state->free_chunks = chunk->next_chunk;
        chunk->next_chunk = state->used_chunks;
        state->used_chunks = chunk;
        state->num_chunks--;
    }
    return mem;
}

// Function to free memory allocated from the buffer
void my_free(struct BufferState* state, char* mem, int size) {
    // Find the chunk corresponding to the freed memory
    struct MemoryChunk* chunk = state->used_chunks;
    while (chunk != NULL) {
        if (mem >= &state->buffer[chunk->start_index] && mem < &state->buffer[chunk->end_index + 1 - size]) {
            break;
        }
        chunk = chunk->next_chunk;
    }

    // If no corresponding chunk is found, print error message and return
    if (chunk == NULL) {
        printf("Invalid memory address!\n");
        return;
    }

    // Update the buffer state and move the chunk from used to free list
    chunk->start_index = mem - state->buffer;
    if (chunk->next_chunk == NULL || chunk->next_chunk->start_index > mem) {
        chunk->next_chunk = state->free_chunks;
        state->free_chunks = chunk;
        state->num_chunks++;
    } else {
        // Merge the current chunk with the next one if they are adjacent
        struct MemoryChunk* next_chunk = chunk->next_chunk;
        if (next_chunk->start_index == chunk->end_index + 1) {
            chunk->end_index = next_chunk->end_index;
            chunk->next_chunk = next_chunk->next_chunk;
        }
    }
}

int main() {
    struct BufferState state;
    init_buffer_state(&state);

    // Allocate and free memory from the buffer
    char* mem1 = my_malloc(&state, 3);
    printf("Allocated memory: %p\n", mem1);
    char* mem2 = my_malloc(&state, 7);
    printf("Allocated memory: %p\n", mem2);
    char* mem3 = my_malloc(&state, 5);
    printf("Allocated memory: %p\n", mem3);

    my_free(&state, mem2, 7);
    printf("Freed memory: %p\n", mem2);
    char* mem4 = my_malloc(&state, 9);
    if (mem4 != NULL) {
        printf("Allocated memory: %p\n", mem4);
    }

    return 0;
}