//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, w, h;
    printf("Enter the width and height of the pixel art (separated by a space): ");
    scanf("%d %d", &w, &h);

    // Allocate memory for the pixel art
    int **pixel_art = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        pixel_art[i] = (int*)malloc(w * sizeof(int));
    }

    // Get the pixel art data
    printf("Enter the pixel art data (separated by commas): ");
    char input[256];
    scanf("%s", input);

    // Convert the input data into integers
    int i = 0;
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            pixel_art[y][x] = input[i] - '0';
            i++;
        }
    }

    // Print the pixel art
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (pixel_art[y][x] == 1)
            {
                printf("# ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Free the memory allocated for the pixel art
    for (int i = 0; i < h; i++)
    {
        free(pixel_art[i]);
    }
    free(pixel_art);

    return 0;
}