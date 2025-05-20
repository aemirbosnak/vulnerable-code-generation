//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed secret message into an image
void embedMessage(char *imageName, char *secretMessage) {
    // Open the image file in read/write mode
    FILE *image = fopen(imageName, "r+b");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the size of the secret message
    int secretMessageSize = strlen(secretMessage);

    // Check if the image is large enough to hold the secret message
    fseek(image, 0, SEEK_END);
    int imageSize = ftell(image);
    if (imageSize < secretMessageSize) {
        fprintf(stderr, "Error: Image is too small to hold the secret message\n");
        exit(1);
    }

    // Reset the file pointer to the beginning of the file
    fseek(image, 0, SEEK_SET);

    // Embed the secret message into the image
    for (int i = 0; i < secretMessageSize; i++) {
        // Get the least significant bit of the current pixel
        unsigned char pixel;
        fread(&pixel, 1, 1, image);
        unsigned char lsb = pixel & 1;

        // Modify the least significant bit of the pixel to match the secret message bit
        if (secretMessage[i] == '1') {
            pixel |= 1;
        } else {
            pixel &= ~1;
        }

        // Write the modified pixel back to the image
        fseek(image, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, image);
    }

    // Close the image file
    fclose(image);
}

// Function to extract secret message from an image
char *extractMessage(char *imageName) {
    // Open the image file in read mode
    FILE *image = fopen(imageName, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the size of the image
    fseek(image, 0, SEEK_END);
    int imageSize = ftell(image);

    // Allocate memory for the secret message
    char *secretMessage = (char *)malloc(imageSize);

    // Reset the file pointer to the beginning of the file
    fseek(image, 0, SEEK_SET);

    // Extract the secret message from the image
    int i = 0;
    while (ftell(image) < imageSize) {
        // Get the least significant bit of the current pixel
        unsigned char pixel;
        fread(&pixel, 1, 1, image);
        unsigned char lsb = pixel & 1;

        // Append the least significant bit to the secret message
        secretMessage[i++] = lsb + '0';
    }

    // Close the image file
    fclose(image);

    // Return the secret message
    return secretMessage;
}

// Main function
int main() {
    // Embed secret message into an image
    embedMessage("image.bmp", "Hello world!");

    // Extract secret message from the image
    char *secretMessage = extractMessage("image.bmp");

    // Print the secret message
    printf("Secret message: %s\n", secretMessage);

    // Free the memory allocated for the secret message
    free(secretMessage);

    return 0;
}