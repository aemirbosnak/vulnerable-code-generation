//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertImageToAscii(char **image, int width, int height)
{
    int i, j, k, l, pixelValue;
    char asciiArt[height][width];

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            asciiArt[i][j] = ' ';
        }
    }

    for (k = 0; k < height; k++)
    {
        for (l = 0; l < width; l++)
        {
            pixelValue = image[k][l];
            switch (pixelValue)
            {
                case 0:
                    asciiArt[k][l] = ' ';
                    break;
                case 1:
                    asciiArt[k][l] = '. ';
                    break;
                case 2:
                    asciiArt[k][l] = '* ';
                    break;
                case 3:
                    asciiArt[k][l] = '# ';
                    break;
                default:
                    asciiArt[k][l] = 'O ';
                    break;
            }
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char **image = NULL;
    int width, height;

    // Allocate memory for the image
    image = (char **)malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        image[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    // Get the image dimensions
    printf("Enter the image width:");
    scanf("%d", &width);

    printf("Enter the image height:");
    scanf("%d", &height);

    // Get the image data
    printf("Enter the image data:");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%d ", &image[i][j]);
        }
    }

    // Convert the image to ASCII art
    convertImageToAscii(image, width, height);

    // Free the memory
    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}