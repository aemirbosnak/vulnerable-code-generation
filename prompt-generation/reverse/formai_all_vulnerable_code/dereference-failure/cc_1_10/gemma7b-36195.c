//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

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
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("# ");
                    break;
                default:
                    printf("Error ");
                    break;
            }
        }

        printf("\n");
    }
}

int main()
{
    // Example image
    char image[MAX_IMAGE_SIZE] = {
        0, 1, 1, 0, 0,
        1, 1, 1, 1, 1,
        1, 1, 1, 1, 1,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0
    };

    int width = 5;
    int height = 5;

    convertImageToASCII(image, width, height);

    return 0;
}