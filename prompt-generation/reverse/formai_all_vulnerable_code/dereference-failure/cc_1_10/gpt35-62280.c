//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a struct to store information about each allocated block of memory
typedef struct {
    void *ptr;
    size_t size;
} MemBlock;

// Global array to store information about each allocated block
MemBlock memory[MAX_SIZE];
int num_blocks = 0;

// Search for an unallocated block of memory of the given size
void* find_memory(size_t size) {
    for (int i = 0; i < num_blocks; i++) {
        if (memory[i].ptr == NULL && memory[i].size >= size) {
            return i;
        }
    }
    return NULL;
}

// Allocate a block of memory of the given size
void* my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    int index = find_memory(size);
    if (index == NULL) {
        if (num_blocks < MAX_SIZE) {
            index = num_blocks++;
        } else {
            free(ptr);
            return NULL;
        }
    }
    memory[index].ptr = ptr;
    memory[index].size = size;
    return ptr;
}

// Free a previously allocated block of memory
void my_free(void *ptr) {
    for (int i = 0; i < num_blocks; i++) {
        if (memory[i].ptr == ptr) {
            free(ptr);
            memory[i].ptr = NULL;
            memory[i].size = 0;
            break;
        }
    }
}

// Main program to test the memory management functions
int main() {
    int *arr1 = (int*) my_malloc(10 * sizeof(int));
    int *arr2 = (int*) my_malloc(20 * sizeof(int));
    double *arr3 = (double*) my_malloc(5 * sizeof(double));
    printf("arr1=%p, arr2=%p, arr3=%p\n", arr1, arr2, arr3);
    my_free(arr1);
    my_free(arr3);
    float *arr4 = (float*) my_malloc(15 * sizeof(float));
    printf("arr4=%p\n", arr4);
    return 0;
}