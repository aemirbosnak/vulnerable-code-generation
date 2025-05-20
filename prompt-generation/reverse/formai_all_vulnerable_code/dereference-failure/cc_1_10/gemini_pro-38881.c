//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct memory_block {
    void *ptr;
    size_t size;
} memory_block;

void print_usage(void) {
    printf("Usage: ./ram_monitor <interval> <duration>\n");
    printf("interval: The interval in seconds between each memory usage check.\n");
    printf("duration: The duration in seconds for which to monitor memory usage.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    int interval = atoi(argv[1]);
    int duration = atoi(argv[2]);

    if (interval <= 0 || duration <= 0) {
        printf("Error: Invalid interval or duration.\n");
        return 1;
    }

    // Initialize memory usage monitor.
    memory_block *blocks = NULL;
    size_t num_blocks = 0;
    size_t total_size = 0;

    // Start memory usage monitor.
    clock_t start = clock();
    while (clock() - start < duration * CLOCKS_PER_SEC) {
        // Get current memory usage.
        memory_block *new_blocks = malloc(sizeof(memory_block));
        new_blocks->ptr = malloc(1024 * 1024);
        new_blocks->size = 1024 * 1024;
        num_blocks++;
        total_size += new_blocks->size;

        // Print memory usage.
        printf("Memory usage: %ld MB\n", total_size / (1024 * 1024));
 
    }

    // Stop memory usage monitor.
    for (size_t i = 0; i < num_blocks; i++) {
        free(blocks[i].ptr);
    }
    free(blocks);

    return 0;
}