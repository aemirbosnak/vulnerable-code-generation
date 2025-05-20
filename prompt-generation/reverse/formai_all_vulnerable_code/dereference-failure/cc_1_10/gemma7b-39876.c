//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

void image_to_ascii(char **image, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_value = image[y][x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf(".. ");
                    break;
                case 3:
                    printf("... ");
                    break;
                case 4:
                    printf(".... ");
                    break;
                case 5:
                    printf("..... ");
                    break;
                case 6:
                    printf("______ ");
                    break;
                case 7:
                    printf("  \\_/_ ");
                    break;
                case 8:
                    printf("   \\_/");
                    break;
                case 9:
                    printf("    \\_/");
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
        image[i] = malloc(MAX_WIDTH * sizeof(char));
    }

    // Fill the image with pixel values
    image[0][0] = 5;
    image[0][1] = 2;
    image[0][2] = 4;
    image[0][3] = 8;
    image[1][0] = 3;
    image[1][1] = 6;
    image[1][2] = 1;
    image[1][3] = 9;

    image_to_ascii(image, MAX_WIDTH, 2);

    for (int i = 0; i < 10; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}