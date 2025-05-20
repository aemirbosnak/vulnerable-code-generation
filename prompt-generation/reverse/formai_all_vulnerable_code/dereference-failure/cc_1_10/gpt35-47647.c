//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally 
void flip_horizontal(int width, int height, int image[height][width])
{
    int i, j, temp;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width/2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to adjust brightness and contrast 
void adjust_brightness_contrast(int width, int height, int image[height][width], float brightness, float contrast)
{
    int i, j;
    int pixel_value;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pixel_value = image[i][j];
            pixel_value = (int)((pixel_value - 128) * contrast + 128 + brightness);
            if (pixel_value < 0)
            {
                pixel_value = 0;
            }
            if (pixel_value > 255)
            {
                pixel_value = 255;
            }
            image[i][j] = pixel_value;
        }
    }
}

// Function to print the image
void print_image(int width, int height, int image[height][width])
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Create a sample image
    int image[4][4] = {{10, 20, 30, 40},
                       {50, 60, 70, 80},
                       {90, 100, 110, 120},
                       {130, 140, 150, 160}};

    // Flip the image horizontally
    flip_horizontal(4, 4, image);
    printf("Image after horizontal flip:\n");
    print_image(4, 4, image);

    // Adjust brightness and contrast
    adjust_brightness_contrast(4, 4, image, 20.0, 0.5);
    printf("Image after brightness and contrast adjustment:\n");
    print_image(4, 4, image);

    return 0;
}