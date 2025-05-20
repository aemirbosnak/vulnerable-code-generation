//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to hide information within an image file
bool hideInformation(const char* imagePath, const char* info) {
    // Read the image file
    FILE* imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Unable to open image file\n");
        return false;
    }
    
    // Read the image data
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);
    
    // Modify the least significant bit of each pixel
    for (int i = 0; i < imageSize; i++) {
        int pixel = imageData[i];
        if (pixel < 0x80) {
            imageData[i] = (pixel | (1 << 7));
        } else {
            imageData[i] = (pixel & ~(1 << 7));
        }
    }
    
    // Write the modified image data back to the image file
    FILE* outputFile = fopen(imagePath, "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to open output image file\n");
        return false;
    }
    fwrite(imageData, 1, imageSize, outputFile);
    fclose(outputFile);
    
    // Print the hidden information
    printf("Hidden information: %s\n", info);
    
    free(imageData);
    return true;
}

// Function to retrieve hidden information from an image file
bool retrieveInformation(const char* imagePath, char* info) {
    // Read the image file
    FILE* imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Unable to open image file\n");
        return false;
    }
    
    // Read the image data
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);
    
    // Modify the least significant bit of each pixel
    for (int i = 0; i < imageSize; i++) {
        int pixel = imageData[i];
        if (pixel < 0x80) {
            imageData[i] = (pixel & ~(1 << 7));
        } else {
            imageData[i] = (pixel | (1 << 7));
        }
    }
    
    // Print the hidden information
    int infoLength = strlen(info);
    int index = 0;
    for (int i = 0; i < imageSize; i++) {
        int pixel = imageData[i];
        if (pixel & (1 << 7)) {
            if (index < infoLength) {
                info[index] = pixel & 0x7F;
                index++;
            }
        }
    }
    
    // Print the hidden information
    printf("Hidden information: %s\n", info);
    
    free(imageData);
    return true;
}

int main() {
    // Test the steganography functions
    const char* testImagePath = "test.jpg";
    const char* testInfo = "Hello, world!";
    hideInformation(testImagePath, testInfo);
    retrieveInformation(testImagePath, testInfo);
    
    return 0;
}