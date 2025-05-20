//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image
{
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *load_image(char *filename)
{
    Image *image = malloc(sizeof(Image));

    image->width = 128;
    image->height = 128;
    image->pixels = malloc(MAX_IMAGE_SIZE);

    FILE *file = fopen(filename, "rb");
    if (file)
    {
        fread(image->pixels, MAX_IMAGE_SIZE, 1, file);
        fclose(file);
    }

    return image;
}

void convert_image_to_ascii(Image *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int pixel_value = image->pixels[y * image->width + x];
            int ascii_value = pixel_value / 2;
            printf("%c ", ascii_value);
        }

        printf("\n");
    }
}

int main()
{
    Image *image = load_image("image.jpg");
    convert_image_to_ascii(image);
    free(image->pixels);
    free(image);

    return 0;
}