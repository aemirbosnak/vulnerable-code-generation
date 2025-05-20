//FormAI DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 1000

typedef struct Block{
    struct Block* next_block;
    int size;
    char data[BLOCK_SIZE];
} Block;

Block* head = NULL;

void* invasive_malloc(int size){
    Block* curr_block = head;
    Block* prev_block = NULL;

    while(curr_block != NULL){
        if(curr_block->size >= size){
            if(curr_block->size - size >= sizeof(Block)){
                //split block into two blocks
                Block* new_block = (Block*)((char*)curr_block + sizeof(Block) + size);
                new_block->next_block = curr_block->next_block;
                new_block->size = curr_block->size - size - sizeof(Block);

                curr_block->size = size;

                if(prev_block == NULL){
                    //update head pointer
                    head = new_block;
                }else{
                    prev_block->next_block = new_block;
                }
            }

            //return pointer to current block
            return curr_block->data;
        }

        prev_block = curr_block;
        curr_block = curr_block->next_block;
    }

    //no block found, create a new block
    Block* new_block = malloc(sizeof(Block));
    new_block->next_block = head;
    new_block->size = BLOCK_SIZE;

    head = new_block;

    //try again with newly created block
    return invasive_malloc(size);
}

void invasive_free(void* ptr){
    Block* curr_block = head;
    Block* prev_block = NULL;

    while(curr_block != NULL){
        if(curr_block->data == (char*)ptr){
            //found block to be freed
            if(prev_block == NULL){
                //update head pointer
                head = curr_block->next_block;
            }else{
                prev_block->next_block = curr_block->next_block;
            }

            free(curr_block);
            return;
        }

        prev_block = curr_block;
        curr_block = curr_block->next_block;
    }
}

int main(){
    //allocate 10 blocks of memory
    void* ptrs[10];

    for(int i = 0; i < 10; i++){
        ptrs[i] = invasive_malloc(i + 1);
        printf("Allocated block of size %d at address %p\n", i + 1, ptrs[i]);
    }

    //free every other block
    for(int i = 0; i < 10; i += 2){
        invasive_free(ptrs[i]);
        printf("Freed block at address %p\n", ptrs[i]);
    }

    //re-allocate the previously freed blocks
    for(int i = 0; i < 10; i += 2){
        ptrs[i] = invasive_malloc(i + 1);
        printf("Allocated block of size %d at address %p\n", i + 1, ptrs[i]);
    }

    return 0;
}