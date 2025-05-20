//FormAI DATASET v1.0 Category: Image Editor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the image file and store pixel data
void readImage(char* filename, unsigned char* imageData, int imageSize) {
    FILE* filePtr = fopen(filename, "rb");
    if (filePtr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fread(imageData, sizeof(unsigned char), imageSize, filePtr);
    fclose(filePtr);
}

// Function to write the modified pixel data to a new file
void writeImage(char* filename, unsigned char* modifiedImageData, int imageSize) {
    FILE* filePtr = fopen(filename, "wb");
    if (filePtr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fwrite(modifiedImageData, sizeof(unsigned char), imageSize, filePtr);
    fclose(filePtr);
}

// Function to flip the image horizontally
void flipHorizontal(unsigned char* imageData, int height, int width) {
    int row, col;
    for (row = 0; row < height; ++row) {
        for (col = 0; col < width/2; ++col) {
            int pixelIndex = row*width + col;
            int oppositePixelIndex = row*width + (width - col - 1);
            unsigned char temp = imageData[pixelIndex];
            imageData[pixelIndex] = imageData[oppositePixelIndex];
            imageData[oppositePixelIndex] = temp;
        }
    }
}

// Function to convert the image to grayscale
void convertToGrayscale(unsigned char* imageData, int imageSize) {
    int i;
    for (i = 0; i < imageSize; i += 3) {
        unsigned char red = imageData[i];
        unsigned char green = imageData[i+1];
        unsigned char blue = imageData[i+2];
        unsigned char gray = 0.2126*red + 0.7152*green + 0.0722*blue;
        imageData[i] = gray;
        imageData[i+1] = gray;
        imageData[i+2] = gray;
    }
}

int main() {
    char inputFilename[50];
    printf("Enter the filename of the input image: ");
    scanf("%s", inputFilename);

    unsigned char* imageData;
    int height, width;
    char header[54];

    FILE* filePtr = fopen(inputFilename, "rb");
    if (filePtr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the header information from the image file
    fread(header, sizeof(unsigned char), 54, filePtr);

    // Extract the height and width information from the header
    height = *(int*)&header[18];
    width = *(int*)&header[22];

    int imageSize = height*width*3;
    imageData = (unsigned char*)malloc(imageSize);

    // Read the pixel data from the image file
    readImage(inputFilename, imageData, imageSize);

    // Manipulate the pixel data by flipping horizontally and converting to grayscale
    flipHorizontal(imageData, height, width);
    convertToGrayscale(imageData, imageSize);

    // Write the modified pixel data to a new file
    char outputFilename[50];
    printf("Enter the filename of the output image: ");
    scanf("%s", outputFilename);

    writeImage(outputFilename, imageData, imageSize);

    printf("Image processing complete!\n");

    return 0;
}