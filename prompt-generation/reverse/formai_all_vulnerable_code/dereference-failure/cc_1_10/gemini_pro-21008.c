//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

Image *image_new(uint32_t width, uint32_t height)
{
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
    return image;
}

void image_free(Image *image)
{
    free(image->data);
    free(image);
}

int image_load(Image *image, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
        return -1;

    fread(&image->width, sizeof(uint32_t), 1, file);
    fread(&image->height, sizeof(uint32_t), 1, file);
    fread(image->data, 1, image->width * image->height * 3, file);
    fclose(file);

    return 0;
}

int image_save(Image *image, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
        return -1;

    fwrite(&image->width, sizeof(uint32_t), 1, file);
    fwrite(&image->height, sizeof(uint32_t), 1, file);
    fwrite(image->data, 1, image->width * image->height * 3, file);
    fclose(file);

    return 0;
}

void image_flip_horizontal(Image *image)
{
    for (uint32_t y = 0; y < image->height; y++)
    {
        for (uint32_t x = 0; x < image->width / 2; x++)
        {
            uint8_t *a = image->data + (y * image->width + x) * 3;
            uint8_t *b = image->data + (y * image->width + image->width - x - 1) * 3;

            uint8_t t = a[0];
            a[0] = b[0];
            b[0] = t;

            t = a[1];
            a[1] = b[1];
            b[1] = t;

            t = a[2];
            a[2] = b[2];
            b[2] = t;
        }
    }
}

void image_flip_vertical(Image *image)
{
    for (uint32_t y = 0; y < image->height / 2; y++)
    {
        for (uint32_t x = 0; x < image->width; x++)
        {
            uint8_t *a = image->data + (y * image->width + x) * 3;
            uint8_t *b = image->data + ((image->height - y - 1) * image->width + x) * 3;

            uint8_t t = a[0];
            a[0] = b[0];
            b[0] = t;

            t = a[1];
            a[1] = b[1];
            b[1] = t;

            t = a[2];
            a[2] = b[2];
            b[2] = t;
        }
    }
}

void image_adjust_brightness(Image *image, float brightness)
{
    for (uint32_t i = 0; i < image->width * image->height * 3; i++)
    {
        image->data[i] = image->data[i] * brightness;
    }
}

void image_adjust_contrast(Image *image, float contrast)
{
    for (uint32_t i = 0; i < image->width * image->height * 3; i++)
    {
        image->data[i] = 127 + (image->data[i] - 127) * contrast;
    }
}

int main()
{
    const char *filename = "image.bmp";
    Image *image = image_new(640, 480);

    if (image_load(image, filename) != 0)
    {
        printf("Error loading image %s\n", filename);
        return -1;
    }

    image_flip_horizontal(image);
    image_flip_vertical(image);
    image_adjust_brightness(image, 1.2);
    image_adjust_contrast(image, 1.5);

    if (image_save(image, filename) != 0)
    {
        printf("Error saving image %s\n", filename);
        return -1;
    }

    image_free(image);

    return 0;
}