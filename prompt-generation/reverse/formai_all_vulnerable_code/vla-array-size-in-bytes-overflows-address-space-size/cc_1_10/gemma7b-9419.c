//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    printf("Enter image data (separate pixels with spaces): ");
    fgets(image, 1024, stdin);

    int width, height;
    printf("Enter image width: ");
    scanf("%d", &width);

    printf("Enter image height: ");
    scanf("%d", &height);

    int pixels[width * height];
    char ascii[width * height];

    // Convert image data to pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels[i * width + j] = image[i * width + j] - '0';
        }
    }

    // Convert pixels to ASCII art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ascii[i * width + j] = pixels[i * width + j] + 'A';
        }
    }

    // Print ASCII art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", ascii[i * width + j]);
        }
        printf("\n");
    }

    return 0;
}