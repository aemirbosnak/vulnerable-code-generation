//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Pixel {
    int r, g, b, a;
} Pixel;

typedef struct Image {
    int width, height;
    Pixel **pixels;
} Image;

Image *createImage(int w, int h)
{
    Image *image = malloc(sizeof(Image));
    image->width = w;
    image->height = h;
    image->pixels = (Pixel **)malloc(h * sizeof(Pixel *));
    for (int i = 0; i < h; i++)
    {
        image->pixels[i] = (Pixel *)malloc(w * sizeof(Pixel));
        for (int j = 0; j < w; j++)
        {
            image->pixels[i][j].r = 0;
            image->pixels[i][j].g = 0;
            image->pixels[i][j].b = 0;
            image->pixels[i][j].a = 255;
        }
    }
    return image;
}

void setImagePixel(Image *image, int x, int y, int r, int g, int b, int a)
{
    if (x >= image->width || y >= image->height)
    {
        return;
    }
    image->pixels[y][x].r = r;
    image->pixels[y][x].g = g;
    image->pixels[y][x].b = b;
    image->pixels[y][x].a = a;
}

void saveImage(Image *image, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "PNG\n");
    fprintf(fp, "IHDR (%d, %d, %d)\n", image->width, image->height, 8);
    fprintf(fp, "IDAT\n");
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            fprintf(fp, "%d, %d, %d, %d\n", image->pixels[y][x].r, image->pixels[y][x].g, image->pixels[y][x].b, image->pixels[y][x].a);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "IEND\n");
    fclose(fp);
}

int main()
{
    Image *image = createImage(10, 10);
    setImagePixel(image, 5, 5, 255, 0, 0, 255);
    setImagePixel(image, 5, 6, 0, 255, 0, 255);
    setImagePixel(image, 6, 5, 0, 0, 255, 255);
    saveImage(image, "image.png");
    return 0;
}