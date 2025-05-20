//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void flip_image_vertically(unsigned char *image_data, int width, int height)
{
    for (int y = 0; y < height / 2; y++)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char temp = image_data[y * width + x];
            image_data[y * width + x] = image_data[(height - y - 1) * width + x];
            image_data[(height - y - 1) * width + x] = temp;
        }
    }
}

void flip_image_horizontally(unsigned char *image_data, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            unsigned char temp = image_data[y * width + x];
            image_data[y * width + x] = image_data[y * width + (width - x - 1)];
            image_data[y * width + (width - x - 1)] = temp;
        }
    }
}

void change_brightness(unsigned char *image_data, int width, int height, float brightness_factor)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image_data[y * width + x] = (unsigned char)fmin(image_data[y * width + x] * brightness_factor, 255);
        }
    }
}

void change_contrast(unsigned char *image_data, int width, int height, float contrast_factor)
{
    float midpoint = 128.0f;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            float value = image_data[y * width + x] - midpoint;
            value *= contrast_factor;
            value += midpoint;
            image_data[y * width + x] = (unsigned char)fmin(fmax(value, 0), 255);
        }
    }
}

int main()
{
    // Load the image data from a file
    FILE *file = fopen("image.raw", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    unsigned char image_data[MAX_WIDTH * MAX_HEIGHT];
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(image_data, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Flip the image vertically
    flip_image_vertically(image_data, width, height);

    // Change the brightness of the image
    change_brightness(image_data, width, height, 1.5f);

    // Change the contrast of the image
    change_contrast(image_data, width, height, 1.2f);

    // Save the modified image data to a file
    file = fopen("modified_image.raw", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite(image_data, sizeof(unsigned char), width * height, file);
    fclose(file);

    return EXIT_SUCCESS;
}