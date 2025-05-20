//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void allocate_memory(int size, int *ptr)
{
    ptr = (int*) malloc(size * sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void initialize_values(int size, int *ptr)
{
    for(int i = 0; i < size; i++)
    {
        *(ptr + i) = i + 1;
    }
}

void print_values(int size, int *ptr)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

void deallocate_memory(int *ptr)
{
    free(ptr);
    ptr = NULL;
}

int main()
{
    int size = 5;
    int *array = NULL;

    // Allocating memory dynamically
    allocate_memory(size, array);

    // Initializing values
    initialize_values(size, array);

    // Printing values
    printf("Initial values: ");
    print_values(size, array);

    // Deallocating memory
    deallocate_memory(array);

    return 0;
}