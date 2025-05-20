//Gemma-7B DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 5, num2 = 0, result = 0;

    printf("Welcome to the wild world of C error handling!\n");

    // Attempt to divide num1 by num2
    result = num1 / num2;

    // Check if the division was successful
    if (result == 0)
    {
        printf("The division was successful! The result is: %d\n", result);
    }
    else
    {
        printf("Oh no! The division failed! You have to provide a non-zero number.\n");
    }

    // Try to allocate memory for a pointer
    void *ptr = malloc(10);

    // Check if the memory allocation was successful
    if (ptr == NULL)
    {
        printf("Memory allocation failed! Out of memory.\n");
    }
    else
    {
        printf("Memory allocation successful! The pointer is: %p\n", ptr);
    }

    // Attempt to read a file
    FILE *file = fopen("my_file.txt", "r");

    // Check if the file opening was successful
    if (file == NULL)
    {
        printf("File opening failed! The file does not exist.\n");
    }
    else
    {
        printf("File opening successful! The file is: %p\n", file);
    }

    return 0;
}