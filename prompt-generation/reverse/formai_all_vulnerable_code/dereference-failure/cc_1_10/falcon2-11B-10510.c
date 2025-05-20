//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int width, height, r, g, b;
    char *filename;

    /* Open input image file */
    filename = "input.jpg";
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    /* Read image dimensions */
    fread(&width, sizeof(int), 1, f);
    fread(&height, sizeof(int), 1, f);

    /* Read pixels */
    int *pixels = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fread(&pixels[i * width + j], sizeof(int), 1, f);
        }
    }

    /* Read image RGB values */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fread(&r, sizeof(int), 1, f);
            fread(&g, sizeof(int), 1, f);
            fread(&b, sizeof(int), 1, f);
            printf("%d %d %d\n", r, g, b);
        }
    }

    /* Close input file */
    fclose(f);

    /* Free allocated memory */
    free(pixels);

    return 0;
}