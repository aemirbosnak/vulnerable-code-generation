//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip(unsigned char *image, int width, int height)
{
    int i;
    for (i = 0; i < height; i++)
    {
        int j;
        for (j = 0; j < width; j++)
        {
            unsigned char temp = image[i*width + j];
            image[i*width + j] = image[height - i - 1 + j*width];
            image[height - i - 1 + j*width] = temp;
        }
    }
}

void brightness_contrast(unsigned char *image, int width, int height, float brightness, float contrast)
{
    int i;
    for (i = 0; i < height; i++)
    {
        int j;
        for (j = 0; j < width; j++)
        {
            unsigned char temp = image[i*width + j];
            temp = (temp * (1 + contrast) + brightness * (1 - temp)) / (1 + 2 * contrast);
            image[i*width + j] = temp;
        }
    }
}

int main(int argc, char **argv)
{
    unsigned char *image;
    int width, height, channels;
    FILE *file;

    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "rb");
    if (!file)
    {
        fprintf(stderr, "Could not open file %s for reading.\n", argv[1]);
        exit(1);
    }

    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(&channels, sizeof(int), 1, file);

    if (channels!= 3)
    {
        fprintf(stderr, "Expected three channels, got %d.\n", channels);
        exit(1);
    }

    image = malloc(width * height * channels * sizeof(unsigned char));
    if (!image)
    {
        fprintf(stderr, "Could not allocate memory for image.\n");
        exit(1);
    }

    fread(image, width * height * channels, 1, file);
    fclose(file);

    flip(image, width, height);
    brightness_contrast(image, width, height, 0.5, 1.0);

    file = fopen(argv[2], "wb");
    if (!file)
    {
        fprintf(stderr, "Could not open file %s for writing.\n", argv[2]);
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite(&channels, sizeof(int), 1, file);

    fwrite(image, width * height * channels, 1, file);

    free(image);
    fclose(file);

    return 0;
}