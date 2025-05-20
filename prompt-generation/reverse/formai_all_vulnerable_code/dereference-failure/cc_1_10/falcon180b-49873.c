//Falcon-180B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the memory block
#define MEMORY_BLOCK_SIZE 1024

// Define the structure of a memory block
typedef struct MemoryBlock {
    size_t size;
    int is_available;
    struct MemoryBlock* next;
} MemoryBlock;

// Define the head of the linked list
MemoryBlock* head = NULL;

// Function to initialize the memory management system
void init() {
    head = (MemoryBlock*)malloc(sizeof(MemoryBlock));
    head->size = MEMORY_BLOCK_SIZE;
    head->is_available = 1;
    head->next = NULL;
}

// Function to allocate memory
void* malloc(size_t size) {
    MemoryBlock* current = head;
    while (current!= NULL) {
        if (current->size >= size && current->is_available == 1) {
            current->is_available = 0;
            void* result = (void*)((char*)current + sizeof(MemoryBlock));
            return result;
        }
        current = current->next;
    }
    printf("Out of memory!\n");
    return NULL;
}

// Function to free memory
void free(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    MemoryBlock* current = head;
    while (current!= NULL) {
        if ((char*)current <= ptr && (char*)current + current->size >= ptr) {
            current->is_available = 1;
            return;
        }
        current = current->next;
    }
}

// Main function
int main() {
    init();
    void* p1 = malloc(100);
    void* p2 = malloc(200);
    void* p3 = malloc(300);
    free(p1);
    free(p3);
    void* p4 = malloc(400);
    free(p2);
    free(p4);
    return 0;
}