//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void image_to_ascii(char **img, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int pixel_value = img[y][x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf(":");
                    break;
                case 3:
                    printf("#");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **img = malloc(MAX_SIZE);
    img[0] = malloc(MAX_SIZE);
    img[1] = malloc(MAX_SIZE);

    // Sample image data
    img[0][0] = 0;
    img[0][1] = 1;
    img[0][2] = 2;
    img[0][3] = 3;
    img[0][4] = 0;

    img[1][0] = 1;
    img[1][1] = 2;
    img[1][2] = 3;
    img[1][3] = 0;
    img[1][4] = 1;

    image_to_ascii(img, 5, 2);

    free(img[0]);
    free(img[1]);
    free(img);

    return 0;
}