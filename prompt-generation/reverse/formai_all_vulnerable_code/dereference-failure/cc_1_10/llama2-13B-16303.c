//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MEMORY_CHUNK_SIZE (1024 * 1024)

struct memory_chunk {
    void *addr;
    size_t size;
    struct memory_chunk *next;
};

struct memory_map {
    size_t total_size;
    size_t used_size;
    struct memory_chunk *chunks;
};

int main(void) {
    struct memory_map *map = malloc(sizeof(struct memory_map));
    map->total_size = 0;
    map->used_size = 0;
    map->chunks = NULL;

    while (1) {
        size_t chunk_size = MEMORY_CHUNK_SIZE;
        void *addr = mmap(NULL, chunk_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (addr == MAP_FAILED) {
            perror("mmap failed");
            exit(EXIT_FAILURE);
        }

        struct memory_chunk *new_chunk = malloc(sizeof(struct memory_chunk));
        new_chunk->addr = addr;
        new_chunk->size = chunk_size;
        new_chunk->next = map->chunks;
        map->chunks = new_chunk;

        map->total_size += chunk_size;
        map->used_size += chunk_size;

        printf("Memory usage: %zu bytes (%zu%%)\n", map->used_size,
                        (map->used_size * 100) / map->total_size);

        usleep(100000);
    }

    return 0;
}