//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image horizontally
void flipImageHorizontal(int image[][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int temp = image[i][j];
            image[i][j] = image[rows-1-i][j];
            image[rows-1-i][j] = temp;
        }
    }
}

// Function to change brightness of an image
void changeBrightness(int image[][100], int rows, int cols, double factor)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int temp = image[i][j];
            image[i][j] = (int)(temp * factor);
        }
    }
}

// Function to change contrast of an image
void changeContrast(int image[][100], int rows, int cols, double factor)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int temp = image[i][j];
            image[i][j] = (int)(temp * (1 - factor) + 255 * factor);
        }
    }
}

int main()
{
    // Create a sample image of size 3x3
    int image[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Flip the image horizontally
    flipImageHorizontal(image, 3, 3);

    // Change brightness by a factor of 2
    changeBrightness(image, 3, 3, 2);

    // Change contrast by a factor of 0.5
    changeContrast(image, 3, 3, 0.5);

    // Print the modified image
    printf("Modified Image: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}