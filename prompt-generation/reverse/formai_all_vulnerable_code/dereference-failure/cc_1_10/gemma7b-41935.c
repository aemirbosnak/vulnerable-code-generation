//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **img_data = NULL;
    int img_size = 0;
    char watermark[] = "Secret Message";

    // Allocate memory for image data
    img_data = (char **)malloc(MAX * sizeof(char *));
    for (int i = 0; i < MAX; i++)
    {
        img_data[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read image file
    FILE *fp = fopen("image.jpg", "rb");
    if (fp == NULL)
    {
        exit(1);
    }

    // Get image size
    img_size = fread(img_data[0], MAX * MAX, 1, fp);

    // Embed watermark
    int i = 0;
    for (int r = 0; r < img_size; r++)
    {
        for (int c = 0; c < img_size; c++)
        {
            img_data[r][c] ^= ( watermark[i] & 0xFF ) << 2;
            i++;
        }
    }

    // Save watermarked image
    fp = fopen("watermarked_image.jpg", "wb");
    fwrite(img_data[0], img_size, 1, fp);

    // Free memory
    for (int i = 0; i < MAX; i++)
    {
        free(img_data[i]);
    }
    free(img_data);

    return 0;
}