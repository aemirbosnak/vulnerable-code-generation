//FormAI DATASET v1.0 Category: Image compression ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the image
#define MAX_IMAGE_SIZE 1000

// Define the maximum number of bits for the compressed data
#define MAX_COMPRESSED_SIZE 5000

// Define the maximum number of unique pixels in the image
#define MAX_PIXELS 256

// Helper function to get the index of a pixel color
int getPixelColorIndex(int pixelColor, int *pixelColors, int numUniquePixels)
{
    int i;
    for (i = 0; i < numUniquePixels; i++) {
        if (pixelColor == pixelColors[i]) {
            return i;
        }
    }
    return -1;
}

// Main function to compress an image
void compressImage(int **image, int width, int height, int numUniquePixels, int *pixelColors, int *compressedData, int *compressedSize)
{
    int i, j, pixelColor, prevPixelColorIndex, currPixelColorIndex, numRepeatingPixels;
    *compressedSize = 0;

    // Iterate through all pixels in the image
    for (i = 0; i < height; i++) {
        prevPixelColorIndex = -1;
        numRepeatingPixels = 1;

        for (j = 0; j < width; j++) {
            pixelColor = image[i][j];

            // Get the index of the current pixel color
            currPixelColorIndex = getPixelColorIndex(pixelColor, pixelColors, numUniquePixels);

            // If the current pixel color is not in the list of unique pixels, add it
            if (currPixelColorIndex == -1) {
                pixelColors[numUniquePixels] = pixelColor;
                currPixelColorIndex = numUniquePixels;
                numUniquePixels++;
            }

            // If the current pixel color is the same as the previous pixel color, increase the count of repeating pixels
            if (prevPixelColorIndex == currPixelColorIndex && numRepeatingPixels < 127) {
                numRepeatingPixels++;
            } else {
                // Otherwise, compress the previous repeating pixels and add the current pixel
                compressedData[*compressedSize] = numRepeatingPixels;
                compressedData[*compressedSize+1] = prevPixelColorIndex;
                *compressedSize += 2;

                prevPixelColorIndex = currPixelColorIndex;
                numRepeatingPixels = 1;
            }
        }

        // Compress any remaining repeating pixels
        compressedData[*compressedSize] = numRepeatingPixels;
        compressedData[*compressedSize+1] = prevPixelColorIndex;
        *compressedSize += 2;
    }
}

int main()
{
    int i, j, width, height, numUniquePixels = 0, compressedSize = 0;
    int **image;
    int pixelColors[MAX_PIXELS];
    int compressedData[MAX_COMPRESSED_SIZE];

    // Read in the image width and height
    printf("Enter the image width and height:\n");
    scanf("%d %d", &width, &height);

    // Allocate memory for the image
    image = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    // Read in the image data
    printf("Enter the image data:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Compress the image
    compressImage(image, width, height, numUniquePixels, pixelColors, compressedData, &compressedSize);

    // Print the compressed data
    printf("Compressed data:\n");
    for (i = 0; i < compressedSize; i++) {
        printf("%d ", compressedData[i]);
    }

    // Free the memory allocated for the image
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}