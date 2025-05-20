//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **image, int width, int height)
{
    int i, j, pixel_value, ascii_value;
    char **ascii_image = NULL;

    ascii_image = malloc(height * sizeof(char *));
    for (i = 0; i < height; i++)
    {
        ascii_image[i] = malloc(width * sizeof(char));
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pixel_value = image[i][j];
            ascii_value = pixel_value / 2;
            ascii_image[i][j] = ascii_value + 32;
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%c ", ascii_image[i][j]);
        }
        printf("\n");
    }

    free(ascii_image);
    free(image);
}

int main()
{
    char **image = NULL;
    int width, height;

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    image = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        image[i] = malloc(width * sizeof(char));
    }

    printf("Enter the pixels of the image (separated by commas): ");
    scanf("%s", image);

    image_to_ascii(image, width, height);

    free(image);

    return 0;
}