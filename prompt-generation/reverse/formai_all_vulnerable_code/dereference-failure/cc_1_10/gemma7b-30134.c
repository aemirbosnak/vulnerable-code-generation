//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int height, int width, char **arr)
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr = NULL;
    int h = 5, w = 5;

    arr = (char **)malloc(h * sizeof(char *) + w * sizeof(char));
    for (int i = 0; i < h; i++)
    {
        arr[i] = (char *)malloc(w * sizeof(char));
    }

    arr[0][0] = 219;
    arr[0][1] = 173;
    arr[0][2] = 182;
    arr[0][3] = 242;
    arr[0][4] = 216;

    arr[1][0] = 128;
    arr[1][1] = 173;
    arr[1][2] = 182;
    arr[1][3] = 128;
    arr[1][4] = 184;

    arr[2][0] = 128;
    arr[2][1] = 173;
    arr[2][2] = 182;
    arr[2][3] = 128;
    arr[2][4] = 184;

    arr[3][0] = 128;
    arr[3][1] = 173;
    arr[3][2] = 182;
    arr[3][3] = 128;
    arr[3][4] = 184;

    arr[4][0] = 128;
    arr[4][1] = 173;
    arr[4][2] = 182;
    arr[4][3] = 128;
    arr[4][4] = 184;

    draw_ascii_art(h, w, arr);

    free(arr);

    return 0;
}