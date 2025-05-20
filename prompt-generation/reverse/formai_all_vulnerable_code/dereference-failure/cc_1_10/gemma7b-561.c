//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image
{
    unsigned char *data;
    int width;
    int height;
} Image;

Image *createImage(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * sizeof(unsigned char));
    image->width = width;
    image->height = height;
    return image;
}

void setImagePixel(Image *image, int x, int y, unsigned char value)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return;
    }
    image->data[x * image->height * sizeof(unsigned char) + y] = value;
}

unsigned char getImagePixel(Image *image, int x, int y)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return 0;
    }
    return image->data[x * image->height * sizeof(unsigned char) + y];
}

int main()
{
    Image *image = createImage(10, 10);
    setImagePixel(image, 5, 5, 255);
    unsigned char pixelValue = getImagePixel(image, 5, 5);
    if (pixelValue == 255)
    {
        printf("Pixel value is 255");
    }
    free(image->data);
    free(image);

    return 0;
}