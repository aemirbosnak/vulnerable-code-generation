//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

int main()
{
    char watermark[] = "SECRET MESSAGE";
    int watermark_len = strlen(watermark);

    char image_data[] = "IMAGE.JPG";
    FILE* image_file = fopen(image_data, "r");
    if (image_file == NULL)
    {
        return -1;
    }

    int image_size = 0;
    int image_width = 0;
    int image_height = 0;

    unsigned char* image_buffer = NULL;
    while (!feof(image_file))
    {
        image_buffer = (unsigned char*)realloc(image_buffer, image_size + 1);
        image_size++;
        fread(image_buffer, 1, 1, image_file);
    }

    fclose(image_file);

    // Calculate image dimensions
    image_width = (int)(image_buffer[0] & 0xFF) << 8 | image_buffer[1] & 0xFF;
    image_height = (int)(image_buffer[2] & 0xFF) << 8 | image_buffer[3] & 0xFF;

    // Calculate the average pixel value
    int average_pixel_value = (image_buffer[image_size - 1] & 0xFF) + (image_buffer[image_size - 2] & 0xFF) + (image_buffer[image_size - 3] & 0xFF) / 3;

    // Embed the watermark
    for (int i = 0; i < watermark_len; i++)
    {
        image_buffer[image_size] = (average_pixel_value * i) % 256 + watermark[i] * 2;
        image_size++;
    }

    // Save the watermarked image
    image_file = fopen("WATERMARKED_IMAGE.JPG", "w");
    fwrite(image_buffer, 1, image_size, image_file);
    fclose(image_file);

    return 0;
}