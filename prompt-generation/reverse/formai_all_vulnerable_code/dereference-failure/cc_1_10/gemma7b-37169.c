//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    int **image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    printf("Enter the pixels of the image (separated by commas): ");
    char input[1000];
    scanf("%s", input);

    // Convert the input string into an array of integers
    int numPixels = 0;
    int pixels[1000];
    char *ptr = input;
    while (*ptr)
    {
        pixels[numPixels++] = atoi(ptr);
        ptr++;
    }

    // Create the ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int pixelValue = image[h][w];
            switch (pixelValue)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("# ");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}