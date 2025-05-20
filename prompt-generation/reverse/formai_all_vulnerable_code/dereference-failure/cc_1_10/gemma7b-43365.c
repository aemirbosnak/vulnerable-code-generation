//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **image, int w, int h)
{
    int i, j, k;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            int pixel_value = image[i][j];
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
    char **image = NULL;
    int w, h;

    // Allocate memory for the image
    image = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        image[i] = malloc(sizeof(char) * 10);
    }

    // Get the image width and height
    printf("Enter the image width: ");
    scanf("%d", &w);

    printf("Enter the image height: ");
    scanf("%d", &h);

    // Get the image pixels
    printf("Enter the image pixels (separated by commas): ");
    char pixel_str[1000];
    scanf("%s", pixel_str);

    // Convert the pixel string into an image array
    int i = 0;
    for (char *pixel = pixel_str; *pixel != '\0'; pixel++)
    {
        image[i / w][i % w] = atoi(pixel);
        i++;
    }

    // Convert the image to ASCII art
    image_to_ascii(image, w, h);

    // Free the memory allocated for the image
    for (int i = 0; i < 5; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}