//Gemma-7B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void image_processing(unsigned char **img, int w, int h)
{
    int x, y;
    for (x = 0; x < w; x++)
    {
        for (y = 0; y < h; y++)
        {
            img[x][y] = (img[x][y] * 2) % 255;
        }
    }
}

int main()
{
    unsigned char **img = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    img = (unsigned char **)malloc(w * h * sizeof(unsigned char *));
    for (int i = 0; i < h; i++)
    {
        img[i] = (unsigned char *)malloc(w * sizeof(unsigned char));
    }

    printf("Enter the pixels of the image: ");
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            scanf("%d ", &img[x][y]);
        }
    }

    image_processing(img, w, h);

    printf("The processed image is:\n");
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            printf("%d ", img[x][y]);
        }
        printf("\n");
    }

    free(img);

    return 0;
}