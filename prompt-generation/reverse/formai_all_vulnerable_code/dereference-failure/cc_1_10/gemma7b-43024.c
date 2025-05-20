//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Image
{
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *createImage(int w, int h)
{
    Image *img = malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    img->pixels = malloc(w * h * 3);
    return img;
}

void setImagePixel(Image *img, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
    {
        return;
    }
    img->pixels[3 * (x * img->height + y)] = r;
    img->pixels[3 * (x * img->height + y) + 1] = g;
    img->pixels[3 * (x * img->height + y) + 2] = b;
}

void saveImage(Image *img, FILE *fp)
{
    fprintf(fp, "PBM %d %d\n", img->width, img->height);
    fprintf(fp, "%d ", img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++)
    {
        fprintf(fp, "%c %c %c ", img->pixels[3 * i], img->pixels[3 * i + 1], img->pixels[3 * i + 2]);
    }
    fprintf(fp, "\n");
}

int main()
{
    Image *img = createImage(10, 10);
    setImagePixel(img, 5, 5, 255, 0, 0);
    setImagePixel(img, 2, 2, 0, 255, 0);
    setImagePixel(img, 3, 3, 0, 0, 255);

    FILE *fp = fopen("image.pbm", "w");
    saveImage(img, fp);
    fclose(fp);

    return 0;
}