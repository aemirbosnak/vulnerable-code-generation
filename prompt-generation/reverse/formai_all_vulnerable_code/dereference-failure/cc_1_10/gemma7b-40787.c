//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct Watermark
{
    char data[MAX_WATERMARK_LENGTH];
    int length;
} Watermark;

Watermark watermark_create(char *data, int length)
{
    Watermark watermark;
    watermark.length = length;
    memcpy(watermark.data, data, length);

    return watermark;
}

void watermark_embed(Watermark watermark, unsigned char *image, int image_size)
{
    for (int i = 0; i < watermark.length && i < image_size; i++)
    {
        image[i] ^= watermark.data[i];
    }
}

int watermark_detect(Watermark watermark, unsigned char *image, int image_size)
{
    for (int i = 0; i < watermark.length && i < image_size; i++)
    {
        if (image[i] ^ watermark.data[i] != image[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char watermark_data[] = "My secret message";
    int watermark_length = strlen(watermark_data) + 1;

    Watermark watermark = watermark_create(watermark_data, watermark_length);

    unsigned char image[] = "my_image.jpg";
    int image_size = 1024 * 1024;

    watermark_embed(watermark, image, image_size);

    if (watermark_detect(watermark, image, image_size))
    {
        printf("Watermark detected!\n");
    } else
    {
        printf("Watermark not detected.\n");
    }

    return 0;
}