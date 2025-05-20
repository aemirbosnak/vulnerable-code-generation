//FormAI DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 2000000

// Define a struct to store the image information
typedef struct {
    int height;
    int width;
    unsigned char *pixels;
} Image;

// Function declaration to shift the pixel values by 1
void shiftPixels(Image *image);

// Function declaration to hide the message in the image
void hideMessage(Image *image, char *message);

// Function declaration to retrieve the hidden message from the image
void retrieveMessage(Image *image, char *retrievedMessage);

int main() {
    // Initialize the image with all white pixels
    Image image;
    image.width = 512;
    image.height = 512;
    image.pixels = calloc(image.width * image.height, sizeof(unsigned char));
    
    // Load the image from file
    FILE *file = fopen("input.bmp", "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    int imageSize = image.width * image.height * 3;
    unsigned char *imageData = image.pixels;
    fread(imageData, sizeof(unsigned char), imageSize, file);
    fclose(file);
    
    // Shift the pixel values by 1
    shiftPixels(&image);
    
    // Hide the message in the image
    char message[] = "Hello World!";
    hideMessage(&image, message);
    
    // Save the modified image to file
    file = fopen("output.bmp", "wb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(imageData, sizeof(unsigned char), imageSize, file);
    fclose(file);
    
    // Retrieve the hidden message from the image
    char retrievedMessage[100];
    retrieveMessage(&image, retrievedMessage);
    printf("Retrieved message: %s\n", retrievedMessage);
    
    // Free the memory used by the image
    free(image.pixels);
    
    return 0;
}

void shiftPixels(Image *image) {
    printf("Shifting pixel values...\n");
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int offset = (i * image->width + j) * 3;
            image->pixels[offset] = ((int)image->pixels[offset] + 1) % 256;
            image->pixels[offset + 1] = ((int)image->pixels[offset + 1] + 1) % 256;
            image->pixels[offset + 2] = ((int)image->pixels[offset + 2] + 1) % 256;
        }
    }
}

void hideMessage(Image *image, char *message) {
    printf("Hiding message in image...\n");
    int messageLength = strlen(message);
    int bitIndex = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int offset = (i * image->width + j) * 3;
            if (bitIndex < messageLength * 8) {
                unsigned char currentByte = message[bitIndex / 8];
                unsigned char currentBit = (currentByte >> (bitIndex % 8)) & 1;
                unsigned char maskedPixel = image->pixels[offset] & 0xFE;
                image->pixels[offset] = maskedPixel | currentBit;
                bitIndex++;
            }
        }
    }
}

void retrieveMessage(Image *image, char *retrievedMessage) {
    printf("Retrieving message from image...\n");
    int messageIndex = 0;
    unsigned char currentByte = 0;
    int bitIndex = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int offset = (i * image->width + j) * 3;
            unsigned char currentBit = image->pixels[offset] & 1;
            currentByte |= (currentBit << bitIndex);
            bitIndex++;
            if (bitIndex == 8) {
                retrievedMessage[messageIndex++] = currentByte;
                bitIndex = 0;
                currentByte = 0;
            }
        }
    }
    retrievedMessage[messageIndex] = '\0';
}