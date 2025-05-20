//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define a structure for storing the pixel color values
typedef struct rgb
{
    int r;
    int g;
    int b;
} rgb_t;

// Function to read image data from a file and return a pointer to the pixel array
rgb_t* readImage(char* filename, int* width, int* height)
{
    FILE* fp;
    char ch;
    int r, g, b;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read image dimensions
    fscanf(fp, "%d %d\n", width, height);

    // Allocate memory for pixel array
    rgb_t* pixels = (rgb_t*) malloc((*width) * (*height) * sizeof(rgb_t));

    // Read pixel data
    for (int i = 0; i < (*width) * (*height); i++)
    {
        fscanf(fp, "%d %d %d%c", &r, &g, &b, &ch);
        pixels[i].r = r;
        pixels[i].g = g;
        pixels[i].b = b;
    }

    // Close file
    fclose(fp);

    return pixels;
}

// Function to write pixel data to a file
void writeImage(char* filename, int width, int height, rgb_t* pixels)
{
    FILE* fp;

    // Open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error: Could not open file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write image dimensions
    fprintf(fp, "%d %d\n", width, height);

    // Write pixel data
    for (int i = 0; i < width * height; i++)
    {
        fprintf(fp, "%d %d %d\n", pixels[i].r, pixels[i].g, pixels[i].b);
    }

    // Close file
    fclose(fp);
}

// Function to change the brightness of an image
void changeBrightness(rgb_t* pixels, int width, int height, int value)
{
    for (int i = 0; i < width * height; i++)
    {
        pixels[i].r += value;
        pixels[i].g += value;
        pixels[i].b += value;

        // Ensure that the color values do not exceed 255 or fall below 0
        if (pixels[i].r > 255) pixels[i].r = 255;
        if (pixels[i].g > 255) pixels[i].g = 255;
        if (pixels[i].b > 255) pixels[i].b = 255;
        if (pixels[i].r < 0) pixels[i].r = 0;
        if (pixels[i].g < 0) pixels[i].g = 0;
        if (pixels[i].b < 0) pixels[i].b = 0;
    }
}

// Function to apply a sepia tone to an image
void applySepia(rgb_t* pixels, int width, int height)
{
    for (int i = 0; i < width * height; i++)
    {
        rgb_t currentColor = pixels[i];

        // Calculate new color values using the Sepia algorithm
        int newRed = (int)(currentColor.r * 0.393 + currentColor.g * 0.769 + currentColor.b * 0.189);
        int newGreen = (int)(currentColor.r * 0.349 + currentColor.g * 0.686 + currentColor.b * 0.168);
        int newBlue = (int)(currentColor.r * 0.272 + currentColor.g * 0.534 + currentColor.b * 0.131);

        // Ensure that the color values do not exceed 255
        if (newRed > 255) newRed = 255;
        if (newGreen > 255) newGreen = 255;
        if (newBlue > 255) newBlue = 255;

        // Update the pixel with the new color values
        pixels[i].r = newRed;
        pixels[i].g = newGreen;
        pixels[i].b = newBlue;
    }
}

// Function to apply a gaussian blur to an image
void applyGaussianBlur(rgb_t* pixels, int width, int height)
{
    // Define the blur kernel
    float kernel[5][5] = {{0.003, 0.013, 0.022, 0.013, 0.003},
                          {0.013, 0.059, 0.097, 0.059, 0.013},
                          {0.022, 0.097, 0.159, 0.097, 0.022},
                          {0.013, 0.059, 0.097, 0.059, 0.013},
                          {0.003, 0.013, 0.022, 0.013, 0.003}};

    // Loop over each pixel in the image
    for (int y = 2; y < height - 2; y++)
    {
        for (int x = 2; x < width - 2; x++)
        {
            float sumR = 0;
            float sumG = 0;
            float sumB = 0;

            // Apply the kernel to each neighboring pixel
            for (int j = 0; j < 5; j++)
            {
                for (int i = 0; i < 5; i++)
                {
                    float factor = kernel[j][i];
                    sumR += factor * pixels[(y + j - 2) * width + x + i - 2].r;
                    sumG += factor * pixels[(y + j - 2) * width + x + i - 2].g;
                    sumB += factor * pixels[(y + j - 2) * width + x + i - 2].b;
                }
            }

            // Update the current pixel with the summed color values
            pixels[y * width + x].r = (int)sumR;
            pixels[y * width + x].g = (int)sumG;
            pixels[y * width + x].b = (int)sumB;

            // Ensure that the color values do not exceed 255
            if (pixels[y * width + x].r > 255) pixels[y * width + x].r = 255;
            if (pixels[y * width + x].g > 255) pixels[y * width + x].g = 255;
            if (pixels[y * width + x].b > 255) pixels[y * width + x].b = 255;
        }
    }
}

int main()
{
    int width, height;
    rgb_t* pixels;

    // Read input image
    pixels = readImage("input.txt", &width, &height);

    // Change brightness of image
    changeBrightness(pixels, width, height, 50);

    // Apply sepia tone to image
    applySepia(pixels, width, height);

    // Apply gaussian blur to image
    applyGaussianBlur(pixels, width, height);

    // Write output image
    writeImage("output.txt", width, height, pixels);

    // Free memory allocated for pixel array
    free(pixels);

    return 0;
}