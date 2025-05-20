//FormAI DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct MemoryBlock {
    int id;
    int size;
    char* data;
    struct MemoryBlock* next;
};

struct MemoryMap {
    int total_size;
    struct MemoryBlock* blocks;
};

struct SystemMemory {
    int total_size;
    char* data;
};

struct MemoryMap* memory_map;
struct SystemMemory* system_memory;

void initialize_memory_map() {
    memory_map = (struct MemoryMap*) malloc(sizeof(struct MemoryMap));
    memory_map->total_size = 1024;
    memory_map->blocks = NULL;
}

void initialize_system_memory() {
    system_memory = (struct SystemMemory*) malloc(sizeof(struct SystemMemory));
    system_memory->total_size = 4096;
    system_memory->data = (char*) malloc(system_memory->total_size);
}

void* my_malloc(int size) {
    if (memory_map->total_size <= 0 || size <= 0) {
        return NULL;
    }

    struct MemoryBlock* block = memory_map->blocks;
    struct MemoryBlock* previous_block = NULL;

    while (block != NULL) {
        if (block->size >= size) {
            block->size -= size;
            char* data = block->data + block->size;
            block->next = (struct MemoryBlock*) malloc(sizeof(struct MemoryBlock));
            block->next->id = block->id + 1;
            block->next->size = size;
            block->next->data = data;
            block->next->next = NULL;
            return data;
        }
        previous_block = block;
        block = block->next;
    }

    if (previous_block == NULL) {
        memory_map->blocks = (struct MemoryBlock*) malloc(sizeof(struct MemoryBlock));
        memory_map->blocks->id = 1;
        memory_map->blocks->size = size;
        memory_map->blocks->data = system_memory->data + system_memory->total_size - size;
        memory_map->blocks->next = NULL;
    } else {
        previous_block->next = (struct MemoryBlock*) malloc(sizeof(struct MemoryBlock));
        previous_block->next->id = previous_block->id + 1;
        previous_block->next->size = size;
        previous_block->next->data = previous_block->data - size;
        previous_block->next->next = NULL;
    }

    memory_map->total_size -= size;
    return memory_map->blocks->data;
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    struct MemoryBlock* block = memory_map->blocks;
    struct MemoryBlock* previous_block = NULL;

    while (block != NULL) {
        if (block->data == ptr) {
            memory_map->total_size += block->size;
            if (previous_block == NULL) {
                memory_map->blocks = block->next;
            } else {
                previous_block->next = block->next;
            }
            free(block);
            return;
        }
        previous_block = block;
        block = block->next;
    }
}

int main() {
    initialize_system_memory();
    initialize_memory_map();
    
    char* data = (char*) my_malloc(8);
    printf("Allocated memory block at address %p with size of 8 bytes\n", data);

    char* data2 = (char*) my_malloc(16);
    printf("Allocated memory block at address %p with size of 16 bytes\n", data2);

    my_free(data);
    printf("Freed memory block at address %p\n", data);

    char* data3 = (char*) my_malloc(4);
    printf("Allocated memory block at address %p with size of 4 bytes\n", data3);    

    return 0;
}