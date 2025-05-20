//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image
{
    int width;
    int height;
    char **pixels;
} Image;

Image *image_create(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        image->pixels[i] = malloc(width * sizeof(char) + 1);
    }
    return image;
}

void image_destroy(Image *image)
{
    free(image->pixels);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, char color)
{
    image->pixels[y][x] = color;
}

void image_to_ascii(Image *image, int threshold)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int intensity = image->pixels[y][x];
            char ascii_char = intensity > threshold ? '|' : ' ';
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main()
{
    Image *image = image_create(8, 8);
    image_set_pixel(image, 0, 0, 255);
    image_set_pixel(image, 1, 1, 0);
    image_set_pixel(image, 2, 2, 255);
    image_to_ascii(image, 128);

    image_destroy(image);

    return 0;
}