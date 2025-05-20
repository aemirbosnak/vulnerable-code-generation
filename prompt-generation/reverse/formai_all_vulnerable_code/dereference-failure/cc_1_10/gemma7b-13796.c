//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Image
{
    int width, height;
    unsigned char *data;
} Image;

Image *createImage(int w, int h)
{
    Image *img = malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    img->data = malloc(w * h * 3);
    return img;
}

void setImagePixel(Image *img, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
    {
        return;
    }
    img->data[3 * (x * img->height + y)] = r;
    img->data[3 * (x * img->height + y) + 1] = g;
    img->data[3 * (x * img->height + y) + 2] = b;
}

void displayImage(Image *img)
{
    for (int y = 0; y < img->height; y++)
    {
        for (int x = 0; x < img->width; x++)
        {
            unsigned char r = img->data[3 * (x * img->height + y)];
            unsigned char g = img->data[3 * (x * img->height + y) + 1];
            unsigned char b = img->data[3 * (x * img->height + y) + 2];
            printf("(%d, %d, %d) ", r, g, b);
        }
        printf("\n");
    }
}

int main()
{
    Image *img = createImage(5, 5);
    setImagePixel(img, 2, 2, 255, 0, 0);
    setImagePixel(img, 3, 3, 0, 255, 0);
    setImagePixel(img, 4, 4, 0, 0, 255);

    displayImage(img);

    free(img->data);
    free(img);

    return 0;
}