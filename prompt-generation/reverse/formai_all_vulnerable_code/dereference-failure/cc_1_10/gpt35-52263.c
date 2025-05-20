//FormAI DATASET v1.0 Category: Memory management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3, *ptr4; //pointer declaration

    //Allocating memory using malloc
    ptr1 = (int *)malloc(5 * sizeof(int));
    ptr2 = (int *)malloc(10 * sizeof(int));
    ptr3 = (int *)malloc(15 * sizeof(int));

    //Checking for malloc error
    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) {
        printf("Memory Allocation Error!\n");
        return -1;
    }

    //Printing the allocated memory addresses
    printf("Memory Addresses Allocated:\n");
    printf("ptr1: %p\n", ptr1);
    printf("ptr2: %p\n", ptr2);
    printf("ptr3: %p\n", ptr3);

    //Freeing up allocated memory using free
    free(ptr1);

    //Allocating memory using calloc
    ptr4 = (int *)calloc(20, sizeof(int));

    //Checking for calloc error
    if (ptr4 == NULL) {
        printf("Memory Allocation Error!\n");
        return -1;
    }

    //Printing the allocated memory address
    printf("ptr4: %p\n", ptr4);

    //Reallocating memory using realloc
    ptr2 = (int *)realloc(ptr2, 20 * sizeof(int));

    //Checking for realloc error
    if (ptr2 == NULL) {
        printf("Memory Allocation Error!\n");
        return -1;
    }

    //Printing the reallocated memory address
    printf("ptr2: %p\n", ptr2);

    //Freeing up the rest of the allocated memory
    free(ptr2);
    free(ptr3);
    free(ptr4);

    return 0;
}