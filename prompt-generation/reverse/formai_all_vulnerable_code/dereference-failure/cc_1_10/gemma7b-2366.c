//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image
{
    int width;
    int height;
    unsigned char **pixels;
} Image;

Image *image_load(char *filename)
{
    Image *image = malloc(sizeof(Image));

    // Read image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return NULL;
    }

    // Get image width and height
    image->width = fread(fp, 1, sizeof(int), (void *) &image->width);
    image->height = fread(fp, 1, sizeof(int), (void *) &image->height);

    // Allocate pixels
    image->pixels = malloc(image->height * image->width * sizeof(unsigned char *));
    for (int i = 0; i < image->height; i++)
    {
        image->pixels[i] = malloc(image->width * sizeof(unsigned char));
    }

    // Read image data
    fread(image->pixels, image->height * image->width * 3, 1, fp);

    fclose(fp);

    return image;
}

void image_to_ascii(Image *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int r = image->pixels[y][x] & 0xFF;
            int g = (image->pixels[y][x] & 0xFF00) >> 8;
            int b = (image->pixels[y][x] & 0xFF0000) >> 16;

            char color = '\0';

            if (r == g && g == b)
            {
                color = ' ';
            }
            else if (r > g && r > b)
            {
                color = '#';
            }
            else if (g > r && g > b)
            {
                color = '$';
            }
            else if (b > r && b > g)
            {
                color = '%';
            }
            else
            {
                color = '.';
            }

            printf("%c", color);
        }

        printf("\n");
    }
}

int main()
{
    Image *image = image_load("image.jpg");
    image_to_ascii(image);
    free(image);

    return 0;
}