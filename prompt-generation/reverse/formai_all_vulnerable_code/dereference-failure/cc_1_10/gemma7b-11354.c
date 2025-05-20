//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
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
                    printf("...... ");
                    break;
                case 7:
                    printf("------- ");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    // Example image data
    unsigned char image[3][5] = {
        {0, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 1, 0}
    };

    image_to_ascii(image, 5, 3);

    return 0;
}