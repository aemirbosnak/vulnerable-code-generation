//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_WIDTH 150
#define MAX_HEIGHT 150

// Function to convert image to ASCII art
void convertToAsciiArt(uint8_t image[], int width, int height)
{
    // Define the characters to use for the ascii art
    const char asciiChars[] = " .'`^\",:;Il!i><~+_-?][{}1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

    // Determine the average brightness of each block of pixels
    uint8_t pixelAvg[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the RGB values for the current pixel
            uint8_t r = image[(i * width + j) * 3];
            uint8_t g = image[(i * width + j) * 3 + 1];
            uint8_t b = image[(i * width + j) * 3 + 2];

            // Compute the average brightness of the pixel using the formula from CIE 1931
            pixelAvg[i][j] = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        }
    }

    // Convert the pixel values to ASCII characters
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute the index of the corresponding ASCII character
            int index = pixelAvg[i][j] * (sizeof(asciiChars) - 1) / 255;

            // Output the character to the console
            printf("%c", asciiChars[index]);
        }

        // End the line
        printf("\n");
    }
}

int main()
{
    // Read the input file into memory
    FILE *inputFile = fopen("input.rgb", "rb");
    if (!inputFile)
    {
        printf("Unable to open input file\n");
        return 1;
    }

    // Determine the size of the image (assuming 24-bit RGB)
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    rewind(inputFile);
    int numPixels = fileSize / 3;

    // Allocate memory for the image
    uint8_t *image = (uint8_t *) malloc(numPixels * sizeof(uint8_t));
    if (!image)
    {
        printf("Unable to allocate memory for image\n");
        fclose(inputFile);
        return 1;
    }

    // Read the image data into memory
    int numBytesRead = fread(image, sizeof(uint8_t), numPixels, inputFile);
    if (numBytesRead != numPixels)
    {
        printf("Error reading image data\n");
        free(image);
        fclose(inputFile);
        return 1;
    }

    // Determine the width and height of the image
    int width = 0;
    int height = 0;
    for (int i = 0; i < numPixels; i++)
    {
        if ((i % 3) == 0)
        {
            width++;
        }

        if ((i % (3 * width)) == 0)
        {
            height++;
        }
    }

    // Make sure the image is not too large
    if ((width > MAX_WIDTH) || (height > MAX_HEIGHT))
    {
        printf("Image is too large\n");
        free(image);
        fclose(inputFile);
        return 1;
    }

    // Convert the image to ASCII art and output to the console
    convertToAsciiArt(image, width, height);

    // Clean up and exit
    free(image);
    fclose(inputFile);
    return 0;
}