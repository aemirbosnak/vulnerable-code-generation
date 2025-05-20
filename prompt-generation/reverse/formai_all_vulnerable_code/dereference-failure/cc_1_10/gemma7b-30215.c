//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct ImageData
{
    unsigned char *data;
    int width;
    int height;
} ImageData;

ImageData *createImage(int width, int height)
{
    ImageData *image = malloc(sizeof(ImageData));
    image->data = malloc(width * height * sizeof(unsigned char));
    image->width = width;
    image->height = height;
    return image;
}

void setImagePixel(ImageData *image, int x, int y, unsigned char value)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return;
    }
    image->data[x * image->height * 3 + y * 3] = value;
}

void displayImage(ImageData *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            unsigned char r = image->data[x * image->height * 3 + y * 3];
            unsigned char g = image->data[x * image->height * 3 + y * 3 + 1];
            unsigned char b = image->data[x * image->height * 3 + y * 3 + 2];
            printf("(%d, %d, %d) ", r, g, b);
        }
        printf("\n");
    }
}

int main()
{
    ImageData *image = createImage(8, 8);
    setImagePixel(image, 0, 0, 255);
    setImagePixel(image, 2, 2, 0);
    setImagePixel(image, 4, 4, 255);
    displayImage(image);

    free(image->data);
    free(image);

    return 0;
}