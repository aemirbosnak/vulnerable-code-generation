//FormAI DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum length of the message
#define MAX_MSG_LENGTH 1000

// Define a constant for the maximum length of the image name
#define MAX_IMAGE_NAME_LENGTH 100

// Define a constant for the number of bits to use for steganography
#define STEGO_BIT_LENGTH 2

// Define a constant for the mask used to retrieve the stegano bits
#define STEGO_BIT_MASK ((1 << STEGO_BIT_LENGTH) - 1)

// Define a function to read the message from the user
void readMessage(char *message) {
    printf("Enter the message to hide in the image: ");
    fgets(message, MAX_MSG_LENGTH, stdin);
    // Remove the newline character from the end of the message
    message[strlen(message) - 1] = '\0';
}

// Define a function to read the name of the image file
void readImageName(char *imageName) {
    printf("Enter the name of the image file: ");
    fgets(imageName, MAX_IMAGE_NAME_LENGTH, stdin);
    // Remove the newline character from the end of the image name
    imageName[strlen(imageName) - 1] = '\0';
}

// Define a function to hide a message in an image by altering the least significant bits of each pixel
void hideMessageInImage(char *message, char *imageName) {
    FILE *image;
    // Open the image file for reading and writing in binary mode
    if ((image = fopen(imageName, "r+b")) == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }
    char pixel;
    unsigned int stegoBits;
    unsigned int messageIndex = 0;
    while (message[messageIndex] != '\0') {
        // Read a pixel from the image file
        fread(&pixel, sizeof(pixel), 1, image);
        // Fetch the stegano bits from the pixel
        stegoBits = pixel & STEGO_BIT_MASK;
        // Insert the message bits into the stegano bits
        stegoBits |= ((unsigned int)message[messageIndex] << STEGO_BIT_LENGTH);
        // Write the updated stegano bits back into the pixel
        pixel = (char)((pixel & ~STEGO_BIT_MASK) | stegoBits);
        // Write the updated pixel back into the image file
        fwrite(&pixel, sizeof(pixel), 1, image);
        messageIndex++;
    }
    // Write the end-of-message byte
    stegoBits = '\0' & STEGO_BIT_MASK;
    pixel = (char)((pixel & ~STEGO_BIT_MASK) | stegoBits);
    fwrite(&pixel, sizeof(pixel), 1, image);
    printf("The message has been hidden in the image!\n");
    // Close the image file
    fclose(image);
}

// Define a function to retrieve a message from an image by extracting the least significant bits from each pixel
void retrieveMessageFromImage(char *imageName) {
    FILE *image;
    // Open the image file for reading in binary mode
    if ((image = fopen(imageName, "rb")) == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }
    char pixel;
    unsigned int stegoBits = 0;
    unsigned int messageIndex = 0;
    char message[MAX_MSG_LENGTH];
    while (1) {
        // Read a pixel from the image file
        fread(&pixel, sizeof(pixel), 1, image);
        // Extract the stegano bits from the pixel
        stegoBits |= (pixel & STEGO_BIT_MASK);
        // Check if we have retrieved enough bits for a character
        if (messageIndex % sizeof(char) == 0 && messageIndex > 0) {
            // Convert the stegano bits back into a character and add it to the message
            message[messageIndex / sizeof(char) - 1] = (char)(stegoBits >> STEGO_BIT_LENGTH);
            if (message[messageIndex / sizeof(char) - 1] == '\0') {
                break;
            }
            stegoBits = 0;
        }
        messageIndex += STEGO_BIT_LENGTH;
    }
    printf("The hidden message in the image is:\n%s\n", message);
    // Close the image file
    fclose(image);
}

int main() {
    char message[MAX_MSG_LENGTH];
    char imageName[MAX_IMAGE_NAME_LENGTH];
    // Read the message from the user
    readMessage(message);
    // Read the name of the image file from the user
    readImageName(imageName);
    // Hide the message in the image
    hideMessageInImage(message, imageName);
    // Retrieve the message from the image
    retrieveMessageFromImage(imageName);
    return 0;
}