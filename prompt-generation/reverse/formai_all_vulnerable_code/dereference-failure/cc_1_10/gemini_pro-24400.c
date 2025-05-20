//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to embed a message into an image
void embedMessage(char *message, char *image, char *output) {
    // Open the message and image files
    FILE *messageFile = fopen(message, "rb");
    FILE *imageFile = fopen(image, "rb");
    FILE *outputFile = fopen(output, "wb");

    // Check if the files were opened successfully
    if (messageFile == NULL || imageFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Get the size of the message and image files
    fseek(messageFile, 0, SEEK_END);
    long messageSize = ftell(messageFile);
    rewind(messageFile);

    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);

    // Check if the message is too large to be embedded in the image
    if (messageSize > imageSize) {
        printf("Error: Message is too large to be embedded in the image.\n");
        exit(1);
    }

    // Read the message and image files into memory
    char *messageBuffer = malloc(messageSize);
    fread(messageBuffer, 1, messageSize, messageFile);

    char *imageBuffer = malloc(imageSize);
    fread(imageBuffer, 1, imageSize, imageFile);

    // Embed the message into the image
    for (int i = 0; i < messageSize; i++) {
        // Get the least significant bit of the current pixel
        int lsb = imageBuffer[i] & 1;

        // Set the least significant bit of the current pixel to the current bit of the message
        imageBuffer[i] = (imageBuffer[i] & ~1) | (messageBuffer[i] & 1);

        // If the current bit of the message is 1, set the second least significant bit of the current pixel to 1
        if (messageBuffer[i] & 1) {
            imageBuffer[i] |= 2;
        }
    }

    // Write the embedded image to the output file
    fwrite(imageBuffer, 1, imageSize, outputFile);

    // Close the files
    fclose(messageFile);
    fclose(imageFile);
    fclose(outputFile);

    // Free the memory
    free(messageBuffer);
    free(imageBuffer);
}

// Function to extract a message from an image
void extractMessage(char *image, char *output) {
    // Open the image file
    FILE *imageFile = fopen(image, "rb");

    // Check if the file was opened successfully
    if (imageFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the size of the image file
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);

    // Read the image file into memory
    char *imageBuffer = malloc(imageSize);
    fread(imageBuffer, 1, imageSize, imageFile);

    // Extract the message from the image
    char *messageBuffer = malloc(imageSize);
    int messageIndex = 0;

    for (int i = 0; i < imageSize; i++) {
        // Get the least significant bit of the current pixel
        int lsb = imageBuffer[i] & 1;

        // Get the second least significant bit of the current pixel
        int secondLsb = (imageBuffer[i] & 2) >> 1;

        // If the second least significant bit of the current pixel is 1, the current bit of the message is 1
        if (secondLsb) {
            messageBuffer[messageIndex] |= 1;
        }

        // Shift the message buffer one bit to the right
        messageBuffer[messageIndex] >>= 1;

        // If the current pixel is the last pixel in a byte, increment the message index
        if (i % 8 == 7) {
            messageIndex++;
        }
    }

    // Write the extracted message to the output file
    FILE *outputFile = fopen(output, "wb");
    fwrite(messageBuffer, 1, messageIndex, outputFile);

    // Close the files
    fclose(imageFile);
    fclose(outputFile);

    // Free the memory
    free(imageBuffer);
    free(messageBuffer);
}

int main() {
    // Embed a message into an image
    embedMessage("message.txt", "image.png", "output.png");

    // Extract the message from the image
    extractMessage("output.png", "extracted_message.txt");

    return 0;
}