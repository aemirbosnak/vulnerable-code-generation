//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int rows, int cols, char ***arr)
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char ***arr;
    int rows = 5;
    int cols = 10;

    arr = (char ***)malloc(rows * sizeof(char **));
    for(int r = 0; r < rows; r++)
    {
        arr[r] = (char **)malloc(cols * sizeof(char *));
        for(int c = 0; c < cols; c++)
        {
            arr[r][c] = (char *)malloc(2 * sizeof(char));
        }
    }

    arr[0][0] = 'A';
    arr[0][1] = 'A';
    arr[0][2] = 'A';
    arr[0][3] = 'A';
    arr[0][4] = 'A';
    arr[0][5] = 'A';
    arr[0][6] = 'A';
    arr[0][7] = 'A';
    arr[0][8] = 'A';
    arr[0][9] = 'A';

    arr[1][0] = 'B';
    arr[1][1] = 'B';
    arr[1][2] = 'B';
    arr[1][3] = 'B';
    arr[1][4] = 'B';
    arr[1][5] = 'B';
    arr[1][6] = 'B';
    arr[1][7] = 'B';
    arr[1][8] = 'B';
    arr[1][9] = 'B';

    draw_ascii_art(rows, cols, arr);

    free(arr);

    return 0;
}