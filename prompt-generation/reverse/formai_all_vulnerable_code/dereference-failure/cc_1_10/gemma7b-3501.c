//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertImageToASCII(char **image)
{
    int height = image[0] - 1;
    int width = image[1] - 1;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixelValue = image[2][y * width + x];
            switch (pixelValue)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **image = malloc(sizeof(char *) * 3);
    image[0] = 5;
    image[1] = 5;
    image[2] = malloc(sizeof(char) * 25);
    image[2][0] = 0;
    image[2][1] = 1;
    image[2][2] = 2;
    image[2][3] = 1;
    image[2][4] = 0;

    convertImageToASCII(image);

    free(image[2]);
    free(image);

    return 0;
}