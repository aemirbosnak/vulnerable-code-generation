//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int **arr = NULL;
    int i, j, n, m;

    // Allocate memory for the matrix
    arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Initialize the matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Print the matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < MAX_SIZE; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}