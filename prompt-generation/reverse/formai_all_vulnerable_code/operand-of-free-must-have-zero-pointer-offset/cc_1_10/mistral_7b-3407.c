//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#define HEAP_SIZE 1024
#define STACK_SIZE 1024

typedef struct {
    int32_t size;
    uint8_t data[1];
} heap_block;

void* heap_start;
void* stack_end;
heap_block* current_heap_block;
void* current_heap_ptr;

void init() {
    heap_start = malloc(HEAP_SIZE);
    if (heap_start == NULL) {
        printf("Error: Heap allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    current_heap_block = (heap_block*)heap_start;
    current_heap_ptr = heap_start;
}

void* allocate(size_t size) {
    size_t new_size = (sizeof(heap_block) + size);

    if ((current_heap_ptr + new_size > (heap_start + HEAP_SIZE))) {
        printf("Error: Out of heap memory!\n");
        exit(EXIT_FAILURE);
    }

    current_heap_block->size = (int32_t)new_size;
    current_heap_block->data[0] = 0;

    current_heap_ptr += new_size;
    current_heap_block++;

    return (void*)((uint8_t*)current_heap_block->data);
}

void print_ram_usage() {
    void* stack_start = &stack_end;
    size_t stack_size = (size_t)((uint8_t*)stack_start - (uint8_t*)0);

    size_t used_ram = (size_t)(current_heap_ptr - heap_start);

    printf("RAM Usage:\n");
    printf("-----------\n");
    printf("Stack:     %d bytes\n", stack_size);
    printf("Heap:      %d bytes\n", used_ram);
    printf("Total:     %d bytes\n", stack_size + used_ram);
}

int main() {
    init();

    char* str = (char*)allocate(100);
    strcpy(str, "Hello, World!");

    print_ram_usage();

    free(str);

    print_ram_usage();

    return 0;
}