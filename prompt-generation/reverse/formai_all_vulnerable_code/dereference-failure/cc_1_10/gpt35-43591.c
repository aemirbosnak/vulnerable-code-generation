//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>

#define MAX_CHUNKS 10
#define CHUNK_SIZE 1024

// Define a data structure for chunks of memory
typedef struct {
    void* mem;
    int size;
    int is_free;
} mem_chunk;

// Define an array to hold all the chunks of memory
mem_chunk memory[MAX_CHUNKS];

// Define a function to initialize all the chunks of memory
void init_mem() {
    int i;
    for (i = 0; i < MAX_CHUNKS; i++) {
        memory[i].mem = malloc(CHUNK_SIZE);
        memory[i].size = CHUNK_SIZE;
        memory[i].is_free = 1;
    }
}

// Define a function to allocate a chunk of memory of the given size
void* my_malloc(int size) {
    int i;
    for (i = 0; i < MAX_CHUNKS; i++) {
        if (memory[i].is_free && memory[i].size >= size) {
            memory[i].is_free = 0;
            return memory[i].mem;
        }
    }
    return NULL;
}

// Define a function to free a chunk of memory
void my_free(void* ptr) {
    int i;
    for (i = 0; i < MAX_CHUNKS; i++) {
        if (memory[i].mem == ptr) {
            memory[i].is_free = 1;
            return;
        }
    }
}

int main() {
    init_mem();

    char* str = my_malloc(sizeof(char) * 10);
    str = "hello";

    int* nums = my_malloc(sizeof(int) * 3);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;

    my_free(str);
    my_free(nums);

    return 0;
}