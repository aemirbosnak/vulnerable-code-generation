//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void generatePixelArt(int **pixels, int w, int h)
{
    srand(time(NULL));
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            pixels[y][x] = rand() % 2;
        }
    }
}

void drawPixelArt(int **pixels, int w, int h)
{
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(pixels[y][x] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int **pixels = (int**)malloc(HEIGHT * sizeof(int *));
    for(int i = 0; i < HEIGHT; i++)
    {
        pixels[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    generatePixelArt(pixels, WIDTH, HEIGHT);
    drawPixelArt(pixels, WIDTH, HEIGHT);

    free(pixels);

    return 0;
}