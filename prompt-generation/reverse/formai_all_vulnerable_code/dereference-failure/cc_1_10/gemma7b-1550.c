//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_ascii_art(char **arr, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int rows = 5;
    int cols = 10;

    arr = (char **)malloc(rows * sizeof(char *));
    for (int r = 0; r < rows; r++)
    {
        arr[r] = (char *)malloc(cols * sizeof(char));
    }

    // Fill the array with ASCII art
    arr[0][0] = 219;
    arr[0][1] = 173;
    arr[0][2] = 173;
    arr[0][3] = 173;
    arr[0][4] = 173;
    arr[0][5] = 248;
    arr[0][6] = 248;
    arr[0][7] = 248;
    arr[0][8] = 248;
    arr[0][9] = 219;

    arr[1][0] = 211;
    arr[1][1] = 211;
    arr[1][2] = 211;
    arr[1][3] = 211;
    arr[1][4] = 211;
    arr[1][5] = 248;
    arr[1][6] = 248;
    arr[1][7] = 248;
    arr[1][8] = 248;
    arr[1][9] = 211;

    generate_ascii_art(arr, rows, cols);

    // Free the allocated memory
    for (int r = 0; r < rows; r++)
    {
        free(arr[r]);
    }
    free(arr);

    return 0;
}