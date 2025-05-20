//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to read the image file
void readImage(FILE *file, char *imageData, int imageSize)
{
    // Read image data
    fread(imageData, sizeof(char), imageSize, file);
}

// Function to convert pixel value to ASCII char
char pixelToChar(char r, char g, char b)
{
    // Calculate grayscale value
    int grayScale = (0.299 * r) + (0.587 * g) + (0.114 * b);

    // Define ASCII char based on grayscale value
    if (grayScale > 230)
        return ' ';
    else if (grayScale > 200)
        return '.';
    else if (grayScale > 180)
        return '*';
    else if (grayScale > 160)
        return ':';
    else if (grayScale > 130)
        return 'o';
    else if (grayScale > 100)
        return '&';
    else if (grayScale > 70)
        return '8';
    else if (grayScale > 50)
        return '#';
    else
        return '@';
}

// Function to convert image to ASCII art
void convertToAscii(char *imageData, int imageWidth, int imageHeight)
{
    // Loop through each pixel in the image
    int i, j, k = 0;
    for (i = 0; i < imageHeight; i++)
    {
        for (j = 0; j < imageWidth; j++)
        {
            // Get RGB values of current pixel
            char r = imageData[k];
            char g = imageData[k + 1];
            char b = imageData[k + 2];

            // Convert pixel to ASCII char
            char asciiChar = pixelToChar(r, g, b);

            // Print ASCII char to console
            printf("%c", asciiChar);

            // Increment k to move to next pixel
            k += 3;
        }

        // Newline character after each row
        printf("\n");
    }
}

int main()
{
    // Open image file
    FILE *file = fopen("image.jpg", "rb");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    int imageSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for image data
    char *imageData = (char *)malloc(imageSize);

    // Read image data from file
    readImage(file, imageData, imageSize);

    // Close image file
    fclose(file);

    // Get image width and height
    int imageWidth = 640;
    int imageHeight = 480;

    // Convert image to ASCII art
    convertToAscii(imageData, imageWidth, imageHeight);

    // Free memory allocated for image data
    free(imageData);

    return 0;
}