//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

// Custom memory allocator with funny names for functions
typedef struct {
    void *mem_block;
    size_t size;
    char name[32];
} heckin_memory_block;

// Allocates memory with a funny name
heckin_memory_block *heckin_malloc(size_t size, const char *name) {
    heckin_memory_block *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (block == MAP_FAILED) {
        perror("Couldn't heckin' allocate memory, man!");
        return NULL;
    }
    strcpy(block->name, name);
    block->size = size;
    return block;
}

// Frees memory with a funny name
void heckin_free(heckin_memory_block *block) {
    if (munmap(block, block->size) == -1) {
        perror("Couldn't free heckin' memory, dang it!");
        exit(EXIT_FAILURE);
    }
}

// Main function with a funny story
int main() {
    heckin_memory_block *heap1 = heckin_malloc(1024, " heap1 - The Heckin' Hero");
    heckin_memory_block *heap2 = heckin_malloc(512, " heap2 - The Heckin' Hooligan");

    if (!heap1 || !heap2) {
        fprintf(stderr, "Couldn't allocate heckin' memory, sorry bud.\n");
        heckin_free(heap2);
        heckin_free(heap1);
        exit(EXIT_FAILURE);
    }

    printf("Heap1: %p, Heckin' size: %ld bytes, Heckin' name: %s\n", heap1, heap1->size, heap1->name);
    printf("Heap2: %p, Heckin' size: %ld bytes, Heckin' name: %s\n", heap2, heap2->size, heap2->name);

    // Do some funny stuff with the heaps
    char *message1 = (char *) heap1;
    strcpy(message1, "Hey, Heckin' Hero, save me from this heckin' situation!");
    char *message2 = (char *) heap2;
    strcpy(message2, "I'm a Heckin' Hooligan, and I'll heckin' wreck your day!");

    // Print out the messages
    printf("Message from Heap1: %s\n", message1);
    printf("Message from Heap2: %s\n", message2);

    // Free the heaps and exit
    heckin_free(heap2);
    heckin_free(heap1);

    return EXIT_SUCCESS;
}