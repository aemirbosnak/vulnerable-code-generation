//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct
{
    unsigned char r, g, b;
} Pixel;

typedef struct
{
    int width, height;
    Pixel *pixels;
} Image;

Image *new_image(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    return image;
}

void free_image(Image *image)
{
    free(image->pixels);
    free(image);
}

void load_image(Image *image, char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    fread(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void save_image(Image *image, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void invert_image(Image *image)
{
    for (int i = 0; i < image->width * image->height; i++)
    {
        image->pixels[i].r = 255 - image->pixels[i].r;
        image->pixels[i].g = 255 - image->pixels[i].g;
        image->pixels[i].b = 255 - image->pixels[i].b;
    }
}

void grayscale_image(Image *image)
{
    for (int i = 0; i < image->width * image->height; i++)
    {
        unsigned char gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].r = gray;
        image->pixels[i].g = gray;
        image->pixels[i].b = gray;
    }
}

void blur_image(Image *image)
{
    int kernel[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}};

    int divisor = 16;

    Image *temp_image = new_image(image->width, image->height);

    for (int i = 1; i < image->width - 1; i++)
    {
        for (int j = 1; j < image->height - 1; j++)
        {
            int r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    r += image->pixels[(i + k) * image->width + (j + l)].r * kernel[k + 1][l + 1];
                    g += image->pixels[(i + k) * image->width + (j + l)].g * kernel[k + 1][l + 1];
                    b += image->pixels[(i + k) * image->width + (j + l)].b * kernel[k + 1][l + 1];
                }
            }
            temp_image->pixels[i * image->width + j].r = r / divisor;
            temp_image->pixels[i * image->width + j].g = g / divisor;
            temp_image->pixels[i * image->width + j].b = b / divisor;
        }
    }

    memcpy(image->pixels, temp_image->pixels, image->width * image->height * sizeof(Pixel));

    free_image(temp_image);
}

void sharpen_image(Image *image)
{
    int kernel[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}};

    int divisor = 1;

    Image *temp_image = new_image(image->width, image->height);

    for (int i = 1; i < image->width - 1; i++)
    {
        for (int j = 1; j < image->height - 1; j++)
        {
            int r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    r += image->pixels[(i + k) * image->width + (j + l)].r * kernel[k + 1][l + 1];
                    g += image->pixels[(i + k) * image->width + (j + l)].g * kernel[k + 1][l + 1];
                    b += image->pixels[(i + k) * image->width + (j + l)].b * kernel[k + 1][l + 1];
                }
            }
            temp_image->pixels[i * image->width + j].r = r / divisor;
            temp_image->pixels[i * image->width + j].g = g / divisor;
            temp_image->pixels[i * image->width + j].b = b / divisor;
        }
    }

    memcpy(image->pixels, temp_image->pixels, image->width * image->height * sizeof(Pixel));

    free_image(temp_image);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }

    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);
    load_image(image, argv[1]);

    invert_image(image);
    grayscale_image(image);
    blur_image(image);
    sharpen_image(image);

    save_image(image, argv[2]);

    free_image(image);

    return 0;
}