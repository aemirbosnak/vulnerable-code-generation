//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Pixel Pixel;
struct Pixel
{
    int x, y, r, g, b;
};

Pixel **generateFractal(int size, int iterations)
{
    Pixel **pixels = (Pixel **)malloc(size * size * sizeof(Pixel));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            pixels[i][j].x = i;
            pixels[i][j].y = j;
            pixels[i][j].r = pixels[i][j].g = pixels[i][j].b = 0;
        }
    }

    for (int i = 0; i < iterations; i++)
    {
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                Pixel pixel = pixels[x][y];
                int distance = abs(pixel.x - pixel.y) + abs(pixel.x - pixel.y);
                pixels[x][y].r = pixels[x][y].g = pixels[x][y].b = distance;
            }
        }
    }

    return pixels;
}

int main()
{
    Pixel **fractal = generateFractal(MAX, 10);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", fractal[i][j].r);
        }
        printf("\n");
    }

    free(fractal);

    return 0;
}