//Gemma-7B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int i, j, k, l, n, m;
    char **arr;

    // Allocate memory for the array
    arr = (char **)malloc(MAX * sizeof(char *));
    for(i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the number of rows and columns
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    // Read the data
    printf("Enter the data: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%c ", &arr[i][j]);
        }
    }

    // Find the maximum value
    k = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(arr[i][j] > k)
            {
                k = arr[i][j];
            }
        }
    }

    // Print the maximum value
    printf("The maximum value is: %d", k);

    // Free the memory
    for(i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}