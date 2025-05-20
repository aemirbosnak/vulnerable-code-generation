//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip the image horizontally
void flipImage(char* imgFileName, char* outputFileName) {
    // Read the image file
    FILE* fp = fopen(imgFileName, "rb");
    if (!fp) {
        printf("Failed to open input file.\n");
        exit(1);
    }

    // Get the size of the image
    int width, height, channels;
    fseek(fp, 0, SEEK_END);
    size_t imgSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&channels, sizeof(int), 1, fp);

    // Allocate memory for the flipped image
    char* flippedImage = (char*)malloc(imgSize);

    // Read the flipped image from the input file
    fread(flippedImage, imgSize, 1, fp);

    // Close the input file
    fclose(fp);

    // Open the output file
    FILE* fp2 = fopen(outputFileName, "wb");
    if (!fp2) {
        printf("Failed to open output file.\n");
        exit(1);
    }

    // Write the flipped image to the output file
    fwrite(flippedImage, imgSize, 1, fp2);

    // Close the output file
    fclose(fp2);

    printf("Image successfully flipped.\n");
    free(flippedImage);
}

int main() {
    // Input file name
    char* imgFileName = "input.jpg";
    // Output file name
    char* outputFileName = "output.jpg";

    flipImage(imgFileName, outputFileName);

    return 0;
}