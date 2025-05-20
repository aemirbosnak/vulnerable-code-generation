//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void watermark(int **img, int w, int h)
{
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            int pixel = img[i][j];
            pixel = (pixel + 13) % MAX;
            img[i][j] = pixel;
        }
    }
}

int main()
{
    int w, h;
    scanf("Enter the width of the image: ", &w);
    scanf("Enter the height of the image: ", &h);

    int **img = (int **)malloc(h * w * sizeof(int));

    for (int i = 0; i < h; i++)
    {
        img[i] = (int *)malloc(w * sizeof(int));
    }

    // Read the image data
    printf("Enter the image data: ");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%d ", &img[i][j]);
        }
    }

    // Watermark the image
    watermark(img, w, h);

    // Print the watermarked image
    printf("The watermarked image is:\n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}