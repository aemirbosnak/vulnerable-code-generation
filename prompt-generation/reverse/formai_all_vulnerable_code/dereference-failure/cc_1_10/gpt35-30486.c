//FormAI DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Struct to hold the pixel's RGB values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Function to get the least significant bit of a byte
unsigned char getLSB(unsigned char byte) {
    return byte & 1;
}

// Function to set the least significant bit of a byte
void setLSB(unsigned char *byte, unsigned char bit) {
    *byte &= ~1;
    *byte |= (bit & 1);
}

// Function to hide a secret message in an image
void hideMessageInImage(char *imagePath, char *secretMessage) {

    // Open the image file
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        printf("Error: Could not open image file.");
        return;
    }

    // Read the image header
    char header[54];
    fread(header, sizeof(char), 54, imageFile);

    // Get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the number of pixels in the image
    int numPixels = width * height;

    // Allocate memory for the pixel array
    Pixel *pixels = (Pixel*) malloc(numPixels * sizeof(Pixel));

    // Read the pixels from the image file
    fread(pixels, sizeof(Pixel), numPixels, imageFile);

    // Close the image file
    fclose(imageFile);

    // Open the output file
    FILE *outputFile = fopen("output.bmp", "wb");
    if (!outputFile) {
        printf("Error: Could not open output file.");
        free(pixels);
        return;
    }

    // Write the header to the output file
    fwrite(header, sizeof(char), 54, outputFile);

    // Copy each pixel from the input image to the output image, hiding bits of the secret message in the blue channel
    int pixelIndex = 0;
    int messageIndex = 0;
    char currentByte = secretMessage[messageIndex];
    while (messageIndex < strlen(secretMessage)) {

        // Get the current pixel
        Pixel p = pixels[pixelIndex];

        // Set the least significant bit of the blue channel to the current bit of the secret message
        setLSB(&p.b, getLSB(currentByte));

        // Write the modified pixel to the output image
        fwrite(&p, sizeof(Pixel), 1, outputFile);

        // Move on to the next pixel and bit of the secret message
        pixelIndex++;
        messageIndex++;

        // If we've reached the end of the message, reset the current byte to 0
        if (messageIndex >= strlen(secretMessage)) {
            currentByte = 0;
        }
        // Otherwise, get the next byte of the secret message
        else {
            currentByte = secretMessage[messageIndex];
        }
    }

    // Copy any remaining pixels from the input image to the output image
    for (int i = pixelIndex; i < numPixels; i++) {
        fwrite(&pixels[i], sizeof(Pixel), 1, outputFile);
    }

    // Close the output file and free the pixel array
    fclose(outputFile);
    free(pixels);
}

// Function to extract a secret message from an image
char* extractMessageFromImage(char *imagePath) {

    // Open the image file
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        printf("Error: Could not open image file.");
        return NULL;
    }

    // Read the image header
    char header[54];
    fread(header, sizeof(char), 54, imageFile);

    // Get the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the number of pixels in the image
    int numPixels = width * height;

    // Allocate memory for the pixel array
    Pixel *pixels = (Pixel*) malloc(numPixels * sizeof(Pixel));

    // Read the pixels from the image file
    fread(pixels, sizeof(Pixel), numPixels, imageFile);

    // Close the image file
    fclose(imageFile);

    // Extract the secret message from the blue channel of the pixels
    char *secretMessage = (char*) malloc(numPixels * sizeof(char));
    int messageIndex = 0;
    char currentByte = 0;
    int bitIndex = 0;
    for (int i = 0; i < numPixels; i++) {

        // Get the current pixel
        Pixel p = pixels[i];

        // Get the least significant bit of the blue channel
        unsigned char bit = getLSB(p.b);

        // Set the corresponding bit of the current byte to the least significant bit of the blue channel
        currentByte |= (bit << bitIndex);
        bitIndex++;

        // If we've processed 8 bits, add the current byte to the secret message and move on to the next byte
        if (bitIndex >= 8) {
            secretMessage[messageIndex++] = currentByte;
            currentByte = 0;
            bitIndex = 0;
        }
    }

    // Null terminate the secret message string and free the pixel array
    secretMessage[messageIndex] = '\0';
    free(pixels);

    // Return the secret message string
    return secretMessage;
}

int main() {

    // Hide a secret message in the provided image
    char imagePath[] = "lenna.bmp";
    char secretMessage[] = "Hello, world!";
    hideMessageInImage(imagePath, secretMessage);

    // Extract the secret message from the manipulated image and print it to the console
    char *extractedMessage = extractMessageFromImage("output.bmp");
    printf("Extracted message: %s", extractedMessage);
    free(extractedMessage);

    return 0;
}