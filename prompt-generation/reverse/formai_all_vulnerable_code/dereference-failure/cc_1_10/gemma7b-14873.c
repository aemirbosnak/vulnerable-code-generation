//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Invalid input. Please enter a positive number: ");
        scanf("%d", &n);
    }

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Generate random numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}