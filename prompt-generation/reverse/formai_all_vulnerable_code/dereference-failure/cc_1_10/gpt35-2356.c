//FormAI DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct {
    size_t size;
    void *mem;
} Block;

Block heap[MAX_SIZE];
int heap_size = 0;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

Block create_block(size_t size) {
    Block block;
    block.size = size;
    block.mem = my_malloc(size);
    return block;
}

void *my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return my_malloc(size);
    }

    for (int i = 0; i < heap_size; i++) {
        if (heap[i].mem == ptr) {
            void *new_mem = realloc(ptr, size);
            if (new_mem == NULL) {
                printf("Error: Out of memory\n");
                exit(1);
            }
            heap[i].mem = new_mem;
            heap[i].size = size;
            return new_mem;
        }
    }

    printf("Error: Pointer not found\n");
    exit(1);
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    for (int i = 0; i < heap_size; i++) {
        if (heap[i].mem == ptr) {
            free(ptr);
            heap[i] = heap[--heap_size];
            return;
        }
    }

    printf("Error: Pointer not found\n");
    exit(1);
}

int main() {
    int *arr = (int *)my_malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }

    Block block1 = create_block(sizeof(double) * 100);
    double *d_arr = (double *)block1.mem;
    for (int i = 0; i < 100; i++) {
        d_arr[i] = (double)i / 2;
    }

    void *ptr = my_realloc(arr, sizeof(int) * 200);
    int *new_arr = (int *)ptr;
    for (int i = 100; i < 200; i++) {
        new_arr[i] = i;
    }

    my_free(arr);
    my_free(block1.mem);

    return 0;
}