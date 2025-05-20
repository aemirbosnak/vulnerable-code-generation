//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024

typedef struct {
    void* ptr;
    size_t size;
} MemBlock;

MemBlock mem_blocks[100];
int num_blocks = 0;

void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    mem_blocks[num_blocks].ptr = ptr;
    mem_blocks[num_blocks].size = size;
    num_blocks++;

    return ptr;
}

void my_free(void* ptr) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if (mem_blocks[i].ptr == ptr) {
            free(ptr);
            mem_blocks[i] = mem_blocks[num_blocks - 1];
            num_blocks--;
            return;
        }
    }
    printf("Error: invalid pointer passed to my_free.\n");
    exit(1);
}

int main() {
    // Allocate and fill an array of integers
    int* arr = (int*) my_malloc(10 * sizeof(int));
    int i;
    for (i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    // Print the array
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Allocate a large chunk of memory and fill it with zeroes
    char* buffer = (char*) my_malloc(CHUNK_SIZE);
    for (i = 0; i < CHUNK_SIZE; i++) {
        buffer[i] = 0;
    }

    // Free the memory
    my_free(arr);
    my_free(buffer);

    return 0;
}