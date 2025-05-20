//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define TOTAL_MEMORY 1024 * 1024 * 1024 // 1 GB
#define BLOCK_SIZE 1024 * 1024 // 1 MB
#define INTERVAL 5

typedef struct block {
    int id;
    void *memory;
} block_t;

block_t *block_list[1024];
int block_count = 0;

void* allocate_memory(int size) {
    void *memory = malloc(size);
    if (memory == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    block_t *block = (block_t *) malloc(sizeof(block_t));
    block->id = block_count;
    block->memory = memory;
    block_list[block_count] = block;
    block_count++;
    return memory;
}

void free_memory(int block_id) {
    if (block_id >= block_count) {
        printf("Free memory failed. Block ID out of range!\n");
        return;
    }
    free(block_list[block_id]->memory);
    free(block_list[block_id]);
    block_list[block_id] = NULL;
}

void print_memory_status() {
    int allocated_blocks = 0;
    int allocated_memory = 0;
    printf("----- Memory Status -----\n");
    for (int i = 0; i < block_count; i++) {
        if (block_list[i] != NULL) {
            allocated_blocks++;
            allocated_memory += BLOCK_SIZE;
        }
    }
    printf("Total Memory: %d MB\n", TOTAL_MEMORY / (1024 * 1024));
    printf("Allocated Memory: %d MB\n", allocated_memory / (1024 * 1024));
    printf("Free Memory: %d MB\n", (TOTAL_MEMORY - allocated_memory) / (1024 * 1024));
    printf("Number of Allocated Blocks: %d\n", allocated_blocks);
}

int main() {
    srand(time(NULL));
    printf("Starting C RAM Usage Monitor...\n");
    while (1) {
        int allocate_chance = rand() % 100 + 1;
        if (allocate_chance <= 50 && block_count < 1024) {
            void *memory = allocate_memory(BLOCK_SIZE);
            if (memory != NULL) {
                printf("Allocated block %d at memory location %p.\n", block_count - 1, memory);
            }
        }
        int free_chance = rand() % 100 + 1;
        if (free_chance <= 20 && block_count > 0) {
            int block_id = rand() % block_count;
            free_memory(block_id);
            printf("Freed block %d.\n", block_id);
        }
        print_memory_status();
        printf("------------------------\n");
        sleep(INTERVAL);
    }
    return 0;
}