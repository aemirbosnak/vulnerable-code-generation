//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void convert_image_to_ascii(char **image, int width, int height)
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
                    printf(".");
                    break;
                case 2:
                    printf(",");
                    break;
                case 3:
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
    char **image = malloc(5 * sizeof(char *));
    image[0] = malloc(10 * sizeof(char));
    image[1] = malloc(10 * sizeof(char));
    image[2] = malloc(10 * sizeof(char));
    image[3] = malloc(10 * sizeof(char));
    image[4] = malloc(10 * sizeof(char));

    image[0][0] = 0;
    image[0][1] = 1;
    image[0][2] = 2;
    image[0][3] = 3;
    image[0][4] = 0;
    image[0][5] = 1;
    image[0][6] = 2;
    image[0][7] = 3;
    image[0][8] = 0;
    image[0][9] = 1;

    image[1][0] = 1;
    image[1][1] = 2;
    image[1][2] = 3;
    image[1][3] = 0;
    image[1][4] = 1;
    image[1][5] = 2;
    image[1][6] = 3;
    image[1][7] = 0;
    image[1][8] = 1;
    image[1][9] = 2;

    convert_image_to_ascii(image, 10, 2);

    free(image[0]);
    free(image[1]);
    free(image[2]);
    free(image[3]);
    free(image[4]);
    free(image);

    return 0;
}