//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSB_BIT 0x01

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGBPixel;

int main() {
    // Let's be happy and hide a secret message in an image!

    // Open the image file
    FILE *imageFile = fopen("happy.bmp", "rb");
    if (imageFile == NULL) {
        printf("Oops, couldn't find the happy image!\n");
        return 1;
    }

    // Skip the BMP header (54 bytes)
    fseek(imageFile, 54, SEEK_SET);

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);

    // Allocate memory for the image data
    RGBPixel *imageData = malloc(sizeof(RGBPixel) * width * height);

    // Read the image data
    fread(imageData, sizeof(RGBPixel), width * height, imageFile);

    // Close the image file
    fclose(imageFile);

    // Open the text file containing the secret message
    FILE *textFile = fopen("secret.txt", "rb");
    if (textFile == NULL) {
        printf("Oops, couldn't find the secret message!\n");
        return 1;
    }

    // Read the secret message
    char *secretMessage = malloc(1024);
    fread(secretMessage, sizeof(char), 1024, textFile);

    // Close the text file
    fclose(textFile);

    // Embed the secret message in the image data
    int messageLength = strlen(secretMessage);
    int messageIndex = 0;
    for (int i = 0; i < width * height && messageIndex < messageLength; i++) {
        // Get the current pixel
        RGBPixel *pixel = &imageData[i];

        // Embed the lowest bit of the secret message in the least significant bit of the blue channel
        pixel->blue &= ~LSB_BIT;
        pixel->blue |= (secretMessage[messageIndex] & LSB_BIT);

        // Increment the message index
        messageIndex++;
    }

    // Open the output image file
    FILE *outputImageFile = fopen("secret.bmp", "wb");
    if (outputImageFile == NULL) {
        printf("Oops, couldn't create the secret image!\n");
        return 1;
    }

    // Write the BMP header
    fseek(outputImageFile, 0, SEEK_SET);
    fwrite("BM", 2, 1, outputImageFile);
    fwrite(&width, sizeof(int), 1, outputImageFile);
    fwrite(&height, sizeof(int), 1, outputImageFile);

    // Write the image data
    fwrite(imageData, sizeof(RGBPixel), width * height, outputImageFile);

    // Close the output image file
    fclose(outputImageFile);

    // Free the allocated memory
    free(imageData);
    free(secretMessage);

    // Mission accomplished! We've hidden the secret message in the image.
    printf("Hooray! The secret message is now hidden in the happy image.\n");

    return 0;
}