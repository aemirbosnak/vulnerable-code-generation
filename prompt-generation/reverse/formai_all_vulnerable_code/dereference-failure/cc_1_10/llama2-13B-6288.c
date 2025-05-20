//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define MEMORY_CHUNK_SIZE 4096
#define MEMORY_MAX_USAGE 0.8

struct memory_block {
    void *base;
    size_t size;
    size_t used;
};

struct memory_map {
    struct memory_block *blocks;
    size_t num_blocks;
    size_t total_size;
};

static void *malloc_with_usage(size_t size) {
    void *ptr = malloc(size);
    struct memory_block *block = malloc(sizeof(struct memory_block));
    block->base = ptr;
    block->size = size;
    block->used = 0;
    return ptr;
}

static void free_with_usage(void *ptr) {
    struct memory_block *block = ptr - sizeof(struct memory_block);
    free(block);
}

static void print_usage(struct memory_map *map) {
    double usage = (double)map->total_size - map->num_blocks * MEMORY_CHUNK_SIZE;
    usage /= 1024.0;
    usage *= 100.0;
    printf("Memory usage: %3.2f %%\n", usage);
}

int main() {
    struct memory_map map;
    map.blocks = NULL;
    map.num_blocks = 0;
    map.total_size = 0;

    while (1) {
        size_t requested_size = 4096;
        void *ptr = malloc_with_usage(requested_size);
        struct memory_block *block = malloc(sizeof(struct memory_block));
        block->base = ptr;
        block->size = requested_size;
        block->used = 0;
        map.blocks = realloc(map.blocks, (map.num_blocks + 1) * sizeof(struct memory_block));
        map.blocks[map.num_blocks] = *block;
        map.num_blocks++;
        map.total_size += requested_size;

        // Calculate usage
        double usage = (double)map.total_size - map.num_blocks * MEMORY_CHUNK_SIZE;
        usage /= 1024.0;
        usage *= 100.0;
        print_usage(&map);

        // Check if usage is above the limit
        if (usage > MEMORY_MAX_USAGE) {
            printf("Memory usage limit exceeded!\n");
            break;
        }

        // Free the memory block
        free_with_usage(ptr);
    }

    return 0;
}