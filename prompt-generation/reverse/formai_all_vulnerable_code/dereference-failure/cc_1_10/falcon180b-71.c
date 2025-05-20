//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RAM 1000000 // 1 MB

typedef struct {
    void* pointer;
    size_t size;
} Allocation;

Allocation* allocations = NULL;
size_t num_allocations = 0;
size_t total_allocated = 0;

void init() {
    allocations = malloc(sizeof(Allocation));
    if (allocations == NULL) {
        printf("Error: Could not allocate memory for allocations.\n");
        exit(1);
    }
    num_allocations = 0;
    total_allocated = 0;
}

void add_allocation(void* ptr, size_t size) {
    if (num_allocations >= MAX_RAM) {
        printf("Warning: Maximum RAM usage reached.\n");
        return;
    }

    Allocation* new_alloc = realloc(allocations, sizeof(Allocation) * (num_allocations + 1));
    if (new_alloc == NULL) {
        printf("Error: Could not reallocate memory for allocations.\n");
        exit(1);
    }
    allocations = new_alloc;

    new_alloc = &allocations[num_allocations];
    new_alloc->pointer = ptr;
    new_alloc->size = size;
    total_allocated += size;
    num_allocations++;
}

void remove_allocation(void* ptr) {
    for (int i = 0; i < num_allocations; i++) {
        if (allocations[i].pointer == ptr) {
            total_allocated -= allocations[i].size;
            for (int j = i; j < num_allocations - 1; j++) {
                allocations[j] = allocations[j + 1];
            }
            num_allocations--;
            return;
        }
    }
}

void print_allocations() {
    printf("Total allocations: %zu\n", num_allocations);
    printf("Total allocated memory: %zu bytes\n", total_allocated);
    for (int i = 0; i < num_allocations; i++) {
        printf("%p (%zu bytes)\n", allocations[i].pointer, allocations[i].size);
    }
}

int main() {
    init();

    void* ptr1 = malloc(100);
    void* ptr2 = malloc(200);
    void* ptr3 = malloc(300);

    add_allocation(ptr1, 100);
    add_allocation(ptr2, 200);
    add_allocation(ptr3, 300);

    print_allocations();

    free(ptr1);
    free(ptr2);
    free(ptr3);

    print_allocations();

    return 0;
}