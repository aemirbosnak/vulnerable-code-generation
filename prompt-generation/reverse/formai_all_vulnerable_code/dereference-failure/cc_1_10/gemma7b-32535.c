//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

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
                    printf(".");
                    break;
                case 2:
                    printf(",");
                    break;
                case 3:
                    printf("$");
                    break;
                case 4:
                    printf("%");
                    break;
                default:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **image = NULL;
    int width = 0;
    int height = 0;

    image = malloc(height * width * sizeof(char *));
    for (int i = 0; i < height * width; i++)
    {
        image[i] = malloc(sizeof(char));
    }

    // Fill the image with sample data
    image[0][0] = 2;
    image[0][1] = 1;
    image[1][0] = 0;
    image[1][1] = 3;

    width = 2;
    height = 2;

    convertImageToASCII(image, width, height);

    free(image);

    return 0;
}