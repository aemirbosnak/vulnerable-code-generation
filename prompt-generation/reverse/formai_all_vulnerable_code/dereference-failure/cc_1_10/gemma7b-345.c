//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

int main()
{
    // Allocates memory for a 2D array
    char ***arr = (char ***)malloc(MAX_ROWS * sizeof(char **));
    for (int r = 0; r < MAX_ROWS; r++)
    {
        arr[r] = (char **)malloc(MAX_COLS * sizeof(char *));
        for (int c = 0; c < MAX_COLS; c++)
        {
            arr[r][c] = NULL;
        }
    }

    // Reads the CSV file
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Gets the header row
    char *header = fgets(arr[0], MAX_COLS, fp);

    // Gets the data rows
    int row = 1;
    while ((arr[row] = fgets(arr[row], MAX_COLS, fp)) != NULL)
    {
        row++;
    }

    // Free the memory
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int c = 0; c < MAX_COLS; c++)
        {
            free(arr[r][c]);
        }
        free(arr[r]);
    }
    free(arr);

    return EXIT_SUCCESS;
}