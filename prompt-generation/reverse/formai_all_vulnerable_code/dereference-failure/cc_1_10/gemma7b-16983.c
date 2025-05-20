//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
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
                    printf(".");
                    break;
                case 2:
                    printf(",");
                    break;
                case 3:
                    printf("$");
                    break;
                default:
                    printf("!");
            }
        }
        printf("\n");
    }
}

int main()
{
    unsigned char **image = NULL;
    int width = 5;
    int height = 5;

    image = (unsigned char **)malloc(height * sizeof(unsigned char *) + height);
    for (int y = 0; y < height; y++)
    {
        image[y] = (unsigned char *)malloc(width * sizeof(unsigned char) + width);
    }

    // Fill the image with sample data
    image[0][0] = 3;
    image[0][1] = 2;
    image[0][2] = 1;
    image[0][3] = 0;
    image[0][4] = 1;

    image[1][0] = 2;
    image[1][1] = 1;
    image[1][2] = 2;
    image[1][3] = 0;
    image[1][4] = 2;

    image_to_ascii(image, width, height);

    free(image);

    return 0;
}