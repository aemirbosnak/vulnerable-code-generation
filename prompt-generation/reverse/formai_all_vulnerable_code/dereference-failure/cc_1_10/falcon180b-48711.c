//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000

int *heap;
int heap_size = 0;

void init_heap() {
    heap = (int *)malloc(HEAP_SIZE * sizeof(int));
    if (heap == NULL) {
        printf("Error: could not allocate memory for heap.\n");
        exit(1);
    }
    heap_size = HEAP_SIZE;
}

void *my_malloc(size_t size) {
    if (heap_size == 0) {
        init_heap();
    }

    void *result = malloc(size);

    if (result == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    return result;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    init_heap();

    int *ptr1 = (int *)my_malloc(sizeof(int));
    *ptr1 = 42;

    int *ptr2 = (int *)my_malloc(sizeof(int));
    *ptr2 = 69;

    printf("ptr1 = %p, value = %d\n", ptr1, *ptr1);
    printf("ptr2 = %p, value = %d\n", ptr2, *ptr2);

    my_free(ptr1);
    my_free(ptr2);

    return 0;
}