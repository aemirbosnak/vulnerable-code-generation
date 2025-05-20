//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct MemoryBlock {
    size_t size;
    void *ptr;
    const char *file;
    int line;
};

struct MemoryBlock *allocatedBlocks = NULL;
size_t numAllocatedBlocks = 0;

void *my_malloc(size_t size, const char *file, int line) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: malloc failed in %s:%d\n", file, line);
        exit(1);
    }
    
    struct MemoryBlock *newBlock = malloc(sizeof(struct MemoryBlock));
    if (newBlock == NULL) {
        fprintf(stderr, "Error: malloc failed in %s:%d\n", file, line);
        exit(1);
    }
    
    newBlock->size = size;
    newBlock->ptr = ptr;
    newBlock->file = file;
    newBlock->line = line;
    
    allocatedBlocks = realloc(allocatedBlocks, (numAllocatedBlocks + 1) * sizeof(struct MemoryBlock));
    if (allocatedBlocks == NULL) {
        fprintf(stderr, "Error: realloc failed in %s:%d\n", file, line);
        exit(1);
    }
    
    allocatedBlocks[numAllocatedBlocks] = *newBlock;
    numAllocatedBlocks++;
    
    return ptr;
}

void my_free(void *ptr, const char *file, int line) {
    if (ptr == NULL) {
        return;
    }
    
    for (size_t i = 0; i < numAllocatedBlocks; i++) {
        if (allocatedBlocks[i].ptr == ptr) {
            free(allocatedBlocks[i].ptr);
            allocatedBlocks[i] = allocatedBlocks[numAllocatedBlocks - 1];
            numAllocatedBlocks--;
            return;
        }
    }
    
    fprintf(stderr, "Error: free called on invalid pointer in %s:%d\n", file, line);
    exit(1);
}

void print_allocated_blocks() {
    printf("Allocated blocks:\n");
    for (size_t i = 0; i < numAllocatedBlocks; i++) {
        printf("  %zu bytes at %p allocated in %s:%d\n", allocatedBlocks[i].size, allocatedBlocks[i].ptr, allocatedBlocks[i].file, allocatedBlocks[i].line);
    }
}

int main() {
    // Allocate some memory blocks
    int *a = my_malloc(sizeof(int), __FILE__, __LINE__);
    char *b = my_malloc(sizeof(char) * 10, __FILE__, __LINE__);
    double *c = my_malloc(sizeof(double), __FILE__, __LINE__);
    
    // Use the memory blocks
    *a = 42;
    strcpy(b, "Hello world!");
    *c = 3.14159;
    
    // Print the allocated blocks
    print_allocated_blocks();
    
    // Free the memory blocks
    my_free(a, __FILE__, __LINE__);
    my_free(b, __FILE__, __LINE__);
    my_free(c, __FILE__, __LINE__);
    
    return 0;
}