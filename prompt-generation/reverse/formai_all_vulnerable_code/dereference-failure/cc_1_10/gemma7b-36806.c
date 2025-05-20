//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertImageToASCII(char **image, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixelValue = image[y][x];
            switch (pixelValue)
            {
                case 0:
                    printf(" ");
                    break;
                case 255:
                    printf("#");
                    break;
                default:
                    printf("%c", pixelValue);
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **image = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        image[i] = malloc(10 * sizeof(char));
    }

    image[0][0] = 0;
    image[0][1] = 255;
    image[0][2] = 0;

    image[1][0] = 255;
    image[1][1] = 255;
    image[1][2] = 0;

    convertImageToASCII(image, 3, 2);

    for (int i = 0; i < 10; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}