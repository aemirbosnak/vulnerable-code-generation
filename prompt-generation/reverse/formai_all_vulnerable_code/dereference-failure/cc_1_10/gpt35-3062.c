//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024
#define NUM_CHUNKS 10

struct Chunk {
    void* start;
    size_t size;
    struct Chunk* next;
};

struct Chunk* free_list = NULL;

void* my_malloc(size_t size) {
    if (free_list == NULL) {
        for (int i = 0; i < NUM_CHUNKS; i++) {
            // Allocate a new chunk
            struct Chunk* new_chunk = (struct Chunk*) malloc(sizeof(struct Chunk));
            new_chunk->start = malloc(CHUNK_SIZE);
            new_chunk->size = CHUNK_SIZE;
            new_chunk->next = free_list;
            free_list = new_chunk;
        }
    }

    // First-fit algorithm
    struct Chunk* cur_chunk = free_list;
    while (cur_chunk != NULL) {
        if (cur_chunk->size >= size) {
            // Split chunk if there is enough space
            if (cur_chunk->size - size >= sizeof(struct Chunk)) {
                struct Chunk* new_chunk = (struct Chunk*) ((char*) cur_chunk->start + size);
                new_chunk->start = (void*) ((char*) new_chunk + sizeof(struct Chunk));
                new_chunk->size = cur_chunk->size - size - sizeof(struct Chunk);
                new_chunk->next = cur_chunk->next;
                cur_chunk->next = new_chunk;
            }

            void* ptr = cur_chunk->start;
            cur_chunk->size = size;

            // Remove chunk from free list
            if (cur_chunk == free_list) {
                free_list = cur_chunk->next;
            } else {
                struct Chunk* prev_chunk = free_list;
                while (prev_chunk->next != cur_chunk) {
                    prev_chunk = prev_chunk->next;
                }
                prev_chunk->next = cur_chunk->next;
            }

            return ptr;
        }
        cur_chunk = cur_chunk->next;
    }

    return NULL;
}

void my_free(void* ptr) {
    struct Chunk* new_chunk = (struct Chunk*) ((char*) ptr - sizeof(struct Chunk));
    new_chunk->next = free_list;
    free_list = new_chunk;
}

int main() {
  // Usage example
  char* str = (char*) my_malloc(10 * sizeof(char));
  sprintf(str, "Hello, %s", "world!");
  printf("%s\n", str);
  my_free(str);
  return 0;
}