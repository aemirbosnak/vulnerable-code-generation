//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct ImageData
{
    unsigned char *data;
    int width;
    int height;
} ImageData;

ImageData *load_image(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return NULL;
    }

    ImageData *image = malloc(sizeof(ImageData));
    image->data = malloc(MAX_IMAGE_SIZE);

    image->width = 1;
    image->height = 1;

    unsigned char pixel_data[3];
    int bytes_read = fread(pixel_data, 3, MAX_IMAGE_SIZE, fp);

    image->width = pixel_data[0] + 1;
    image->height = pixel_data[1] + 1;

    image->data = realloc(image->data, image->width * image->height * 3);
    fwrite(pixel_data, 3, bytes_read, image->data);

    fclose(fp);

    return image;
}

void convert_image_to_ascii(ImageData *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int r = image->data[y * image->width * 3 + x * 3] & 0xFF;
            int g = image->data[y * image->width * 3 + x * 3 + 1] & 0xFF;
            int b = image->data[y * image->width * 3 + x * 3 + 2] & 0xFF;

            char pixel = '\0';

            if (r >= 128) pixel = 'H';
            else if (r >= 64) pixel = 'M';
            else if (r >= 32) pixel = 'A';
            else pixel = ' ';

            printf("%c", pixel);
        }

        printf("\n");
    }
}

int main()
{
    ImageData *image = load_image("image.jpg");
    convert_image_to_ascii(image);

    return 0;
}