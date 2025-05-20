//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocator that uses a linked list to track allocated memory.
typedef struct memory_block {
    void* ptr;
    size_t size;
    struct memory_block* next;
} memory_block;

memory_block* head = NULL;

void* my_malloc(size_t size) {
    // Allocate a new memory block.
    memory_block* block = malloc(sizeof(memory_block));
    block->ptr = malloc(size);
    block->size = size;

    // Add the new block to the linked list.
    block->next = head;
    head = block;

    // Return the pointer to the allocated memory.
    return block->ptr;
}

void my_free(void* ptr) {
    // Find the memory block that contains the given pointer.
    memory_block* block = head;
    while (block != NULL && block->ptr != ptr) {
        block = block->next;
    }

    // Free the memory block.
    if (block != NULL) {
        head = block->next;
        free(block->ptr);
        free(block);
    }
}

// Define a custom data structure that uses the custom memory allocator.
typedef struct my_struct {
    int a;
    char* b;
} my_struct;

// Create an instance of the custom data structure.
my_struct* my_struct_create() {
    // Allocate memory for the data structure.
    my_struct* s = my_malloc(sizeof(my_struct));

    // Initialize the data structure.
    s->a = 0;
    s->b = NULL;

    // Return the data structure.
    return s;
}

// Free an instance of the custom data structure.
void my_struct_free(my_struct* s) {
    // Free the memory allocated for the data structure.
    my_free(s->b);
    my_free(s);
}

// Use the custom data structure.
int main() {
    // Create an instance of the custom data structure.
    my_struct* s = my_struct_create();

    // Access the members of the data structure.
    printf("a: %d\n", s->a);
    printf("b: %s\n", s->b);

    // Free the instance of the custom data structure.
    my_struct_free(s);

    return 0;
}