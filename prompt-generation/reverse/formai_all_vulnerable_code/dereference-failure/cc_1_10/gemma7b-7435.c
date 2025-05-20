//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **image, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int pixel_value = image[y][x];
            switch (pixel_value)
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
    // Example image data
    char **image = malloc(5 * sizeof(char *));
    image[0] = malloc(10 * sizeof(char));
    image[1] = malloc(10 * sizeof(char));
    image[2] = malloc(10 * sizeof(char));
    image[3] = malloc(10 * sizeof(char));
    image[4] = malloc(10 * sizeof(char));

    image[0][0] = 1;
    image[0][1] = 0;
    image[0][2] = 2;
    image[0][3] = 1;
    image[0][4] = 0;
    image[0][5] = 1;
    image[0][6] = 2;
    image[0][7] = 1;
    image[0][8] = 0;
    image[0][9] = 2;

    image[1][0] = 0;
    image[1][1] = 1;
    image[1][2] = 0;
    image[1][3] = 1;
    image[1][4] = 2;
    image[1][5] = 0;
    image[1][6] = 1;
    image[1][7] = 0;
    image[1][8] = 1;
    image[1][9] = 0;

    image_to_ascii(image, 10, 2);

    free(image);

    return 0;
}