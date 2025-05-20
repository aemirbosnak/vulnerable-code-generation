//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <string.h>

void image_to_ascii(char **img, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            int pixel_value = (int)img[r][c];
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
                    printf("$");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **img = NULL;
    int w = 5;
    int h = 5;

    img = malloc(h * w * sizeof(char *));
    for (int r = 0; r < h; r++)
    {
        img[r] = malloc(w * sizeof(char));
    }

    img[0][0] = 1;
    img[0][1] = 3;
    img[0][2] = 2;
    img[0][3] = 1;
    img[0][4] = 0;

    img[1][0] = 2;
    img[1][1] = 2;
    img[1][2] = 2;
    img[1][3] = 1;
    img[1][4] = 0;

    image_to_ascii(img, w, h);

    free(img);

    return 0;
}