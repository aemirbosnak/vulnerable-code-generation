//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void editImage(unsigned char **image, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = (image[y][x] - 10) * 2;
        }
    }
}

int main()
{
    unsigned char **image = NULL;
    int width = 0, height = 0;

    // Get image size
    printf("Enter image width: ");
    scanf("%d", &width);

    printf("Enter image height: ");
    scanf("%d", &height);

    // Allocate memory for image
    image = (unsigned char **)malloc(height * sizeof(unsigned char *) + height);
    for (int i = 0; i < height; i++)
    {
        image[i] = (unsigned char *)malloc(width * sizeof(unsigned char) + width);
    }

    // Get image data
    printf("Enter image data (separated by commas): ");
    char data[MAX_SIZE];
    scanf("%s", data);

    // Convert data to image
    int i = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = data[i] - '0';
            i++;
        }
    }

    // Edit image
    editImage(image, width, height);

    // Display image
    printf("Edited image:\n");
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            printf("%d ", image[y][x]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}