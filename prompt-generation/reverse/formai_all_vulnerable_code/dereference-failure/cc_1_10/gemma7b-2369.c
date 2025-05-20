//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void edit_image(int **image, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = image[y][x] * 2;
        }
    }
}

int main()
{
    int width = 5;
    int height = 5;
    int **image = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        image[i] = malloc(width * sizeof(int));
    }

    // Initialize the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = 0;
        }
    }

    // Edit the image
    edit_image(image, width, height);

    // Display the image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            printf("%d ", image[y][x]);
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