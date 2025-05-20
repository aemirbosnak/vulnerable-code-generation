//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory block header structure
typedef struct {
    size_t size;
    struct mem_block *next;
} mem_block_header;

// Define a custom memory manager structure
typedef struct {
    mem_block_header *free_list;
    size_t total_memory;
    size_t allocated_memory;
} memory_manager;

// Initialize the memory manager
void memory_manager_init(memory_manager *mm, size_t total_memory) {
    // Allocate memory for the memory manager
    mm->free_list = malloc(sizeof(mem_block_header));
    if (mm->free_list == NULL) {
        perror("malloc");
        exit(1);
    }

    // Set the initial state of the memory manager
    mm->free_list->size = total_memory - sizeof(mem_block_header);
    mm->free_list->next = NULL;
    mm->total_memory = total_memory;
    mm->allocated_memory = 0;
}

// Allocate memory from the memory manager
void *memory_manager_alloc(memory_manager *mm, size_t size) {
    // Check if there is enough free memory
    if (size > mm->free_list->size) {
        fprintf(stderr, "Out of memory!\n");
        return NULL;
    }

    // Allocate a new memory block
    mem_block_header *block = malloc(sizeof(mem_block_header) + size);
    if (block == NULL) {
        perror("malloc");
        return NULL;
    }

    // Update the memory manager state
    mm->free_list->size -= size;
    block->size = size;
    block->next = mm->free_list->next;
    mm->free_list->next = block;
    mm->allocated_memory += size;

    // Return the pointer to the allocated memory
    return block + 1;
}

// Free memory to the memory manager
void memory_manager_free(memory_manager *mm, void *ptr) {
    // Cast the pointer back to a memory block header
    mem_block_header *block = (mem_block_header *)ptr - 1;

    // Find the previous memory block in the free list
    mem_block_header *prev = mm->free_list;
    while (prev->next != block) {
        prev = prev->next;
    }

    // Merge the freed memory block with the previous block if possible
    if (prev->next == block) {
        prev->size += block->size;
        prev->next = block->next;
    }

    // Update the memory manager state
    mm->allocated_memory -= block->size;

    // Free the memory block
    free(block);
}

// Print the memory manager state
void memory_manager_print(memory_manager *mm) {
    printf("Total memory: %lu bytes\n", mm->total_memory);
    printf("Allocated memory: %lu bytes\n", mm->allocated_memory);
    printf("Free memory: %lu bytes\n", mm->free_list->size);
}

// Main function
int main() {
    // Initialize the memory manager with 1MB of memory
    memory_manager mm;
    memory_manager_init(&mm, 1024 * 1024);

    // Allocate some memory blocks
    int *array1 = memory_manager_alloc(&mm, 100 * sizeof(int));
    int *array2 = memory_manager_alloc(&mm, 200 * sizeof(int));
    int *array3 = memory_manager_alloc(&mm, 300 * sizeof(int));

    // Free some memory blocks
    memory_manager_free(&mm, array2);
    memory_manager_free(&mm, array3);

    // Print the memory manager state
    memory_manager_print(&mm);

    // Free the remaining memory blocks
    memory_manager_free(&mm, array1);

    // Print the memory manager state
    memory_manager_print(&mm);

    return 0;
}