//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct Image
{
    int **data;
    int width;
    int height;
} Image;

Image *image_create(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    image->data = malloc(height * width * sizeof(int));
    image->width = width;
    image->height = height;

    return image;
}

void image_destroy(Image *image)
{
    free(image->data);
    free(image);
}

void image_pixel_set(Image *image, int x, int y, int r, int g, int b)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        return;
    }

    image->data[y * image->width + x] = (r << RED) | (g << GREEN) | (b << BLUE);
}

void image_save(Image *image, char *filename)
{
    FILE *file = fopen(filename, "w");

    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            fprintf(file, "%d ", image->data[y * image->width + x]);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

int main()
{
    Image *image = image_create(IMAGE_WIDTH, IMAGE_HEIGHT);

    image_pixel_set(image, 100, 100, 255, 0, 0);
    image_pixel_set(image, 101, 101, 0, 255, 0);
    image_pixel_set(image, 102, 102, 0, 0, 255);

    image_save(image, "image.txt");

    image_destroy(image);

    return 0;
}