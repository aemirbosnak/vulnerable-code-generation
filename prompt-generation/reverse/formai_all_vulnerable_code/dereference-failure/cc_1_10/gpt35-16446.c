//FormAI DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr1, *ptr2, *ptr3;
    ptr1 = (int*) malloc(10 * sizeof(int)); // allocating memory for ptr1
    ptr2 = (int*) calloc(5, sizeof(int)); // allocating memory for ptr2 and initializing values to 0
    ptr3 = (int*) realloc(ptr1, 20 * sizeof(int)); // reallocating memory for ptr1

    if(ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) // checking if memory allocation was successful
    {
        printf("Memory allocation unsuccessful\n");
        exit(0);
    }

    /* Storing values in allocated memory */
    for(int i = 0; i < 10; i++)
    {
        *(ptr1 + i) = i + 1;
    }

    for(int i = 0; i < 5; i++)
    {
        *(ptr2 + i) = i + 1;
    }

    for(int i = 10; i < 20; i++)
    {
        *(ptr3 + i) = i + 1;
    }

    /* Printing values stored in allocated memory */
    printf("Values in ptr1:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", *(ptr1 + i));
    }

    printf("\nValues in ptr2:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr2 + i));
    }

    printf("\nValues in ptr3:\n");
    for(int i = 0; i < 20; i++)
    {
        printf("%d ", *(ptr3 + i));
    }

    /* Freeing allocated memory */
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}