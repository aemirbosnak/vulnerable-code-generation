//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_CHAR 20

int main()
{
    int lines, chars, x, y, r, seed;
    char **arr;

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Get the number of lines and characters
    lines = rand() % MAX_LINES + 1;
    chars = rand() % MAX_CHAR + 1;

    // Allocate memory for the array
    arr = (char**)malloc(lines * sizeof(char*) + 1);
    for (x = 0; x < lines; x++)
    {
        arr[x] = (char*)malloc(chars * sizeof(char) + 1);
    }

    // Fill the array with random characters
    for (x = 0; x < lines; x++)
    {
        for (y = 0; y < chars; y++)
        {
            arr[x][y] = (char)rand() % 26 + 65;
        }
    }

    // Print the array to ASCII art
    for (x = 0; x < lines; x++)
    {
        for (y = 0; y < chars; y++)
        {
            printf("%c ", arr[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < lines; x++)
    {
        free(arr[x]);
    }
    free(arr);

    return 0;
}