//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void imgToAscii(char **img, int w, int h)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            int pixel = img[r][c];
            switch (pixel)
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
                default:
                    printf("Error!");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    char **img = NULL;
    int w = 0, h = 0;

    // Allocate memory for the image
    img = (char **)malloc(h * sizeof(char *) + w * sizeof(char));
    for (int i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char));
    }

    // Get the image data
    w = 5;
    h = 5;
    img[0][0] = 1;
    img[0][1] = 2;
    img[0][2] = 3;
    img[0][3] = 2;
    img[0][4] = 1;
    img[1][0] = 2;
    img[1][1] = 3;
    img[1][2] = 3;
    img[1][3] = 2;
    img[1][4] = 1;

    // Convert the image to ASCII art
    imgToAscii(img, w, h);

    // Free the memory allocated for the image
    for (int i = 0; i < h; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}