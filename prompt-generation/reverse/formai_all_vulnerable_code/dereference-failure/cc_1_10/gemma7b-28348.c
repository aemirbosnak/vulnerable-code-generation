//Gemma-7B DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    // Allocate memory for a 2D array
    int **arr = (int **)malloc(MAX * sizeof(int *)), i, j, k;

    // Initialize the 2D array
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Read data from a file
    FILE *fp = fopen("data.txt", "r");
    char line[MAX];
    while (fgets(line, MAX, fp) != NULL)
    {
        // Split the line into tokens
        char *token = strtok(line, ",");
        while (token)
        {
            // Convert the token to an integer
            int num = atoi(token);

            // Increment the element in the 2D array
            arr[num][num] = 1;
            token = strtok(NULL, ",");
        }
    }

    // Print the 2D array
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the 2D array
    for (i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}