//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE sizeof(struct block)
#define HEAP_SIZE 1024

struct block {
    size_t size;
    int free;
    struct block* next;
};

void* heap; //Pointer for the first block of heap

void* my_malloc(size_t size);
void my_free(void* ptr);
void split(struct block* allocated, size_t size);

int main()
{
    //Initializing heap and block structure for the whole heap
    heap = malloc(HEAP_SIZE);
    struct block* start = (struct block*) heap;
    start->size = HEAP_SIZE - BLOCK_SIZE;
    start->free = 1;
    start->next = NULL;

    printf("Initial size for heap is: %lu\n", start->size);

    //Allocating memory using my malloc
    int* arr1 = (int*) my_malloc(5 * sizeof(int));
    int* arr2 = (int*) my_malloc(10 * sizeof(int));

    //Freeing arr1
    my_free(arr1);

    //Allocating memory again
    int* arr3 = (int*) my_malloc(3 * sizeof(int));

    //Freeing arr2
    my_free(arr2);

    //Allocating memory once again
    int* arr4 = (int*) my_malloc(15 * sizeof(int));

    //Freeing arr3
    my_free(arr3);

    //Allocating memory one last time
    int* arr5 = (int*) my_malloc(20 * sizeof(int));

    //Freeing arr4 and arr5
    my_free(arr4);
    my_free(arr5);

    return 0;
}

//Function for allocating memory
void* my_malloc(size_t size) {
    struct block* current = (struct block*) heap;
    struct block* previous = NULL;

    //Finding a free block on heap of suitable size
    while ((current->size < size || !current->free) && current->next != NULL) {
        previous = current;
        current = current->next;
    }

    //Returning NULL if there is no free block of suitable size
    if (current->size < size) {
        printf("Not enough space available on heap.\n");
        return NULL;
    }

    //If there is free block that can be splitted
    if (current->size >= size + BLOCK_SIZE) {
        split(current, size);
        current->free = 0;
    } else {
        current->free = 0;
    }
    printf("Memory allocated successfully to heap, block size = %lu\n", current->size);

    //Returning pointer to the allocated memory block
    return (void*) (current + 1);
}

//Function for splitting free block into 2 blocks to avoid internal fragmentation
void split(struct block* allocated, size_t size) {
    struct block* new_block = (struct block*) ((void*) allocated + BLOCK_SIZE + size);
    new_block->size = allocated->size - BLOCK_SIZE - size;
    new_block->free = 1;
    new_block->next = allocated->next;
    allocated->size = size;
    allocated->next = new_block;
}

//Function for freeing a memory block
void my_free(void* ptr) {
    if (ptr == NULL) {
        printf("Pointer is already NULL.\n");
        return;
    }

    //Finding the block whose memory is to be freed
    struct block* current_block = (struct block*) ptr - 1;
    struct block* current = (struct block*) heap;
    struct block* previous = NULL;
    int found = 0;

    while (current != NULL) {
        if (current == current_block) {
            found = 1;
            break;
        }
        previous = current;
        current = current->next;
    }

    //Returning error if block is not found
    if (!found) {
        printf("Block not found!\n");
        return;
    }

    //Marking block as free
    current_block->free = 1;
    printf("Memory freed for block of size = %lu\n", current_block->size);

    //Merging adjacent free blocks to avoid external fragmentation
    if (previous != NULL && previous->free) {
        previous->size += BLOCK_SIZE + current_block->size;
        previous->next = current_block->next;
        current_block = previous;
    }

    if (current_block->next != NULL && current_block->next->free) {
        current_block->size += BLOCK_SIZE + current_block->next->size;
        current_block->next = current_block->next->next;
    }
}