//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide the secret message in the image
void hideMessage(char *imageFile, char *message) {
    // Open the image file
    FILE *image = fopen(imageFile, "rb+");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the size of the image file
    fseek(image, 0, SEEK_END);
    long fileSize = ftell(image);
    fseek(image, 0, SEEK_SET);

    // Get the length of the secret message
    int messageLength = strlen(message);

    // Check if the image file is large enough to hold the secret message
    if (fileSize < messageLength) {
        printf("Error: Image file is too small to hold the secret message\n");
        exit(1);
    }

    // Hide the secret message in the image file
    for (int i = 0; i < messageLength; i++) {
        // Get the least significant bit of the current pixel
        int bit = message[i] & 1;

        // Set the least significant bit of the current pixel to the secret message bit
        int pixelValue;
        fread(&pixelValue, 1, 1, image);
        pixelValue &= 0xFE;
        pixelValue |= bit;
        fseek(image, -1, SEEK_CUR);
        fwrite(&pixelValue, 1, 1, image);
    }

    // Close the image file
    fclose(image);
}

// Function to extract the secret message from the image
char *extractMessage(char *imageFile) {
    // Open the image file
    FILE *image = fopen(imageFile, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the size of the image file
    fseek(image, 0, SEEK_END);
    long fileSize = ftell(image);
    fseek(image, 0, SEEK_SET);

    // Extract the secret message from the image file
    char *message = malloc(fileSize + 1);
    if (message == NULL) {
        perror("Error allocating memory for secret message");
        exit(1);
    }

    for (int i = 0; i < fileSize; i++) {
        // Get the least significant bit of the current pixel
        int bit;
        fread(&bit, 1, 1, image);
        bit &= 1;

        // Append the secret message bit to the message
        message[i] = bit;
    }

    // Null-terminate the message
    message[fileSize] = '\0';

    // Close the image file
    fclose(image);

    // Return the secret message
    return message;
}

// Main function
int main() {
    // Hide the secret message in the image file
    hideMessage("image.bmp", "Hello, world!");

    // Extract the secret message from the image file
    char *message = extractMessage("image.bmp");

    // Print the secret message
    printf("Secret message: %s\n", message);

    // Free the memory allocated for the secret message
    free(message);

    return 0;
}