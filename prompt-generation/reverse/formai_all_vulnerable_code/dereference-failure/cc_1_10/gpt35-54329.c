//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEMORY_SIZE 100 // Size of the memory

/* Memory block struct */
typedef struct mem_block {
    int id; // Block identification
    int size; // Block size
    struct mem_block* next; // Next block pointer
} mem_block;

/* Initial memory block */
mem_block* head = NULL;

/* Function to display the current memory state */
void display_memory() {
    mem_block* curr = head;
    printf("Memory Blocks:\n");
    while (curr != NULL) {
        printf("Block ID: %d | Size: %d\n", curr->id, curr->size);
        curr = curr->next;
    }
    printf("\n");
}

/* Function to allocate a memory block */
void allocate_memory(int id, int size) {
    mem_block* curr = head;
    mem_block* prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    if (head == NULL) { // Empty memory
        head = (mem_block*)malloc(sizeof(mem_block));
        head->id = id;
        head->size = size;
        head->next = NULL;
    }
    else if (prev != NULL && ((char*)prev + prev->size + sizeof(mem_block) + size) <= ((char*)head + MEMORY_SIZE)) { // Allocate block after the prev block
        prev->next = (mem_block*) ((char*) prev + prev->size + sizeof(mem_block));
        prev->next->id = id;
        prev->next->size = size;
        prev->next->next = NULL;
    }
    else if (prev == NULL && (char*)head + sizeof(mem_block) + size <= ((char*)head + MEMORY_SIZE)) { // Allocate block at the beginning of the memory
        mem_block* new_head = (mem_block*) ((char*)head + sizeof(mem_block));
        new_head->id = id;
        new_head->size = size;
        new_head->next = head;
        head = new_head;
    }
    else {
        printf("Not enough memory available to allocate block.\n\n");
        return;
    }
    printf("Block with ID %d allocated with size %d.\n\n", id, size);
}

/* Function to deallocate a memory block */
void deallocate_memory(int id) {
    mem_block* curr = head;
    mem_block* prev = NULL;
    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) { // Block not found
        printf("Block with ID %d not found in memory.\n\n", id);
        return;
    }
    if (curr == head) { // Block is the head
        head = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr);
    printf("Block with ID %d deallocated from memory.\n\n", id);
}

int main() {
    srand(time(0));
    // Allocate 3 blocks randomly
    allocate_memory(1, rand() % 20 + 1);
    allocate_memory(2, rand() % 20 + 1);
    allocate_memory(3, rand() % 20 + 1);
    display_memory();
    // Deallocate block with ID 2
    deallocate_memory(2);
    display_memory();
    // Attempt to allocate block that is too large
    allocate_memory(4, MEMORY_SIZE + 1);
    display_memory();
    return 0;
}