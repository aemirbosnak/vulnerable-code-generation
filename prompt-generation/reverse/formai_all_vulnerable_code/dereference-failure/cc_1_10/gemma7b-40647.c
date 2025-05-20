//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void img_to_ascii(char **img, int w, int h)
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
    char **img = NULL;
    int w = 0, h = 0;

    // Allocate memory for the image
    img = (char **)malloc(h * sizeof(char *) + h);
    for (int i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char) + w);
    }

    // Get the image dimensions
    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    // Get the image pixels
    printf("Enter the pixels of the image (separated by commas): ");
    char pixels[1000];
    scanf("%s", pixels);

    // Convert the pixels into an image
    int index = 0;
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            img[r][c] = pixels[index++];
        }
    }

    // Convert the image to ASCII art
    img_to_ascii(img, w, h);

    // Free the memory allocated for the image
    for (int i = 0; i < h; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}