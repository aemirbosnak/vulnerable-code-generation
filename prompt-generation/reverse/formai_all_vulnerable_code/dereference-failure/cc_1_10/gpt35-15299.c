//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int size;
    int *ptr;
} memory_block;

void print_buffer(memory_block *buffer, int n) {
    printf("Memory buffer size: %d\n", buffer->size);
    printf("Memory buffer content: [");
    for(int i=0; i<n; i++) {
        printf("%d", buffer->ptr[i]);
        if(i<n-1) printf(", ");
    }
    printf("]\n");
}

void merge_blocks(memory_block *block1, memory_block *block2) {
    int new_size = block1->size + block2->size;
    int *new_ptr = (int*)realloc(block1->ptr, new_size*sizeof(int));
    if(new_ptr == NULL) {
        printf("Error: Failed to allocate memory!\n");
        return;
    }

    for(int i=0; i<block2->size; i++) {
        new_ptr[block1->size+i] = block2->ptr[i];
    }

    block1->size = new_size;
    block1->ptr = new_ptr;
    free(block2->ptr);
}

int main() {
    srand(time(NULL)); //seed the random function

    //initialize memory blocks
    int buffer_size = 100;
    memory_block *block1 = (memory_block*)malloc(sizeof(memory_block));
    memory_block *block2 = (memory_block*)malloc(sizeof(memory_block));
    block1->size = 30;
    block1->ptr = (int*)malloc(block1->size*sizeof(int));
    for(int i=0; i<block1->size; i++) {
        block1->ptr[i] = rand()%100; //generate random numbers for block1
    }
    block2->size = 50;
    block2->ptr = (int*)malloc(block2->size*sizeof(int));
    for(int i=0; i<block2->size; i++) {
        block2->ptr[i] = rand()%100; //generate random numbers for block2
    }

    //print initial memory buffer
    printf("Initial memory buffer:\n");
    print_buffer(block1, block1->size);
    print_buffer(block2, block2->size);

    //merge blocks
    merge_blocks(block1, block2);

    //print final memory buffer
    printf("Final memory buffer:\n");
    print_buffer(block1, block1->size);

    //free memory blocks
    free(block1->ptr);
    free(block1);
    free(block2);  
    return 0;
}