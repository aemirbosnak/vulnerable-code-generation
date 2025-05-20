//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: genius
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

Image *createImage(int w, int h)
{
    Image *image = malloc(sizeof(Image));
    image->width = w;
    image->height = h;
    image->pixels = malloc(w * h * sizeof(unsigned char));
    return image;
}

void setImagePixel(Image *image, int x, int y, unsigned char value)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return;
    }
    image->pixels[x * image->height + y] = value;
}

void displayImage(Image *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            printf("%c ", image->pixels[x * image->height + y]);
        }
        printf("\n");
    }
}

int main()
{
    Image *image = createImage(5, 5);

    setImagePixel(image, 2, 2, 255);
    setImagePixel(image, 3, 3, 0);

    displayImage(image);

    free(image->pixels);
    free(image);

    return 0;
}