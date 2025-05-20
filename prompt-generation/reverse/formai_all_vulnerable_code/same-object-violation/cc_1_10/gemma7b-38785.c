//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void embed_data(unsigned char *image, int image_size, char *data, int data_size)
{
    int i, j, k;

    for (i = 0; i < data_size; i++)
    {
        for (j = 0; j < image_size; j++)
        {
            k = (j + i) % image_size;
            image[k] ^= (data[i] & 0x0F) << 2;
        }
    }
}

void extract_data(unsigned char *image, int image_size, char *data, int *data_size)
{
    int i, j, k, count = 0;

    for (i = 0; i < image_size; i++)
    {
        for (j = 0; j < data_size; j++)
        {
            k = (j + i) % image_size;
            if (image[k] & 0x0F)
                count++;
        }
    }

    *data_size = count;
    data = malloc(count);

    for (i = 0; i < image_size; i++)
    {
        for (j = 0; j < data_size; j++)
        {
            k = (j + i) % image_size;
            if (image[k] & 0x0F)
                data[j] = (image[k] >> 2) & 0x0F;
        }
    }
}

int main()
{
    unsigned char image[MAX] = "This is an image.";
    char data[] = "Secret message!";
    int image_size = 256;
    int data_size = 0;

    embed_data(image, image_size, data, data_size);

    extract_data(image, image_size, data, &data_size);

    printf("Extracted data: %s\n", data);

    free(data);

    return 0;
}