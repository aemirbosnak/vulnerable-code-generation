//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct Image {
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *image_create(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * 3);

    return image;
}

void image_destroy(Image *image)
{
    free(image->pixels);
    free(image);
}

void image_draw(Image *image, int x, int y, int r, int g, int b)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }

    image->pixels[3 * (image->width * y + x)] = r;
    image->pixels[3 * (image->width * y + x) + 1] = g;
    image->pixels[3 * (image->width * y + x) + 2] = b;
}

int main()
{
    Image *image = image_create(MAX_WIDTH, MAX_HEIGHT);

    image_draw(image, 100, 100, 255, 0, 0);
    image_draw(image, 100, 100, 0, 255, 0);
    image_draw(image, 100, 100, 0, 0, 255);

    image_destroy(image);

    return 0;
}