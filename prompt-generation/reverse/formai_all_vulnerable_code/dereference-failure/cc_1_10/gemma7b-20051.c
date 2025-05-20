//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image
{
    int width;
    int height;
    unsigned char **pixels;
} Image;

Image *createImage(int w, int h)
{
    Image *img = malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    img->pixels = malloc(h * w * sizeof(unsigned char *));
    for (int y = 0; y < h; y++)
    {
        img->pixels[y] = malloc(w * sizeof(unsigned char));
        for (int x = 0; x < w; x++)
        {
            img->pixels[y][x] = 0;
        }
    }
    return img;
}

void setImagePixel(Image *img, int x, int y, unsigned char value)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
    {
        return;
    }
    img->pixels[y][x] = value;
}

void displayImage(Image *img)
{
    for (int y = 0; y < img->height; y++)
    {
        for (int x = 0; x < img->width; x++)
        {
            printf("%c ", img->pixels[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    Image *img = createImage(5, 5);
    setImagePixel(img, 2, 2, 255);
    setImagePixel(img, 3, 3, 255);
    displayImage(img);

    free(img->pixels);
    free(img);

    return 0;
}