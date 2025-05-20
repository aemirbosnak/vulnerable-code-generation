//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void image_to_ascii(unsigned char **img, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            int pixel_value = img[r][c];
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
                    printf("$");
                    break;
                case 4:
                    printf("@");
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
    unsigned char **img = NULL;
    int w = 5;
    int h = 5;

    img = (unsigned char **)malloc(h * w * sizeof(unsigned char));
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            img[r][c] = 2;
        }
    }

    image_to_ascii(img, w, h);

    free(img);

    return 0;
}