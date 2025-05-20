//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed the secret message into the image
void embedSecretMessage(char *image, char *secretMessage) {
    int imageSize = strlen(image);
    int secretMessageSize = strlen(secretMessage);

    // Check if the secret message is too large to be embedded in the image
    if (secretMessageSize > imageSize) {
        printf("Error: Secret message is too large to be embedded in the image.\n");
        exit(1);
    }

    // Embed the secret message into the image
    for (int i = 0; i < secretMessageSize; i++) {
        // Convert the secret message character to binary
        int secretMessageChar = secretMessage[i];
        for (int j = 7; j >= 0; j--) {
            // Get the j-th bit of the secret message character
            int bit = (secretMessageChar >> j) & 1;

            // Embed the bit into the image
            int imageCharIndex = i * 8 + j;
            int imageChar = image[imageCharIndex];
            imageChar = (imageChar & 0xFE) | bit;
            image[imageCharIndex] = imageChar;
        }
    }
}

// Function to extract the secret message from the image
char *extractSecretMessage(char *image) {
    int imageSize = strlen(image);

    // Calculate the size of the secret message
    int secretMessageSize = imageSize / 8;

    // Extract the secret message from the image
    char *secretMessage = malloc(secretMessageSize + 1);
    for (int i = 0; i < secretMessageSize; i++) {
        // Extract the i-th character of the secret message
        int secretMessageChar = 0;
        for (int j = 0; j < 8; j++) {
            // Get the j-th bit of the i-th character of the secret message
            int imageCharIndex = i * 8 + j;
            int imageChar = image[imageCharIndex];
            int bit = imageChar & 1;

            // Shift the secret message character to the left by 1 bit
            secretMessageChar = (secretMessageChar << 1) | bit;
        }

        // Append the i-th character of the secret message to the secret message
        secretMessage[i] = secretMessageChar;
    }

    // Add a null terminator to the secret message
    secretMessage[secretMessageSize] = '\0';

    return secretMessage;
}

int main() {
    // Read the image from a file
    FILE *imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open the image file.\n");
        exit(1);
    }
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    char *image = malloc(imageSize + 1);
    fread(image, 1, imageSize, imageFile);
    fclose(imageFile);

    // Read the secret message from a file
    FILE *secretMessageFile = fopen("secretMessage.txt", "rb");
    if (secretMessageFile == NULL) {
        printf("Error: Could not open the secret message file.\n");
        exit(1);
    }
    fseek(secretMessageFile, 0, SEEK_END);
    int secretMessageSize = ftell(secretMessageFile);
    fseek(secretMessageFile, 0, SEEK_SET);
    char *secretMessage = malloc(secretMessageSize + 1);
    fread(secretMessage, 1, secretMessageSize, secretMessageFile);
    fclose(secretMessageFile);

    // Embed the secret message into the image
    embedSecretMessage(image, secretMessage);

    // Write the stego-image to a file
    FILE *stegoImageFile = fopen("stegoImage.bmp", "wb");
    if (stegoImageFile == NULL) {
        printf("Error: Could not open the stego-image file.\n");
        exit(1);
    }
    fwrite(image, 1, imageSize, stegoImageFile);
    fclose(stegoImageFile);

    // Extract the secret message from the stego-image
    char *extractedSecretMessage = extractSecretMessage(image);

    // Print the extracted secret message to the console
    printf("Extracted secret message: %s\n", extractedSecretMessage);

    // Free the allocated memory
    free(image);
    free(secretMessage);
    free(extractedSecretMessage);

    return 0;
}