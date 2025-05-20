//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int width, int height, char **arr)
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int width = 10;
    int height = 5;

    arr = (char **)malloc(height * sizeof(char *));
    for (int r = 0; r < height; r++)
    {
        arr[r] = (char *)malloc(width * sizeof(char));
    }

    arr[0][0] = 219;
    arr[0][1] = 248;
    arr[0][2] = 248;
    arr[0][3] = 232;
    arr[0][4] = 248;

    arr[1][0] = 248;
    arr[1][1] = 248;
    arr[1][2] = 224;
    arr[1][3] = 248;
    arr[1][4] = 248;

    arr[2][0] = 248;
    arr[2][1] = 248;
    arr[2][2] = 224;
    arr[2][3] = 248;
    arr[2][4] = 248;

    arr[3][0] = 248;
    arr[3][1] = 248;
    arr[3][2] = 248;
    arr[3][3] = 248;
    arr[3][4] = 248;

    arr[4][0] = 248;
    arr[4][1] = 248;
    arr[4][2] = 248;
    arr[4][3] = 248;
    arr[4][4] = 248;

    draw_ascii_art(width, height, arr);

    free(arr);

    return 0;
}