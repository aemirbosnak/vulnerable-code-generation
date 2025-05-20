//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct ImageData
{
    int width;
    int height;
    unsigned char *pixels;
} ImageData;

ImageData *load_image(char *filename)
{
    FILE *fp;
    ImageData *image = NULL;

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return NULL;
    }

    image = malloc(sizeof(ImageData));
    image->width = 10;
    image->height = 10;
    image->pixels = malloc(MAX_IMAGE_SIZE);

    fread(image->pixels, MAX_IMAGE_SIZE, 1, fp);
    fclose(fp);

    return image;
}

int main()
{
    ImageData *image = load_image("image.jpg");

    image->width = image->width * 2;
    image->height = image->height * 2;
    image->pixels = realloc(image->pixels, image->width * image->height * MAX_IMAGE_SIZE);

    printf("Image loaded successfully!\n");

    free(image->pixels);
    free(image);

    return 0;
}