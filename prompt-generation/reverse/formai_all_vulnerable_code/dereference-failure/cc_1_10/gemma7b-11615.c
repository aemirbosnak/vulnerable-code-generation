//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    char **image = (char **)malloc(height * sizeof(char *) + 1);

    for (int i = 0; i < height; i++)
    {
        image[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    printf("Enter the pixels of the image (separated by commas): ");
    char pixels[1024];
    scanf("%s", pixels);

    int pixelIndex = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = pixels[pixelIndex];
            pixelIndex++;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch (image[i][j])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }

    free(image);

    return 0;
}