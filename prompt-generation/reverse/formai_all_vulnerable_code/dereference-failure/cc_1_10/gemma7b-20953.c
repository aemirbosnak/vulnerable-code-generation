//Gemma-7B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void check_palindrome(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = size - 1;
        for (int k = 0; k < size; k++)
        {
            if (arr[i][k] == arr[i][j] && i != k)
            {
                printf("Palindrome found!\n");
                return;
            }
        }
    }

    printf("No palindromes found.\n");
}

int main()
{
    char **arr = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    int size = 0;

    // Get the size of the array
    printf("Enter the number of rows: ");
    scanf("%d", &size);

    // Allocate the memory for the array
    arr = (char **)realloc(arr, size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (char *)realloc(arr[i], size * sizeof(char));
    }

    // Get the data for the array
    printf("Enter the data for the array: ");
    scanf("%s", arr[0]);

    // Check if the array is a palindrome
    check_palindrome(arr, size);

    // Free the memory for the array
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}