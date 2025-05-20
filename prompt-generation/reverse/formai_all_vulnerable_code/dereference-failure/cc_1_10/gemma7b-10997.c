//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void watermark_image(char *image_file, char *water_mark)
{
    FILE *fp;
    unsigned char *image_data, *water_mark_data;
    int image_size, water_mark_size;

    fp = fopen(image_file, "rb");
    if (fp == NULL)
    {
        perror("Error opening image file");
        exit(1);
    }

    image_size = fread(image_data, 1, image_size, fp);
    fclose(fp);

    fp = fopen(water_mark, "rb");
    if (fp == NULL)
    {
        perror("Error opening water mark file");
        exit(1);
    }

    water_mark_size = fread(water_mark_data, 1, water_mark_size, fp);
    fclose(fp);

    // Embed water mark data into image data
    for (int i = 0; i < image_size; i++)
    {
        if (i % 1024 == 0)
        {
            image_data[i] = image_data[i] ^ water_mark_data[0];
        }
    }

    // Save the watermarked image
    fp = fopen(image_file, "wb");
    if (fp == NULL)
    {
        perror("Error saving watermarked image");
        exit(1);
    }

    fwrite(image_data, 1, image_size, fp);
    fclose(fp);

    printf("Image watermarked successfully!\n");
}

int main()
{
    char image_file[] = "image.jpg";
    char water_mark[] = "secret.txt";

    watermark_image(image_file, water_mark);

    return 0;
}