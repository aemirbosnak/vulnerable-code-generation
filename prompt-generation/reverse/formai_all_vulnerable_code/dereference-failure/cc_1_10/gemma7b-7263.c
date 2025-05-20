//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_WIDTH 256
#define MAX_IMAGE_HEIGHT 256

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
    for (int i = 0; i < image->height; i++)
    {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void image_set_pixel(Image *image, int x, int y, char value)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return;
    }
    image->pixels[y][x] = value;
}

void image_convert_to_ascii(Image *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            char pixel_value = image->pixels[y][x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("o ");
                    break;
                case 3:
                    printf("* ");
                    break;
                default:
                    printf("Error! ");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    Image *image = image_create(8, 8);
    image_set_pixel(image, 0, 0, 2);
    image_set_pixel(image, 1, 0, 1);
    image_set_pixel(image, 2, 0, 0);
    image_set_pixel(image, 3, 0, 3);
    image_convert_to_ascii(image);

    image_destroy(image);

    return 0;
}