//FormAI DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1, *ptr2, *ptr3, *ptr4;

    // Allocate memory blocks
    ptr1 = (int*)malloc(5 * sizeof(int));
    ptr2 = (int*)calloc(10, sizeof(int));
    ptr3 = (int*)realloc(ptr2, 15 * sizeof(int));
    ptr4 = (int*)malloc(20 * sizeof(int));

    // Print the starting addresses of the memory blocks
    printf("Starting Address of ptr1: %p\n", ptr1);
    printf("Starting Address of ptr2: %p\n", ptr2);
    printf("Starting Address of ptr3: %p\n", ptr3);
    printf("Starting Address of ptr4: %p\n", ptr4);

    // Free ptr2 and reallocate its memory block
    free(ptr2);
    ptr2 = (int*)realloc(NULL, 15 * sizeof(int));

    // Print the addresses of ptr2 before and after reallocation
    printf("\nAddress of ptr2 before reallocation: %p\n", ptr2);
    ptr2 = (int*)realloc(ptr2, 20 * sizeof(int));
    printf("Address of ptr2 after reallocation: %p\n", ptr2);

    // Fill the memory blocks with random values
    for(int i = 0; i < 5; i++)
    {
        *(ptr1 + i) = rand() % 100;
    }

    for(int i = 0; i < 15; i++)
    {
        *(ptr3 + i) = rand() % 1000;
    }

    for(int i = 0; i < 20; i++)
    {
        *(ptr4 + i) = rand() % 10;
    }

    // Print the contents of the memory blocks
    printf("\nContents of ptr1: ");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr1 + i));
    }

    printf("\nContents of ptr3: ");
    for(int i = 0; i < 15; i++)
    {
        printf("%d ", *(ptr3 + i));
    }

    printf("\nContents of ptr4: ");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ", *(ptr4 + i));
    }

    // Deallocate memory blocks
    free(ptr1);
    free(ptr3);
    free(ptr4);

    return 0;
}