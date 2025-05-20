//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int w, h, x, y;

    printf("Enter the width of the pixel art: ");
    scanf("%d", &w);

    printf("Enter the height of the pixel art: ");
    scanf("%d", &h);

    int **pixels = (int **)malloc(h * sizeof(int *));
    for(int i = 0; i < h; i++)
    {
        pixels[i] = (int *)malloc(w * sizeof(int));
    }

    srand(time(NULL));

    for(y = 0; y < h; y++)
    {
        for(x = 0; x < w; x++)
        {
            pixels[y][x] = rand() % 2;
        }
    }

    for(y = 0; y < h; y++)
    {
        for(x = 0; x < w; x++)
        {
            if(pixels[y][x] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

    free(pixels);

    return 0;
}