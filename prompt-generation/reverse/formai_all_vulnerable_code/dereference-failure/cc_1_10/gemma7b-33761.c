//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char watermark[MAX_SIZE];
    char image[MAX_SIZE];
    int size, i, j, k;

    printf("Enter the size of the watermark (in bytes): ");
    scanf("%d", &size);

    printf("Enter the watermark: ");
    scanf("%s", watermark);

    printf("Enter the name of the image file: ");
    scanf("%s", image);

    FILE *fp = fopen(image, "r");
    if (fp == NULL)
    {
        printf("Error opening image file.\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    size_t imageSize = ftell(fp);

    rewind(fp);

    if (size > imageSize)
    {
        printf("Error: the watermark is too large.\n");
        exit(1);
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < imageSize; j++)
        {
            k = rand() % MAX_SIZE;
            image[j] ^= watermark[k];
        }
    }

    fclose(fp);

    printf("Watermarked image saved as %s\n", image);

    return 0;
}