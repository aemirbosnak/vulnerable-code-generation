//Gemma-7B DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, w, h, r, g, b;
    printf("Enter the width and height of the pixel art: ");
    scanf("%d %d", &w, &h);

    printf("Enter the number of rows and columns for each pixel: ");
    scanf("%d", &r);

    printf("Enter the red, green, and blue values for each pixel: ");
    scanf("%d %d %d", &g, &b);

    int **pixels = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        pixels[i] = (int*)malloc(w * sizeof(int));
    }

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            pixels[y][x] = r * 256 + g * 256 + b * 256;
        }
    }

    FILE *fp = fopen("pixel_art.ppm", "w");
    fprintf(fp, "PPPM\n");
    fprintf(fp, "Width: %d\n", w);
    fprintf(fp, "Height: %d\n", h);
    fprintf(fp, "Number of Rows and Columns for Each Pixel: %d\n", r);
    fprintf(fp, "Red, Green, Blue Values for Each Pixel: %d, %d, %d\n", g, b);
    fprintf(fp, "Pixel Data: ");

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            fprintf(fp, "%d ", pixels[y][x]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}