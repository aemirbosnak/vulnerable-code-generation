//Falcon-180B DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our custom memory manager struct
typedef struct {
    void* start;
    size_t size;
    size_t used;
} MemoryManager;

// Initialize our memory manager
void init_memory_manager(MemoryManager* manager, size_t size) {
    manager->start = malloc(size);
    manager->size = size;
    manager->used = 0;
}

// Allocate memory from our custom memory manager
void* my_malloc(MemoryManager* manager, size_t size) {
    if (manager->used + size > manager->size) {
        printf("Out of memory!\n");
        return NULL;
    }

    void* result = (void*) ((char*) manager->start + manager->used);
    manager->used += size;

    return result;
}

// Free memory allocated from our custom memory manager
void my_free(MemoryManager* manager, void* ptr) {
    if (ptr < manager->start || ptr >= (void*) ((char*) manager->start + manager->size)) {
        printf("Invalid pointer!\n");
        return;
    }

    manager->used -= (size_t) ((char*) ptr - (char*) manager->start);
}

int main() {
    MemoryManager manager;
    init_memory_manager(&manager, 1024); // Initialize with 1KB of memory

    void* ptr1 = my_malloc(&manager, 64);
    void* ptr2 = my_malloc(&manager, 128);
    void* ptr3 = my_malloc(&manager, 256);

    if (ptr1 && ptr2 && ptr3) {
        printf("Successfully allocated 3 blocks of memory!\n");
    } else {
        printf("Failed to allocate memory...\n");
    }

    my_free(&manager, ptr1);
    my_free(&manager, ptr2);
    my_free(&manager, ptr3);

    return 0;
}