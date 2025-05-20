//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ImageData
{
    unsigned char *pixels;
    int width, height;
} ImageData;

ImageData *createImageData(int w, int h)
{
    ImageData *image = malloc(sizeof(ImageData));
    image->pixels = malloc(w * h * sizeof(unsigned char));
    image->width = w;
    image->height = h;
    return image;
}

void setImagePixel(ImageData *image, int x, int y, unsigned char value)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return;
    }
    image->pixels[x * image->height + y] = value;
}

unsigned char getImagePixel(ImageData *image, int x, int y)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return 0;
    }
    return image->pixels[x * image->height + y];
}

int main()
{
    ImageData *image = createImageData(10, 10);

    setImagePixel(image, 5, 5, 255);
    setImagePixel(image, 2, 2, 0);

    unsigned char pixelValue = getImagePixel(image, 2, 2);

    printf("Pixel value at (2, 2): %d", pixelValue);

    free(image->pixels);
    free(image);

    return 0;
}