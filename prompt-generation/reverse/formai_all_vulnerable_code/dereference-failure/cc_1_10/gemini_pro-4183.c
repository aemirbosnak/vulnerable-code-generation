//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

// Declare a custom data structure to track memory usage
typedef struct {
    size_t total;       // Total memory allocated
    size_t current;     // Current memory allocated
    size_t peak;        // Peak memory allocated
} memory_usage_t;

// Initialize memory usage tracking
memory_usage_t mem_usage = {0, 0, 0};

// Function to allocate memory and track usage
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Could not allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Update memory usage stats
    mem_usage.total += size;
    mem_usage.current += size;
    if (mem_usage.current > mem_usage.peak) {
        mem_usage.peak = mem_usage.current;
    }

    return ptr;
}

// Function to free memory and track usage
void my_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);

        // Update memory usage stats
        mem_usage.current -= mem_usage.total;
        if (mem_usage.current < 0) {
            fprintf(stderr, "Error: Memory underflow\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to print memory usage information
void print_mem_usage() {
    printf("Memory Usage:\n");
    printf("Total: %lu bytes\n", mem_usage.total);
    printf("Current: %lu bytes\n", mem_usage.current);
    printf("Peak: %lu bytes\n", mem_usage.peak);
}

// Main program
int main() {
    // Allocate memory using my_malloc
    char* buf1 = my_malloc(1024);
    char* buf2 = my_malloc(2048);
    char* buf3 = my_malloc(4096);

    // Print memory usage information
    print_mem_usage();

    // Free memory using my_free
    my_free(buf1);
    my_free(buf2);
    my_free(buf3);

    // Print memory usage information again
    print_mem_usage();

    return 0;
}