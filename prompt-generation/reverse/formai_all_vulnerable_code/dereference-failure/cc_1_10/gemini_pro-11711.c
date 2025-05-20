//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 1000

// Structure to store allocation information
typedef struct {
    void *ptr;
    size_t size;
    char *file;
    int line;
} allocation_t;

// Array to store allocation information
static allocation_t allocations[MAX_ALLOCATIONS];

// Current number of allocations
static int num_allocations = 0;

// Function to allocate memory
void *xmalloc(size_t size, const char *file, int line) {
    // Check if we can allocate any more memory
    if (num_allocations == MAX_ALLOCATIONS) {
        fprintf(stderr, "Error: Maximum number of allocations reached\n");
        exit(1);
    }

    // Allocate memory
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(1);
    }

    // Store allocation information
    allocations[num_allocations].ptr = ptr;
    allocations[num_allocations].size = size;
    allocations[num_allocations].file = file;
    allocations[num_allocations].line = line;

    // Increment number of allocations
    num_allocations++;

    // Return pointer to allocated memory
    return ptr;
}

// Function to free memory
void xfree(void *ptr) {
    // Find allocation information
    int i;
    for (i = 0; i < num_allocations; i++) {
        if (allocations[i].ptr == ptr) {
            break;
        }
    }

    // Check if allocation was found
    if (i == num_allocations) {
        fprintf(stderr, "Error: Invalid pointer passed to free\n");
        exit(1);
    }

    // Free memory
    free(ptr);

    // Remove allocation information
    num_allocations--;
    for (; i < num_allocations; i++) {
        allocations[i] = allocations[i + 1];
    }
}

// Function to print memory usage
void print_memory_usage() {
    int i;

    // Print header
    printf("Memory Usage:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("%-20s %-10s %-20s %-20s\n", "Address", "Size", "File", "Line");

    // Print allocation information
    for (i = 0; i < num_allocations; i++) {
        printf("%-20p %-10lu %-20s %-20d\n", allocations[i].ptr, allocations[i].size, allocations[i].file, allocations[i].line);
    }

    // Print footer
    printf("--------------------------------------------------------------------------------\n");
    printf("Total Allocations: %d\n", num_allocations);
}

// Main function
int main() {
    // Allocate some memory
    int *ptr1 = xmalloc(100, __FILE__, __LINE__);
    int *ptr2 = xmalloc(200, __FILE__, __LINE__);
    int *ptr3 = xmalloc(300, __FILE__, __LINE__);

    // Print memory usage
    print_memory_usage();

    // Free some memory
    xfree(ptr2);
    xfree(ptr3);

    // Print memory usage
    print_memory_usage();

    // Free remaining memory
    xfree(ptr1);

    // Print memory usage
    print_memory_usage();

    return 0;
}