//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

void image_to_ascii(int **img, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int pixel_value = img[y][x];
            switch (pixel_value)
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
                case 4:
                    printf("# ");
                    break;
                case 5:
                    printf("$ ");
                    break;
                default:
                    printf("! ");
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
    int **img = (int **)malloc(h * sizeof(int *) + h);
    for (int i = 0; i < h; i++)
    {
        img[i] = (int *)malloc(w * sizeof(int) + w);
    }

    // Image data
    img[0][0] = 2;
    img[0][1] = 4;
    img[0][2] = 1;
    img[0][3] = 3;
    img[0][4] = 0;
    img[1][0] = 0;
    img[1][1] = 2;
    img[1][2] = 2;
    img[1][3] = 1;
    img[1][4] = 0;
    img[2][0] = 1;
    img[2][1] = 1;
    img[2][2] = 3;
    img[2][3] = 2;
    img[2][4] = 0;
    img[3][0] = 0;
    img[3][1] = 0;
    img[3][2] = 0;
    img[3][3] = 1;
    img[3][4] = 0;
    img[4][0] = 0;
    img[4][1] = 0;
    img[4][2] = 0;
    img[4][3] = 0;
    img[4][4] = 1;

    image_to_ascii(img, w, h);

    free(img);
    return 0;
}