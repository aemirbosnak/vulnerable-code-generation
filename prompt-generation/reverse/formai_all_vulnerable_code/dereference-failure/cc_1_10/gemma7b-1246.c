//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct Image
{
    int width;
    int height;
    unsigned char *pixels;
} Image;

Image *load_image(char *filename)
{
    Image *image = malloc(sizeof(Image));

    image->width = MAX_WIDTH;
    image->height = MAX_HEIGHT;
    image->pixels = malloc(image->width * image->height * 3);

    FILE *file = fopen(filename, "rb");
    if (file)
    {
        unsigned char header[512];
        fread(header, 1, 512, file);

        image->width = header[1] * 2;
        image->height = header[2] * 2;
        image->pixels = realloc(image->pixels, image->width * image->height * 3);

        fread(image->pixels, 1, image->width * image->height * 3, file);
        fclose(file);
    }

    return image;
}

void save_image(Image *image, char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file)
    {
        unsigned char header[512];
        header[0] = 0x80;
        header[1] = (image->width) / 2;
        header[2] = (image->height) / 2;
        header[3] = (image->width) % 2;
        header[4] = (image->height) % 2;

        fwrite(header, 1, 512, file);
        fwrite(image->pixels, 1, image->width * image->height * 3, file);
        fclose(file);
    }
}

int main()
{
    Image *image = load_image("image.jpg");
    save_image(image, "image_edited.jpg");

    return 0;
}