//Falcon-180B DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the block size
#define BLOCK_SIZE 8

// Define the maximum number of blocks
#define MAX_BLOCKS 100

// Define the memory pool
char* mem_pool[MAX_BLOCKS];

// Define the number of blocks currently in use
int num_blocks = 0;

// Function to initialize the memory pool
void init_mem_pool() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        mem_pool[i] = (char*) malloc(BLOCK_SIZE);
    }
}

// Function to allocate memory
char* alloc_mem(int size) {
    int i;
    char* mem = NULL;
    for (i = 0; i < num_blocks; i++) {
        if (mem_pool[i]!= NULL) {
            if (size <= BLOCK_SIZE - num_blocks * BLOCK_SIZE) {
                mem = mem_pool[i] + num_blocks * BLOCK_SIZE;
                num_blocks++;
                break;
            }
        }
    }
    if (mem == NULL) {
        printf("Memory exhausted!\n");
        exit(1);
    }
    return mem;
}

// Function to deallocate memory
void dealloc_mem(char* mem) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (mem_pool[i]!= NULL && mem >= mem_pool[i] && mem < mem_pool[i] + BLOCK_SIZE) {
            num_blocks--;
            break;
        }
    }
}

int main() {
    init_mem_pool();
    char* mem1 = alloc_mem(10);
    char* mem2 = alloc_mem(20);
    char* mem3 = alloc_mem(30);
    printf("Allocated memory: %p, %p, %p\n", mem1, mem2, mem3);
    dealloc_mem(mem2);
    printf("Deallocated memory at %p\n", mem2);
    char* mem4 = alloc_mem(40);
    printf("Allocated memory: %p\n", mem4);
    return 0;
}