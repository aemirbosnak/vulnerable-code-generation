//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr1, *ptr2, *ptr3;

    // allocate memory of 10 integers dynamically
    ptr1 = (int*)malloc(10 * sizeof(int));

    // check if memory allocation was successful
    if (ptr1 == NULL)
    {
        printf("Memory allocation unsuccessful. Exiting...");
        exit(0);
    }
    
    // assign some values to the first 5 integers
    ptr1[0] = 1;
    ptr1[1] = 2;
    ptr1[2] = 3;
    ptr1[3] = 4;
    ptr1[4] = 5;

    // print the values of the first 5 integers
    printf("Values of the first 5 integers: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // allocate memory of 5 integers dynamically
    ptr2 = (int*)calloc(5, sizeof(int));

    // check if memory allocation was successful
    if (ptr2 == NULL)
    {
        printf("Memory allocation unsuccessful. Exiting...");
        exit(0);
    }

    // assign some values to the first 5 integers
    ptr2[0] = 6;
    ptr2[1] = 7;
    ptr2[2] = 8;
    ptr2[3] = 9;
    ptr2[4] = 10;

    // print the values of the 5 integers allocated using calloc
    printf("Values of the 5 integers allocated using calloc: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    // reallocate memory of ptr1 to hold 20 integers
    ptr3 = realloc(ptr1, 20 * sizeof(int));

    // check if memory allocation was successful
    if (ptr3 == NULL)
    {
        printf("Memory allocation unsuccessful. Exiting...");
        exit(0);
    }

    // assign some values to the next 5 integers
    ptr3[5] = 11;
    ptr3[6] = 12;
    ptr3[7] = 13;
    ptr3[8] = 14;
    ptr3[9] = 15;

    // print the values of the first 10 integers after reallocation
    printf("Values of the first 10 integers after reallocation: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ptr3[i]);
    }
    printf("\n");

    // free the memory allocated dynamically using malloc and realloc
    free(ptr3);
    free(ptr2);

    return 0;
}