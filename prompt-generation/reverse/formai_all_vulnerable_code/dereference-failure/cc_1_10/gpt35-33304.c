//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 1000
#define ALLOC_SIZE 20

struct Memory {
    int mem[MEM_SIZE];
    int num_allocs;
    int alloc_sizes[ALLOC_SIZE];
    int alloc_start[ALLOC_SIZE];
};

typedef struct Memory Memory;

Memory* init_memory() {
    Memory* mem = malloc(sizeof(Memory));
    mem->num_allocs = 0;
    return mem;
}

void* allocate_memory(Memory* mem, int size) {
    if (mem->num_allocs >= ALLOC_SIZE) {
        printf("Error: Memory limit reached. Cannot allocate more memory.\n");
        return NULL;
    }
    
    int start_index = -1;
    int end_index = -1;
    int i;
    for (i = 0; i < MEM_SIZE; i++) {
        if (mem->mem[i] == 0) {
            if (start_index == -1) {
                start_index = i;
            }
            end_index = i;
            if (end_index - start_index + 1 == size) {
                break;
            }
        }
        else {
            start_index = -1;
            end_index = -1;
        }
    }
    
    if (start_index == -1) {
        printf("Error: Not enough contiguous memory available.\n");
        return NULL;
    }
    
    void* alloc_ptr = &(mem->mem[start_index]);
    mem->num_allocs++;
    mem->alloc_sizes[mem->num_allocs-1] = size;
    mem->alloc_start[mem->num_allocs-1] = start_index;
    for (i = start_index; i <= end_index; i++) {
        mem->mem[i] = 1;
    }
    return alloc_ptr;
}

void free_memory(Memory* mem, void* ptr) {
    int start_index = (int)((char*)ptr - (char*)(&(mem->mem[0])));
    int size = -1;
    int i;
    for (i = 0; i < mem->num_allocs; i++) {
        if (mem->alloc_start[i] == start_index) {
            size = mem->alloc_sizes[i];
            mem->num_allocs--;
            if (i == mem->num_allocs) {
                break;
            }
            for (int j = i; j < mem->num_allocs; j++) {
                mem->alloc_sizes[j] = mem->alloc_sizes[j+1];
                mem->alloc_start[j] = mem->alloc_start[j+1];
            }
            break;
        }
    }
    if (size == -1) {
        printf("Error: Invalid memory address.\n");
        return;
    }
    for (i = start_index; i < start_index + size; i++) {
        mem->mem[i] = 0;
    }
}

void print_memory_status(Memory* mem) {
    printf("Memory Status:\n");
    printf("Number of allocations: %d\n", mem->num_allocs);
    for (int i = 0; i < mem->num_allocs; i++) {
        printf("   Allocation %d, size: %d, start index: %d\n", i+1, mem->alloc_sizes[i], mem->alloc_start[i]);
    }
    printf("\n");
}

int main() {
    Memory* mem = init_memory();
    printf("Initial Memory Status:\n");
    print_memory_status(mem);
    
    int* ptr_1 = (int*)allocate_memory(mem, 10 * sizeof(int));
    if (ptr_1 != NULL) {
        for (int i = 0; i < 10; i++) {
            *(ptr_1 + i) = i;
        }
    }
    printf("Memory Status after allocating space for 10 integers:\n");
    print_memory_status(mem);
    
    int* ptr_2 = (int*)allocate_memory(mem, 5 * sizeof(int));
    if (ptr_2 != NULL) {
        for (int i = 0; i < 5; i++) {
            *(ptr_2 + i) = i * 2;
        }
    }
    printf("Memory Status after allocating space for 5 integers:\n");
    print_memory_status(mem);
    
    free_memory(mem, ptr_1);
    printf("Memory Status after freeing space for first allocation:\n");
    print_memory_status(mem);
    
    int* ptr_3 = (int*)allocate_memory(mem, 7 * sizeof(int));
    if (ptr_3 != NULL) {
        for (int i = 0; i < 7; i++) {
            *(ptr_3 + i) = i * 3;
        }
    }
    printf("Memory Status after allocating space for 7 integers:\n");
    print_memory_status(mem);
    
    free_memory(mem, ptr_2);
    printf("Memory Status after freeing space for second allocation:\n");
    print_memory_status(mem);
    
    free_memory(mem, ptr_3);
    printf("Final Memory Status:\n");
    print_memory_status(mem);
    
    free(mem);
    return 0;
}