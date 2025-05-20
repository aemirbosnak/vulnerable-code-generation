//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void generate_ascii_art(int size)
{
    int i, j;
    char **arr = (char **)malloc(size * sizeof(char *));
    for (i = 0; i < size; i++)
    {
        arr[i] = (char *)malloc(size * sizeof(char));
        for (j = 0; j < size; j++)
        {
            arr[i][j] = ' ';
        }
    }

    // Draw a rectangle
    arr[0][0] = arr[0][size - 1] = arr[size - 1][0] = arr[size - 1][size - 1] = '*';

    // Draw the diagonal lines
    for (i = 1; i < size - 1; i++)
    {
        for (j = 1; j < size - 1; j++)
        {
            if (i == j)
            {
                arr[i][j] = '*';
            }
        }
    }

    // Print the ASCII art
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

int main()
{
    generate_ascii_art(MAX_SIZE);

    return 0;
}