//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void convertImageToASCII(char **image, int x, int y)
{
    if (x >= 0 && y >= 0)
    {
        switch (image[x][y])
        {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("=");
                break;
            case 2:
                printf("#");
                break;
            default:
                printf("!");
                break;
        }
        convertImageToASCII(image, x - 1, y);
        convertImageToASCII(image, x, y - 1);
    }
}

int main()
{
    char **image = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        image[i] = (char *)malloc(10 * sizeof(char));
    }

    image[0][0] = 2;
    image[0][1] = 1;
    image[0][2] = 0;
    image[0][3] = 2;
    image[0][4] = 0;

    image[1][0] = 1;
    image[1][1] = 2;
    image[1][2] = 1;
    image[1][3] = 0;
    image[1][4] = 1;

    image[2][0] = 0;
    image[2][1] = 1;
    image[2][2] = 0;
    image[2][3] = 1;
    image[2][4] = 0;

    image[3][0] = 2;
    image[3][1] = 1;
    image[3][2] = 0;
    image[3][3] = 2;
    image[3][4] = 0;

    image[4][0] = 0;
    image[4][1] = 1;
    image[4][2] = 0;
    image[4][3] = 1;
    image[4][4] = 0;

    convertImageToASCII(image, 4, 4);
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}