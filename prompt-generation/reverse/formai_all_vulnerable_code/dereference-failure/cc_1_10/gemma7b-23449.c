//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
// The Great Detective's Pixel Art Generator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    printf("Enter the width of your pixel art (in pixels): ");
    scanf("%d", &width);

    printf("Enter the height of your pixel art (in pixels): ");
    scanf("%d", &height);

    int **pixels = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++)
    {
        pixels[i] = (int*)malloc(width * sizeof(int));
    }

    // Gather pixel data from the detective
    printf("Enter the pixel data, one pixel at a time (separate pixels with spaces): ");
    char input;
    int x, y;
    while ((input = getchar()) != '\n')
    {
        scanf("%d %d", &x, &y);
        pixels[y][x] = 1;
    }

    // Create the pixel art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (pixels[i][j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < height; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}