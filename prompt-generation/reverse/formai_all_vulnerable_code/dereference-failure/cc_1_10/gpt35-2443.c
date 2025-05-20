//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
/*
* This program generates a unique fractal pattern using C programming language.
* It is inspired by the fractal generation techniques, and implemented with the help of recursion.
* Linus Torvalds has taught us to write code that is simple, elegant, and efficient. 
* This program tries to incorporate the same philosophy.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 1024 // Dimension of the image generated
#define MAX_DEPTH 10 // Maximum depth of recursion

// Function to get the RGB color values for the image
void getColor(int depth, int *r, int *g, int *b)
{
    // simple algorithm for generating color
    *r = depth * 10;
    *g = depth * 20;
    *b = depth * 30;
}

// Function to generate fractal image
void generateFractal(int x, int y, int w, int h, int depth, unsigned char *image)
{
    if (depth >= MAX_DEPTH)
    {
        return;
    }

    int r, g, b;
    getColor(depth, &r, &g, &b);

    // Calculate color value for entire block
    for (int i = x; i < x + w; i++)
    {
        for (int j = y; j < y + h; j++)
        {
            int index = (i + j * DIM) * 3;
            image[index] = r;
            image[index + 1] = g;
            image[index + 2] = b;
        }
    }

    // Divide the block recursively into 4 sub-blocks
    int sub_w = w / 2;
    int sub_h = h / 2;

    generateFractal(x, y, sub_w, sub_h, depth + 1, image);
    generateFractal(x + sub_w, y, sub_w, sub_h, depth + 1, image);
    generateFractal(x, y + sub_h, sub_w, sub_h, depth + 1, image);
    generateFractal(x + sub_w, y + sub_h, sub_w, sub_h, depth + 1, image);
}

int main()
{
    // Allocate memory for image
    unsigned char *image = (unsigned char *)malloc(DIM * DIM * 3);

    // Set all values to 0 (black)
    for (int i = 0; i < DIM * DIM * 3; i++)
    {
        image[i] = 0;
    }

    // Generate the fractal image
    generateFractal(0, 0, DIM, DIM, 0, image);

    // Write the image to file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
    fwrite(image, 1, DIM * DIM * 3, fp);
    fclose(fp);

    // Free the image memory
    free(image);

    return 0;
}