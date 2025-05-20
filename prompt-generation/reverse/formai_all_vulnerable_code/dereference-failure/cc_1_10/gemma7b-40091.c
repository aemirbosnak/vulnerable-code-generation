//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertImageToASCII(char **image)
{
    int width = image[0][0];
    int height = image[0][1];

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
                default:
                    printf("Error! ");
            }
        }

        printf("\n");
    }
}

int main()
{
    char **image = malloc(10 * sizeof(char *));
    image[0] = malloc(10 * sizeof(char));
    image[0][0] = 5;
    image[0][1] = 5;

    image[1] = malloc(10 * sizeof(char));
    image[1][0] = 2;
    image[1][1] = 3;

    convertImageToASCII(image);

    free(image[0]);
    free(image);

    return 0;
}