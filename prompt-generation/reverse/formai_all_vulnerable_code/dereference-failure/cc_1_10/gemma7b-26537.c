//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void image_to_ascii(int **img, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int pixel = img[y][x];
            switch (pixel)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("o ");
                    break;
                case 3:
                    printf("* ");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int w = 5;
    int h = 5;
    int **img = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        img[i] = (int *)malloc(w * sizeof(int));
    }

    img[0][0] = 2;
    img[0][1] = 1;
    img[0][2] = 2;
    img[0][3] = 0;
    img[0][4] = 1;

    img[1][0] = 1;
    img[1][1] = 2;
    img[1][2] = 1;
    img[1][3] = 0;
    img[1][4] = 2;

    image_to_ascii(img, w, h);

    free(img);

    return 0;
}