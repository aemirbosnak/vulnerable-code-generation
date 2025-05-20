//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LENGTH 256

typedef struct Watermark
{
    char* data;
    int length;
} Watermark;

Watermark watermark_create(int length)
{
    Watermark watermark;
    watermark.data = malloc(length);
    watermark.length = length;
    return watermark;
}

void watermark_embed(Watermark watermark, char* image, int image_length)
{
    int i, j, k;
    for (i = 0; i < watermark.length; i++)
    {
        for (j = 0; j < image_length; j++)
        {
            for (k = 0; k < 3; k++)
            {
                int pixel_value = image[j * 3 + k] & 0xFF;
                pixel_value += watermark.data[i] & 0xFF;
                image[j * 3 + k] = pixel_value & 0xFF;
            }
        }
    }
}

int main()
{
    char* image = "image.jpg";
    char* watermark = "Secret message";

    int image_length = 1024 * 1024 * 3;
    int watermark_length = strlen(watermark) + 1;

    Watermark watermark_obj = watermark_create(watermark_length);
    strcpy(watermark_obj.data, watermark);

    watermark_embed(watermark_obj, image, image_length);

    return 0;
}