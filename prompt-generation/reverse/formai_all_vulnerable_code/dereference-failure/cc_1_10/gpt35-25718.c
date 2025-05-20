//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include<stdio.h> 

#define MEM_SIZE 1000  //total memory size 

//Structure to store memory block information
typedef struct mem_block {
    int start, end, size; 
    struct mem_block *next; 
} memory;

memory *head = NULL;  //start of the memory list 
memory *tail = NULL;  //end of the memory list 

void mem_init() {
    head = (memory *) malloc(sizeof(memory)); 
    head->start = 0; 
    head->end = MEM_SIZE - 1; 
    head->size = MEM_SIZE; 
    head->next = NULL; 
    tail = head; 
}

void mem_alloc(int size, char *tag) {
    memory *block = head; 
    while (block != NULL) {
        if (block->size >= size) {
            printf("Memory allocated for %s size = %d start = %d end = %d\n", tag, size, block->start, block->start + size - 1); 
            //update the block information 
            block->start += size; 
            block->size -= size; 
            //add new block to the list 
            memory *new_block = (memory *) malloc(sizeof(memory)); 
            new_block->start = block->start - size; 
            new_block->end = new_block->start + size - 1; 
            new_block->size = size; 
            new_block->next = block; 
            //update the previous block to point to the new block 
            if (tail == block) {
                tail = new_block; 
            }
            else {
                memory *prev_block = head; 
                while (prev_block->next != block) {
                    prev_block = prev_block->next; 
                }
                prev_block->next = new_block; 
            }
            break; 
        }
        block = block->next; 
    }
    if (block == NULL) {
        printf("Memory allocation failed for %s size = %d\n", tag, size); 
    }
}

void mem_free(char *tag) {
    memory *block = head; 
    memory *prev_block = NULL; 
    while (block != NULL) {
        if (strcmp(tag, "") == 0 || strcmp(tag, "") == 0 || strcmp(tag, "") == 0 || strcmp(tag, "") == 0) {
            //if tag is empty or matches the tag of the block 
            if (prev_block == NULL) {
                head = block->next; 
            }
            else {
                prev_block->next = block->next; 
            }
            free(block); 
            printf("Memory freed for %s\n", tag); 
            break; 
        }
        prev_block = block; 
        block = block->next; 
    }
    if (block == NULL) {
        printf("No memory block found for %s\n", tag); 
    }
}

void mem_print() {
    memory *block = head; 
    while (block != NULL) {
        printf("Block start = %d end = %d size = %d\n", block->start, block->end, block->size); 
        block = block->next; 
    }
}

int main() {
    mem_init(); 
    mem_alloc(100, "first block"); 
    mem_alloc(200, "second block"); 
    mem_alloc(50, "third block"); 
    mem_alloc(150, "fourth block"); 
    mem_print(); 
    mem_free("second block"); 
    mem_alloc(50, "fifth block"); 
    mem_free(""); 
    mem_print(); 
    return 0; 
}