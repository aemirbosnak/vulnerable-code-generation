//FormAI DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// structure for keeping track of memory allocation
struct mem_block {
    void *ptr;
    size_t size;
    char file_name[100];
    int line_num;
};

// global array to store memory blocks
struct mem_block mem_blocks[MAX_SIZE];

// global counter to keep track of number of allocated memory blocks
int num_blocks = 0;

// function to add a memory block to the list
void add_mem_block(void *ptr, size_t size, char *file_name, int line_num) {
    struct mem_block *block = &mem_blocks[num_blocks++];
    block->ptr = ptr;
    block->size = size;
    strncpy(block->file_name, file_name, 99);
    block->line_num = line_num;
}

// function to remove a memory block from the list
void remove_mem_block(void *ptr) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (mem_blocks[i].ptr == ptr) {
            // shift all blocks after this one down one index
            memmove(mem_blocks + i, mem_blocks + i + 1, (num_blocks - i - 1) * sizeof(struct mem_block));
            num_blocks--;
            break;
        }
    }
}

// overridden version of malloc that keeps track of memory allocation
void *introspective_malloc(size_t size, char *file_name, int line_num) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        add_mem_block(ptr, size, file_name, line_num);
    }
    return ptr;
}

// overridden version of free that keeps track of memory deallocation
void introspective_free(void *ptr) {
    if (ptr != NULL) {
        remove_mem_block(ptr);
        free(ptr);
    }
}

// overridden version of realloc that keeps track of memory reallocation
void *introspective_realloc(void *ptr, size_t size, char *file_name, int line_num) {
    void *new_ptr = realloc(ptr, size);
    if (new_ptr != NULL) {
        // if the memory block was reallocated, remove it from the list and add the new one
        if (new_ptr != ptr) {
            remove_mem_block(ptr);
            add_mem_block(new_ptr, size, file_name, line_num);
        }
        // otherwise, adjust the size of the existing block
        else {
            int i;
            for (i = 0; i < num_blocks; i++) {
                if (mem_blocks[i].ptr == ptr) {
                    mem_blocks[i].size = size;
                    break;
                }
            }
        }
    }
    return new_ptr;
}

// main function for testing
int main() {
    int *int_ptr = introspective_malloc(sizeof(int), __FILE__, __LINE__);
    *int_ptr = 42;
    printf("int_ptr=%p, *int_ptr=%d\n", int_ptr, *int_ptr);
    introspective_free(int_ptr);
    char *string = introspective_malloc(100, __FILE__, __LINE__);
    strcpy(string, "Hello, world!");
    printf("string=%p, %s\n", string, string);
    char *new_string = introspective_realloc(string, 200, __FILE__, __LINE__);
    printf("string=%p, %s\n", string, string);
    printf("new_string=%p, %s\n", new_string, new_string);
    introspective_free(new_string);
    return 0;
}