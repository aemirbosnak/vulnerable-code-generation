//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 20

void generate_ascii_art(int row, int col, char **arr)
{
    arr[row][col] = rand() % 26 + 65;
    if (row == MAX_ROWS - 1)
    {
        arr[row][col] = '\n';
    }
    else
    {
        arr[row][col] = ' ';
    }
}

int main()
{
    char **arr = NULL;
    int row, col;

    arr = (char**)malloc(MAX_ROWS * sizeof(char *));
    for (row = 0; row < MAX_ROWS; row++)
    {
        arr[row] = (char *)malloc(MAX_COLS * sizeof(char));
    }

    srand(time(NULL));

    for (row = 0; row < MAX_ROWS; row++)
    {
        for (col = 0; col < MAX_COLS; col++)
        {
            generate_ascii_art(row, col, arr);
        }
    }

    printf("%s", arr);

    for (row = 0; row < MAX_ROWS; row++)
    {
        free(arr[row]);
    }
    free(arr);

    return 0;
}