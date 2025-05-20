//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void image_to_ascii(unsigned char **image, int width, int height)
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
                    printf("·");
                    break;
                case 2:
                    printf("○");
                    break;
                case 3:
                    printf("●");
                    break;
                case 4:
                    printf("★");
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
    unsigned char **image = malloc(10 * sizeof(unsigned char *));
    for (int i = 0; i < 10; i++)
    {
        image[i] = malloc(10 * sizeof(unsigned char));
    }

    image[0][0] = 2;
    image[0][1] = 1;
    image[0][2] = 0;
    image[0][3] = 2;
    image[0][4] = 1;

    image_to_ascii(image, 5, 1);

    for (int i = 0; i < 10; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}