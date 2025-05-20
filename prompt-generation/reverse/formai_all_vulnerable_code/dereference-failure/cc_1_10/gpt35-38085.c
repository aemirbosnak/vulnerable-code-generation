//FormAI DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 1024 // Total memory size 
#define BLOCK_SIZE 64 // Size of each block
#define NUM_BLOCKS MEM_SIZE/BLOCK_SIZE // Number of blocks

// Struct for each block of memory
typedef struct {
    int in_use; // 0 for available, 1 for in use
    int size; // size of the memory block in bytes
} block;

// Initialize all blocks of memory
void init_memory(block* memory) {
    for(int i = 0; i < NUM_BLOCKS; i++) {
        memory[i].in_use = 0;
        memory[i].size = BLOCK_SIZE;
    }
}

// Find the largest available block of memory
int find_largest_available(block* memory) {
    int largest_block_size = 0;
    int index = -1;
    for(int i = 0; i < NUM_BLOCKS; i++) {
        if(memory[i].in_use == 0 && memory[i].size > largest_block_size) {
            largest_block_size = memory[i].size;
            index = i;
        }
    }
    return index;
}

// Allocate memory of size 'size'
int my_malloc(block* memory, int size) {
    // Find the largest available block
    int index = find_largest_available(memory);
    if(index == -1 || memory[index].size < size) {
        // No available block or no block is large enough
        return -1;
    }
    memory[index].in_use = 1;
    // If the block is larger than size, split it into two blocks
    if(memory[index].size > size) {
        int new_index = index + (size/BLOCK_SIZE) + (size % BLOCK_SIZE ? 1 : 0);
        memory[new_index].in_use = 0;
        memory[new_index].size = memory[index].size - size;
        memory[index].size = size;
    }
    return index*BLOCK_SIZE;
}

// Free memory at address 'addr'
void my_free(block* memory, int addr) {
    int index = addr/BLOCK_SIZE;
    memory[index].in_use = 0;
    // If the adjacent block is also free, merge them
    if(index < NUM_BLOCKS - 1 && memory[index+1].in_use == 0) {
        memory[index].size += memory[index+1].size;
        memory[index+1].size = BLOCK_SIZE;
    }
}

int main() {
    // Initialize memory
    block* memory = malloc(sizeof(block) * NUM_BLOCKS);
    init_memory(memory);

    // Allocate and free memory
    int addr1 = my_malloc(memory, 320);
    int addr2 = my_malloc(memory, 128);
    int addr3 = my_malloc(memory, 512);
    my_free(memory, addr1);
    my_free(memory, addr3);
    int addr4 = my_malloc(memory, 256);
    
    // Check if memory is correctly allocated and freed
    printf("Address 1: %d\n", addr1); // should be -1
    printf("Address 2: %d\n", addr2); // should be 0
    printf("Address 3: %d\n", addr3); // should be 256
    printf("Address 4: %d\n", addr4); // should be 320
    printf("Block 0 in use: %d, size: %d\n", memory[0].in_use, memory[0].size); // should be 0, 64
    printf("Block 1 in use: %d, size: %d\n", memory[1].in_use, memory[1].size); // should be 1, 256
    printf("Block 3 in use: %d, size: %d\n", memory[3].in_use, memory[3].size); // should be 0, 192

    // Free memory and clean up
    free(memory);
    return 0;
}