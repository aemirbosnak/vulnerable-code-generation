//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height)
{
    for (int i = 0; i < height / 2; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_value = image[i * width + j] + brightness;
            if (new_value > 255)
            {
                new_value = 255;
            }
            else if (new_value < 0)
            {
                new_value = 0;
            }
            image[i * width + j] = new_value;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int new_value = image[i * width + j] * contrast / 100;
            if (new_value > 255)
            {
                new_value = 255;
            }
            else if (new_value < 0)
            {
                new_value = 0;
            }
            image[i * width + j] = new_value;
        }
    }
}

int main()
{
    // Read the image from a file
    FILE *file = fopen("image.ppm", "rb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char header[100];
    fscanf(file, "%s", header);
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    int max_value;
    fscanf(file, "%d", &max_value);

    unsigned char *image = malloc(width * height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 150);

    // Write the image to a file
    file = fopen("new_image.ppm", "wb");
    fprintf(file, "%s\n", header);
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", max_value);
    fwrite(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    // Free the allocated memory
    free(image);

    return 0;
}