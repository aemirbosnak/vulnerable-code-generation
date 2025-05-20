//Gemma-7B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **arr = NULL;
    int i, j, n, m, k;

    // Allocate memory for the array
    arr = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Fill the array with data
    printf("Enter the data: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%s", arr[i][j]);
        }
    }

    // Find the maximum value in the array
    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (atoi(arr[i][j]) > k)
            {
                k = atoi(arr[i][j]);
            }
        }
    }

    // Print the maximum value
    printf("The maximum value in the array is: %d", k);

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}