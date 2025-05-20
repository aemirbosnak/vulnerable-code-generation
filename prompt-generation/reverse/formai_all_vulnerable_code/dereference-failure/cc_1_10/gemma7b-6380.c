//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int width, height;
    printf("Enter the image width: ");
    scanf("%d", &width);

    printf("Enter the image height: ");
    scanf("%d", &height);

    char **image = (char**)malloc(height * sizeof(char *) + 1);
    for (int h = 0; h < height; h++)
    {
        image[h] = (char *)malloc(width * sizeof(char) + 1);
    }

    printf("Enter the image data: ");
    scanf("%s", image);

    char **ascii_art = (char**)malloc(height * sizeof(char *) + 1);
    for (int h = 0; h < height; h++)
    {
        ascii_art[h] = (char *)malloc(width * sizeof(char) + 1);
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int pixel_value = image[h][w];
            ascii_art[h][w] = pixel_value + 32;
        }
    }

    printf("Your ASCII art:\n");
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    free(image);
    free(ascii_art);

    return 0;
}