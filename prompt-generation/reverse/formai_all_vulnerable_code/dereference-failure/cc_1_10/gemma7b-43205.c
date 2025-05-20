//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void draw_ascii_art(int x, int y, char **arr)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Generate ASCII art
    arr[0][0] = 'H';
    arr[0][1] = 'U';
    arr[0][2] = 'R';
    arr[0][3] = 'C';
    arr[1][0] = 'A';
    arr[1][1] = 'R';
    arr[1][2] = 'T';
    arr[1][3] = 'R';
    arr[2][0] = 'A';
    arr[2][1] = 'R';
    arr[2][2] = 'C';
    arr[2][3] = 'H';

    draw_ascii_art(4, 3, arr);

    // Free memory
    for (int i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}