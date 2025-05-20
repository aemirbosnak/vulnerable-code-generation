//FormAI DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024 * 1024 // Allocation chunk size in bytes
#define MAX_CHUNKS 10 // Maximum number of chunks to allocate
#define MAX_ALLOCS 100 // Maximum number of times to allocate chunks
#define POISON1 0xAA // Memory poison value 1
#define POISON2 0x55 // Memory poison value 2
#define PARANOID_CHECK_INTERVAL 5 // Interval to check for memory tampering
#define PARANOID_ERROR_CODE 666 // Error code to return if paranoid checks fail

typedef struct Chunk {
    void* start;
    size_t size;
} Chunk;

Chunk chunks[MAX_CHUNKS];
int nChunks = 0;

void* allocateChunk(size_t size) {
    if (nChunks >= MAX_CHUNKS) {
        printf("[ERROR] Maximum number of chunks exceeded\n");
        return NULL;
    }
    
    void* chunk = malloc(size);
    if (chunk != NULL) {
        for (size_t i = 0; i < size; i++) {
            *((char*)chunk + i) = POISON1;
        }
        chunks[nChunks++] = (Chunk){.start = chunk, .size = size};
    } else {
        printf("[ERROR] Unable to allocate chunk of size %zu\n", size);
    }
    
    return chunk;
}

void freeChunks() {
    for (int i = 0; i < nChunks; i++) {
        for (size_t j = 0; j < chunks[i].size; j++) {
            if (*((char*)chunks[i].start + j) != POISON1 && *((char*)chunks[i].start + j) != POISON2) {
                printf("[ERROR] Memory tampering detected\n");
                exit(PARANOID_ERROR_CODE);
            }
        }
        free(chunks[i].start);
    }
    
    nChunks = 0;
}

void* allocate(size_t size) {
    void* chunk = allocateChunk(size);
    if (chunk == NULL) {
        return NULL;
    }
    
    for (size_t i = 0; i < size; i++) {
        *((char*)chunk + i) = POISON2;
    }
    
    return chunk;
}

void* paranoidAllocate(size_t size) {
    void* chunk = allocate(size);
    if (chunk == NULL) {
        return NULL;
    }
    
    static int allocCount = 0;
    if (++allocCount % PARANOID_CHECK_INTERVAL == 0) {
        for (int i = 0; i < nChunks; i++) {
            for (size_t j = 0; j < chunks[i].size; j++) {
                if (*((char*)chunks[i].start + j) != POISON1 && *((char*)chunks[i].start + j) != POISON2) {
                    printf("[ERROR] Memory tampering detected\n");
                    exit(PARANOID_ERROR_CODE);
                }
            }
        }
    }
    
    return chunk;
}

int main() {
    for (int i = 0; i < MAX_ALLOCS; i++) {
        void* chunk = paranoidAllocate(CHUNK_SIZE);
        if (chunk == NULL) {
            printf("[ERROR] Aborting due to allocation error\n");
            break;
        }
    }

    freeChunks();

    return 0;
}