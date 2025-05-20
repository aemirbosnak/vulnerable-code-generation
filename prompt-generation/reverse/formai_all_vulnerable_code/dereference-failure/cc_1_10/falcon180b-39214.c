//Falcon-180B DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MEMORY_SIZE 1000000

typedef struct {
    void* data;
    size_t size;
} MemoryBlock;

MemoryBlock* memory = (void*)0;
size_t memorySize = 0;

void* allocate(size_t size) {
    if (memorySize + size > MEMORY_SIZE) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    MemoryBlock* block = (void*)malloc(size + sizeof(MemoryBlock));
    block->data = (void*)((size_t)block + sizeof(MemoryBlock));
    block->size = size;

    memory = (void*)((size_t)memory + size + sizeof(MemoryBlock));
    memorySize += size + sizeof(MemoryBlock);

    return block->data;
}

void deallocate(void* data) {
    MemoryBlock* block = (void*)((size_t)data - sizeof(MemoryBlock));

    memory = (void*)((size_t)memory - block->size - sizeof(MemoryBlock));
    memorySize -= block->size + sizeof(MemoryBlock);

    free(block);
}

int main() {
    void* data1 = allocate(10);
    void* data2 = allocate(20);
    void* data3 = allocate(30);

    printf("Data1: %p\n", data1);
    printf("Data2: %p\n", data2);
    printf("Data3: %p\n", data3);

    deallocate(data2);

    printf("Data2 deallocated\n");

    void* data4 = allocate(40);

    printf("Data4: %p\n", data4);

    return 0;
}