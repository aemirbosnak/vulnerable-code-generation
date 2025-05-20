//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **image, int width, int height)
{
    int i, j, k;
    char **ascii_image = NULL;

    ascii_image = malloc(height * sizeof(char *) + 1);
    for (i = 0; i < height; i++)
    {
        ascii_image[i] = malloc(width * sizeof(char) + 1);
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int pixel_value = image[i][j];
            switch (pixel_value)
            {
                case 0:
                    ascii_image[i][j] = ' ';
                    break;
                case 1:
                    ascii_image[i][j] = '.';
                    break;
                case 2:
                    ascii_image[i][j] = '=';
                    break;
                case 3:
                    ascii_image[i][j] = '*';
                    break;
                case 4:
                    ascii_image[i][j] = '#';
                    break;
                default:
                    ascii_image[i][j] = '?';
                    break;
            }
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c ", ascii_image[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < height; i++)
    {
        free(ascii_image[i]);
    }
    free(ascii_image);
}

int main()
{
    char **image = NULL;
    int width = 5;
    int height = 5;

    image = malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        image[i] = malloc(width * sizeof(char) + 1);
    }

    image[0][0] = 1;
    image[0][1] = 2;
    image[0][2] = 3;
    image[0][3] = 4;
    image[0][4] = 5;

    image[1][0] = 2;
    image[1][1] = 3;
    image[1][2] = 4;
    image[1][3] = 5;
    image[1][4] = 1;

    image_to_ascii(image, width, height);

    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}