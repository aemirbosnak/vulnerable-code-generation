//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reshapeImage(unsigned char **image, int w, int h)
{
    int newW = w * 2;
    int newH = h * 2;
    unsigned char **newImage = (unsigned char **)malloc(newH * sizeof(unsigned char *) + newW * sizeof(unsigned char));

    for (int i = 0; i < newH; i++)
    {
        newImage[i] = (unsigned char *)malloc(newW * sizeof(unsigned char));
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            newImage[2 * i][2 * j] = image[i][j];
            newImage[2 * i][2 * j + 1] = image[i][j];
            newImage[2 * i + 1][2 * j] = image[i][j];
            newImage[2 * i + 1][2 * j + 1] = image[i][j];
        }
    }

    free(image);
    image = newImage;
    w *= 2;
    h *= 2;
}

int main()
{
    unsigned char **image = (unsigned char **)malloc(5 * sizeof(unsigned char *) + 10 * sizeof(unsigned char));

    for (int i = 0; i < 5; i++)
    {
        image[i] = (unsigned char *)malloc(10 * sizeof(unsigned char));
    }

    image[0][0] = 255;
    image[0][1] = 0;
    image[0][2] = 0;
    image[0][3] = 255;
    image[0][4] = 0;

    image[1][0] = 0;
    image[1][1] = 255;
    image[1][2] = 0;
    image[1][3] = 0;
    image[1][4] = 255;

    reshapeImage(image, 10, 5);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    free(image);

    return 0;
}