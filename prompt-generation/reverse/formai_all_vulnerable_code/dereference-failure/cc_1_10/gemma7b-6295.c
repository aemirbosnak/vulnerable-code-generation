//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024

typedef struct ImageData
{
    int width, height;
    unsigned char *pixels;
} ImageData;

ImageData *createImage(int w, int h)
{
    ImageData *image = (ImageData *)malloc(sizeof(ImageData));
    image->width = w;
    image->height = h;
    image->pixels = (unsigned char *)malloc(w * h * 3);
    return image;
}

void setImagePixel(ImageData *image, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x >= image->width || y >= image->height)
    {
        return;
    }
    image->pixels[3 * (x + image->width * y)] = r;
    image->pixels[3 * (x + image->width * y) + 1] = g;
    image->pixels[3 * (x + image->width * y) + 2] = b;
}

void displayImage(ImageData *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            unsigned char r = image->pixels[3 * (x + image->width * y)];
            unsigned char g = image->pixels[3 * (x + image->width * y) + 1];
            unsigned char b = image->pixels[3 * (x + image->width * y) + 2];
            printf("%c%c%c ", r, g, b);
        }
        printf("\n");
    }
}

int main()
{
    ImageData *image = createImage(10, 10);
    setImagePixel(image, 5, 5, 255, 0, 0);
    setImagePixel(image, 6, 6, 0, 255, 0);
    setImagePixel(image, 7, 7, 0, 0, 255);
    displayImage(image);

    free(image->pixels);
    free(image);

    return 0;
}