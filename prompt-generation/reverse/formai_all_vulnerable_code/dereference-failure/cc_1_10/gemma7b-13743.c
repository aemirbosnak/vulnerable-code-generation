//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **img = NULL;
    int w, h, i, j, k, l, watermark_pos = 0;

    // Allocate memory for the image
    img = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        img[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the image
    FILE *fp = fopen("image.jpg", "rb");
    if (fp == NULL)
    {
        printf("Error reading image file");
        exit(1);
    }

    // Get the image dimensions
    w = fread(&w, 1, sizeof(int), fp);
    h = fread(&h, 1, sizeof(int), fp);

    // Decode the image
    fread(img, w * h * 3, MAX * MAX, fp);

    // Create the watermark
    char watermark[10] = "SECRET MESSAGE";
    int watermark_len = strlen(watermark);

    // Hide the watermark in the image
    for (k = 0; k < watermark_len; k++)
    {
        l = rand() % w;
        j = rand() % h;
        img[l][j] ^= 0x5F;
    }

    // Save the watermarked image
    fp = fopen("watermarked_image.jpg", "wb");
    if (fp == NULL)
    {
        printf("Error saving watermarked image file");
        exit(1);
    }

    fwrite(img, w * h * 3, MAX * MAX, fp);
    fclose(fp);

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}