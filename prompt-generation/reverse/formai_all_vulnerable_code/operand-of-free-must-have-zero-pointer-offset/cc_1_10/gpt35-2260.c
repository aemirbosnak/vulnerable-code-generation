//FormAI DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024 // size of our memory pool

void *memory_pool = NULL; // create a pointer to the memory pool
int available_size = SIZE; // total available memory

void* my_malloc(int size) {
    void *allocated_memory = NULL;
  
    if (size <= available_size) { // check if we have enough free memory
        allocated_memory = memory_pool; // allocate memory from the start of the memory pool
        memory_pool += size; // increase the pointer to the next free memory
        available_size -= size; // reduce the available size
    }
  
    return allocated_memory; // return the newly allocated memory
}

void my_free(void *memory) {
    if (memory >= memory_pool && memory < memory_pool + SIZE) {// check if given memory is within our memory pool
        available_size += memory - memory_pool; // increase the available size by the freed memory
        memory_pool = memory; // move the pointer back to the start of the freed memory
    }
}

int main() {
    memory_pool = malloc(SIZE); // allocate memory pool

    int *a = my_malloc(sizeof(int)); // allocate integer pointer
    *a = 10; // assign value
    printf("a = %d\n", *a);

    float *b = my_malloc(sizeof(float)); // allocate float pointer
    *b = 10.5; // assign value
    printf("b = %f\n", *b);

    my_free(b); // free float pointer
    b = NULL; // set pointer to NULL

    char *c = my_malloc(sizeof(char)); // allocate char pointer
    *c = 'A'; // assign value
    printf("c = %c\n", *c);

    my_free(a); // free integer pointer
    a = NULL; // set pointer to NULL

    my_free(c); // free char pointer
    c = NULL; // set pointer to NULL

    free(memory_pool); // free memory pool

    return 0;
}