//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_BLOCKS 1000
#define BLOCK_SIZE 1024

typedef struct {
    void* address;
    int size;
    int free;
} block_t;

block_t* blocks = NULL;
int num_blocks = 0;

void init() {
    blocks = malloc(MAX_NUM_BLOCKS * sizeof(block_t));
    if (blocks == NULL) {
        printf("Error: failed to allocate memory for block structs\n");
        exit(1);
    }
    num_blocks = 0;
}

void* my_malloc(int size) {
    void* result = NULL;
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (blocks[i].size == size && blocks[i].free) {
            blocks[i].free = 0;
            result = blocks[i].address;
            break;
        } else if (blocks[i].size > size) {
            void* new_address = (void*)((int)blocks[i].address + size);
            block_t* new_block = (block_t*)new_address;
            new_block->address = new_address;
            new_block->size = blocks[i].size - size;
            new_block->free = 1;
            blocks[i].size = size;
            result = blocks[i].address;
            num_blocks++;
            break;
        }
    }
    if (result == NULL) {
        void* new_block = malloc(size + sizeof(block_t));
        if (new_block == NULL) {
            printf("Error: failed to allocate memory\n");
            exit(1);
        }
        block_t* new_struct = (block_t*)new_block;
        new_struct->address = (void*)((int)new_block + sizeof(block_t));
        new_struct->size = size;
        new_struct->free = 0;
        blocks[num_blocks] = *new_struct;
        num_blocks++;
        result = new_struct->address;
    }
    return result;
}

void my_free(void* ptr) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (blocks[i].address == ptr) {
            blocks[i].free = 1;
            break;
        }
    }
}

int main() {
    init();
    void* ptr1 = my_malloc(512);
    void* ptr2 = my_malloc(1024);
    void* ptr3 = my_malloc(512);
    my_free(ptr1);
    my_free(ptr3);
    printf("Done.\n");
    return 0;
}