//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_MEMORY_BLOCKS 10

typedef struct {
    void *address;
    size_t size;
} MemoryBlock;

MemoryBlock memoryBlocks[MAX_MEMORY_BLOCKS];
int blockCount = 0;

void* customMalloc(size_t size) {
    if (blockCount >= MAX_MEMORY_BLOCKS) {
        printf("Memory limit reached. Cannot allocate more blocks.\n");
        return NULL;
    }
    
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    memoryBlocks[blockCount].address = ptr;
    memoryBlocks[blockCount].size = size;
    blockCount++;
    
    return ptr;
}

void customFree(void *ptr) {
    for (int i = 0; i < blockCount; i++) {
        if (memoryBlocks[i].address == ptr) {
            free(ptr);
            printf("Freed memory block of size %zu at %p\n", memoryBlocks[i].size, ptr);
            memoryBlocks[i].address = NULL; // Mark as freed
            memoryBlocks[i].size = 0;
            return;
        }
    }
    printf("Pointer not found in allocated memory blocks.\n");
}

void printMemoryStatus() {
    printf("Allocated memory blocks:\n");
    for (int i = 0; i < blockCount; i++) {
        if (memoryBlocks[i].address != NULL) {
            printf("Block %d: Size = %zu, Address = %p\n", 
                   i, memoryBlocks[i].size, memoryBlocks[i].address);
        }
    }
}

int main() {
    char *inputBuffer = (char *)customMalloc(MAX_INPUT_SIZE * sizeof(char));
    if (inputBuffer == NULL) return EXIT_FAILURE;

    printf("Enter some text (max %d characters): ", MAX_INPUT_SIZE - 1);
    fgets(inputBuffer, MAX_INPUT_SIZE, stdin);
    
    // Remove potential newline character from input
    inputBuffer[strcspn(inputBuffer, "\n")] = 0;
    printf("You entered: %s\n", inputBuffer);
    
    // Display memory status
    printMemoryStatus();
    
    // Allocate an array of integers
    size_t arraySize = 5;
    int *numbers = (int *)customMalloc(arraySize * sizeof(int));
    if (numbers == NULL) return EXIT_FAILURE;

    // Fill the array with values
    for (size_t i = 0; i < arraySize; i++) {
        numbers[i] = (int)(i * i);  // store square of index
    }

    // Print numbers
    printf("Numbers array: ");
    for (size_t i = 0; i < arraySize; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Free the memory
    customFree(numbers);
    customFree(inputBuffer);

    // Reprint memory status after freeing
    printMemoryStatus();
    
    return EXIT_SUCCESS;
}