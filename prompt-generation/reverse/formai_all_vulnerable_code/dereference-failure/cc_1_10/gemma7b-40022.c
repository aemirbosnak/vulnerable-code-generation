//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void draw_ascii_art(int height, int width, char ***arr)
{
    int i, j, k;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            for (k = 0; k < width; k++)
            {
                printf("%c ", arr[i][j][k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    char ***arr;
    int h, w;

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &w);

    arr = (char ***)malloc(h * sizeof(char **));
    for (int i = 0; i < h; i++)
    {
        arr[i] = (char **)malloc(w * sizeof(char *));
        for (int j = 0; j < w; j++)
        {
            arr[i][j] = (char *)malloc(w * sizeof(char));
        }
    }

    printf("Enter the ASCII art: ");
    char ch;
    int r, c, l;
    while ((ch = getchar()) != '\n')
    {
        r = c = l = 0;
        scanf("%d %d %d", &r, &c, &l);
        arr[r][c][l] = ch;
    }

    draw_ascii_art(h, w, arr);

    free(arr);

    return 0;
}