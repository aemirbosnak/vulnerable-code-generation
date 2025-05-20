//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w, h;
    printf("Enter the width and height of the pixel art (separated by a space): ");
    scanf("%d %d", &w, &h);

    int **pixels = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        pixels[i] = (int*)malloc(w * sizeof(int));
    }

    printf("Enter the pixel values (separated by commas): ");
    char input[1024];
    scanf("%s", input);

    // Convert the input string into an array of integers
    int numPixels = 0;
    int pixelValues[1024];
    char* p = input;
    while (*p)
    {
        pixelValues[numPixels++] = atoi(p);
        p++;
    }

    // Create the pixel art
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            pixels[y][x] = pixelValues[numPixels - 1];
        }
    }

    // Print the pixel art
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%d ", pixels[y][x]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < h; i++)
    {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}