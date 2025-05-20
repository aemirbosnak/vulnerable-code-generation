//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <limits.h>

// Simple utility to simulate memory allocation and deallocation
typedef struct {
    size_t size;  // Size of the memory block
    void *ptr;    // Pointer to the memory block
    int allocated; // Flag to track if the block is allocated or not
} memory_block;

// Create a memory block of the given size
memory_block *create_memory_block(size_t size) {
    memory_block *block = malloc(sizeof(memory_block));
    block->size = size;
    block->ptr = malloc(size);
    block->allocated = 1;
    return block;
}

// Free the memory block
void free_memory_block(memory_block *block) {
    if (block->allocated) {
        free(block->ptr);
        block->allocated = 0;
    }
    free(block);
}

// Simulate memory allocation and deallocation
void simulate_memory_usage(int num_blocks) {
    memory_block **blocks = malloc(sizeof(memory_block *) * num_blocks);
    srand(time(NULL));
    for (int i = 0; i < num_blocks; i++) {
        // Randomly generate the size of the memory block
        size_t size = rand() % (1024 * 1024);  // Up to 1 MB
        blocks[i] = create_memory_block(size);
        usleep(rand() % 1000);  // Simulate some delay
        // Randomly decide whether to free the memory block
        if (rand() % 2) {
            free_memory_block(blocks[i]);
        }
    }
    free(blocks);
}

// Get the current RAM usage in bytes
uint64_t get_ram_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss * 1024;
}

// Print the current RAM usage in a user-friendly format
void print_ram_usage() {
    uint64_t ram_usage = get_ram_usage();
    printf("Current RAM usage: %.2f MB\n", (double)ram_usage / (1024 * 1024));
}

int main() {
    // Set the stack size to a large value to avoid stack overflow
    const rlim_t stack_size = 128 * 1024 * 1024;  // 128 MB
    struct rlimit stack_limit;
    stack_limit.rlim_cur = stack_limit.rlim_max = stack_size;
    setrlimit(RLIMIT_STACK, &stack_limit);

    // Simulate memory allocation and deallocation
    simulate_memory_usage(10000);

    // Print the current RAM usage
    print_ram_usage();

    return 0;
}