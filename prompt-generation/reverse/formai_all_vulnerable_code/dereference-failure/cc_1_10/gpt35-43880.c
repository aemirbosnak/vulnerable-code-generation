//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flipImage(int rows, int cols, unsigned char *imageData)
{
    unsigned char temp;
    for (int i = 0; i < rows/2; i++) {
        for (int j = 0; j < cols; j++) {
            temp = imageData[i*cols + j];
            imageData[i*cols + j] = imageData[(rows-i-1)*cols + j];
            imageData[(rows-i-1)*cols + j] = temp;
        }
    }
}

// Function to change brightness and contrast of an image
void changeBrightnessAndContrast(int rows, int cols, unsigned char *imageData, int brightness, int contrast)
{
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            imageData[i*cols + j] = (unsigned char)(factor * (imageData[i*cols + j] - 128) + 128 + brightness);
        }
    }
}

int main()
{
    FILE *inputFile = fopen("inputImage.raw", "rb");
    if (inputFile == NULL) {
        printf("Error opening input image file!\n");
        return -1;
    }

    // Get the image dimensions
    int rows = 480;
    int cols = 640;

    // Allocate memory for the image data
    unsigned char *imageData = (unsigned char *)malloc(rows * cols * sizeof(unsigned char));
    if (imageData == NULL) {
        printf("Error allocating memory for image data!\n");
        return -1;
    }

    // Read the image data from the file
    size_t elementsRead = fread(imageData, sizeof(unsigned char), rows * cols, inputFile);
    if (elementsRead != rows * cols) {
        printf("Error reading image data from file!\n");
        return -1;
    }

    // Close the input file
    fclose(inputFile);

    // Flip the image
    flipImage(rows, cols, imageData);
    // Change the brightness and contrast of the image
    changeBrightnessAndContrast(rows, cols, imageData, 50, 20);

    // Write the processed image data to a new file
    FILE *outputFile = fopen("outputImage.raw", "wb");
    if (outputFile == NULL) {
        printf("Error creating output image file!\n");
        return -1;
    }
    fwrite(imageData, sizeof(unsigned char), rows * cols, outputFile);

    // Close the output file
    fclose(outputFile);

    // Free the allocated memory
    free(imageData);

    printf("Image processing completed successfully!\n");
    return 0;
}