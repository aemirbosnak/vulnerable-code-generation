//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to hide the secret message in the image
void hideMessage(char *imageName, char *message) {
    // Open the image file in read-write mode
    FILE *image = fopen(imageName, "r+");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the file size
    fseek(image, 0, SEEK_END);
    long fileSize = ftell(image);
    rewind(image);

    // Check if the message is too long to fit in the image
    if (strlen(message) > fileSize / 2) {
        fprintf(stderr, "Error: Message is too long to fit in the image\n");
        exit(1);
    }

    // Convert the message to binary
    char binaryMessage[strlen(message) * 8 + 1];
    for (int i = 0; i < strlen(message); i++) {
        for (int j = 7; j >= 0; j--) {
            binaryMessage[i * 8 + j] = (message[i] >> j) & 1 ? '1' : '0';
        }
    }

    // Hide the binary message in the image
    for (int i = 0; i < strlen(binaryMessage); i++) {
        // Get the current pixel value
        unsigned char pixel;
        fread(&pixel, 1, 1, image);

        // Modify the least significant bit of the pixel to match the binary message
        pixel = (pixel & 0xFE) | (binaryMessage[i] - '0');

        // Write the modified pixel back to the image
        fseek(image, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, image);
    }

    // Close the image file
    fclose(image);
}

// Function to extract the secret message from the image
char *extractMessage(char *imageName) {
    // Open the image file in read mode
    FILE *image = fopen(imageName, "r");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the file size
    fseek(image, 0, SEEK_END);
    long fileSize = ftell(image);
    rewind(image);

    // Create a buffer to store the binary message
    char binaryMessage[fileSize * 8 + 1];

    // Extract the binary message from the image
    for (int i = 0; i < fileSize; i++) {
        // Get the current pixel value
        unsigned char pixel;
        fread(&pixel, 1, 1, image);

        // Extract the least significant bit of the pixel
        binaryMessage[i * 8] = (pixel & 1) + '0';
    }

    // Close the image file
    fclose(image);

    // Convert the binary message to a string
    char *message = malloc(strlen(binaryMessage) / 8 + 1);
    for (int i = 0; i < strlen(binaryMessage) / 8; i++) {
        for (int j = 0; j < 8; j++) {
            message[i] |= (binaryMessage[i * 8 + j] - '0') << j;
        }
    }

    return message;
}

int main() {
    // Hide the secret message in the image
    hideMessage("image.bmp", "Hello, world!");

    // Extract the secret message from the image
    char *message = extractMessage("image.bmp");

    // Print the secret message
    printf("%s\n", message);

    // Free the allocated memory
    free(message);

    return 0;
}