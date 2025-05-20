//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 5

typedef struct MemoryBlock {
    void *ptr;
    size_t size;
} MemoryBlock;

MemoryBlock memory[MAX_MEMORY];
int memIndex = 0;

void *my_malloc(size_t size) {
    if (memIndex >= MAX_MEMORY) {
        fprintf(stderr, "Heap is full! Time to go dumpster diving for REAL memory!\n");
        return NULL;
    }

    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed! Maybe it was too much pizza last night?\n");
        return NULL;
    }

    memory[memIndex].ptr = ptr;
    memory[memIndex].size = size;
    memIndex++;

    printf("Allocated %zu bytes at %p. Current allocation count: %d\n", size, ptr, memIndex);
    return ptr;
}

void my_free(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Freeing NULL pointer? Are we just cleaning up imaginary friends?\n");
        return;
    }

    for (int i = 0; i < memIndex; i++) {
        if (memory[i].ptr == ptr) {
            free(ptr);
            printf("Freed %zu bytes from %p. Cleaning up after the party!\n", memory[i].size, ptr);
            memory[i].ptr = NULL; // Null as we freed the pointer
            memory[i].size = 0; // Size is now zero
            return;
        }
    }

    fprintf(stderr, "Pointer %p not found in our memory book! Is it running away from its responsibilities?\n", ptr);
}

void report_memory() {
    printf("Current memory allocations:\n");
    for (int i = 0; i < memIndex; i++) {
        if (memory[i].ptr != NULL) {
            printf(" - %zu bytes at %p\n", memory[i].size, memory[i].ptr);
        }
    }
    if (memIndex == 0) {
        printf("No memory is allocated! It's a ghost town here!\n");
    }
}

int main() {
    printf("Welcome to the Funny Memory Management Program!\n");

    void *p1 = my_malloc(100);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(300);
    void *p4 = my_malloc(400);
    void *p5 = my_malloc(500);

    report_memory();
    
    my_free(p2);
    my_free(p4);
    report_memory();

    p2 = my_malloc(150); // Trying to allocate again after freeing
    p3 = my_malloc(250);
    
    report_memory();
    
    my_free(p1);
    my_free(p3);
    my_free(p5);
    my_free(p2); // Freeing all remaining memory
    report_memory();

    printf("End of the Funny Memory Management Program! Remember, garbage collection is not just for your kitchen!\n");

    return 0;
}