//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MEMORY_BLOCK_SIZE (4 * 1024 * 1024) // 4 MB
#define MAX_MEMORY_USAGE (100 * 1024 * 1024) // 100 MB

struct memory_block {
    void *base;
    size_t size;
    size_t used;
};

struct memory_map {
    struct memory_block *blocks;
    size_t num_blocks;
};

// Initialize memory map
struct memory_map *init_memory_map(void) {
    struct memory_map *map = malloc(sizeof(struct memory_map));
    map->blocks = malloc(MEMORY_BLOCK_SIZE * sizeof(struct memory_block));
    map->num_blocks = 0;
    return map;
}

// Allocate memory block
void *allocate_memory(struct memory_map *map, size_t size) {
    void *base = NULL;
    size_t used = 0;
    for (size_t i = 0; i < map->num_blocks; i++) {
        struct memory_block *block = map->blocks + i;
        if (block->size > used) {
            base = block->base + used;
            used = block->size - used;
            if (used > size) {
                used = size;
            }
            break;
        }
    }
    if (base == NULL) {
        struct memory_block *new_block = malloc(size);
        new_block->size = size;
        new_block->used = 0;
        map->num_blocks++;
        map->blocks = realloc(map->blocks, (map->num_blocks + 1) * sizeof(struct memory_block));
        map->blocks[map->num_blocks - 1] = *new_block;
        base = new_block->base;
    }
    return base;
}

// Free memory block
void free_memory(struct memory_map *map, void *base) {
    for (size_t i = 0; i < map->num_blocks; i++) {
        struct memory_block *block = map->blocks + i;
        if (block->base == base) {
            block->used -= (size_t) (base - block->base);
            if (block->used == 0) {
                map->num_blocks--;
                free(block);
            }
            return;
        }
    }
}

// Display memory usage
void display_memory_usage(struct memory_map *map) {
    printf("Memory Usage:\n");
    for (size_t i = 0; i < map->num_blocks; i++) {
        struct memory_block *block = map->blocks + i;
        printf("Block %zu: Used %zu, Free %zu\n", i, block->used, block->size - block->used);
    }
    printf("Total Used: %zu\n", map->num_blocks * MEMORY_BLOCK_SIZE);
}

int main(void) {
    struct memory_map *map = init_memory_map();
    void *ptr = allocate_memory(map, 1024 * 1024); // allocate 1 MB
    display_memory_usage(map);
    free_memory(map, ptr);
    display_memory_usage(map);
    return 0;
}