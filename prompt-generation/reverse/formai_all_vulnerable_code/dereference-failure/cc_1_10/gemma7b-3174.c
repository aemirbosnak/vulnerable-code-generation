//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct Image
{
    int width;
    int height;
    int *pixels;
} Image;

Image *createImage(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(int));
    return image;
}

void setImagePixel(Image *image, int x, int y, int value)
{
    if (x >= image->width || y >= image->height)
    {
        return;
    }
    image->pixels[x * image->height + y] = value;
}

int getImagePixel(Image *image, int x, int y)
{
    if (x >= image->width || y >= image->height)
    {
        return -1;
    }
    return image->pixels[x * image->height + y];
}

int main()
{
    Image *image = createImage(MAX_WIDTH, MAX_HEIGHT);
    setImagePixel(image, 10, 10, 255);
    setImagePixel(image, 20, 20, 0);

    int pixelValue = getImagePixel(image, 10, 10);
    if (pixelValue == 255)
    {
        printf("Pixel at (10, 10) is white.\n");
    }

    free(image->pixels);
    free(image);

    return 0;
}