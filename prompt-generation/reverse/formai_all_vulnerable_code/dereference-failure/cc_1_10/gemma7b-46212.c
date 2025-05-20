//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void pixel_art_generator()
{
    int width, height, x, y;

    // Get the dimensions of the pixel art
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);

    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    // Allocate memory for the pixel art
    int **pixel_art = (int**)malloc(height * sizeof(int*));
    for (y = 0; y < height; y++)
    {
        pixel_art[y] = (int*)malloc(width * sizeof(int));
    }

    // Create the pixel art
    printf("Enter the pixel art data (each pixel is a number between 0 and 255):\n");
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            scanf("%d", &pixel_art[y][x]);
        }
    }

    // Display the pixel art
    printf("Your pixel art:\n");
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            printf("%d ", pixel_art[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (y = 0; y < height; y++)
    {
        free(pixel_art[y]);
    }
    free(pixel_art);
}

int main()
{
    pixel_art_generator();

    return 0;
}