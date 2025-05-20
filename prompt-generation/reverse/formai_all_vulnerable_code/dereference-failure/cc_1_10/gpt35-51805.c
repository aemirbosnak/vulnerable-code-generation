//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Function to set the least significant bit of pixel to given bit
char setLSB(char pixel, char bit) {
    // Clear the last bit of pixel
    pixel &= 0xFE;
    // Set the last bit to given bit
    pixel |= bit;
    return pixel;
}

// Function to extract the last bit of pixel
char extractLSB(char pixel) {
    // Extract the last bit of pixel
    return (pixel & 0x01);
}

// Function to hide the message in the image
void hideMessageInImage(char *message, char *imageFilePath, char *outputFilePath) {
    // Open the input image file
    FILE *fpImage = fopen(imageFilePath, "rb");
    // Open the output file for writing
    FILE *fpOutput = fopen(outputFilePath, "wb");

    // Copy the first 54 bytes of input file to the output file
    char buffer[BUFFER_SIZE];
    int bytesRead = fread(buffer, 1, 54, fpImage);
    fwrite(buffer, 1, bytesRead, fpOutput);

    int messageIndex = 0;
    // Loop through each pixel in the image
    while (bytesRead = fread(buffer, 1, BUFFER_SIZE, fpImage)) {
        for (int i = 0; i < bytesRead; i += 3) {
            // Extract the red, green and blue components of the pixel
            char red = buffer[i];
            char green = buffer[i+1];
            char blue = buffer[i+2];

            // Check if we still have characters to hide in the message
            if (message[messageIndex] != '\0') {
                // Get the least significant bit of the message character
                char bitToHide = extractLSB(message[messageIndex]);
                // Update the red component of the pixel to hide the bit
                red = setLSB(red, bitToHide);
                // Increment the message index
                messageIndex++;
            }

            // Check if we still have characters to hide in the message
            if (message[messageIndex] != '\0') {
                // Get the least significant bit of the message character
                char bitToHide = extractLSB(message[messageIndex]);
                // Update the green component of the pixel to hide the bit
                green = setLSB(green, bitToHide);
                // Increment the message index
                messageIndex++;
            }

            // Check if we still have characters to hide in the message
            if (message[messageIndex] != '\0') {
                // Get the least significant bit of the message character
                char bitToHide = extractLSB(message[messageIndex]);
                // Update the blue component of the pixel to hide the bit
                blue = setLSB(blue, bitToHide);
                // Increment the message index
                messageIndex++;
            }

            // Write the updated pixel back to output file
            buffer[i] = red;
            buffer[i+1] = green;
            buffer[i+2] = blue;
        }
        fwrite(buffer, 1, bytesRead, fpOutput);
    }

    // Close the input and output files
    fclose(fpImage);
    fclose(fpOutput);
}

// Function to get the hidden message from the image
char *getHiddenMessageFromImage(char *imageFilePath) {
    // Open the input image file
    FILE *fpImage = fopen(imageFilePath, "rb");

    // Skip the first 54 bytes (header) of the image file
    fseek(fpImage, 54, SEEK_SET);

    char buffer[BUFFER_SIZE];
    int bytesRead = 0;
    int messageIndex = 0;
    char currentChar = 0;
    char *message = (char *)malloc(sizeof(char) * (BUFFER_SIZE * 3 + 1));

    // Loop through each pixel in the image
    while (bytesRead = fread(buffer, 1, BUFFER_SIZE, fpImage)) {
        for (int i = 0; i < bytesRead; i += 3) {
            // Extract the red, green and blue components of the pixel
            char red = buffer[i];
            char green = buffer[i+1];
            char blue = buffer[i+2];

            // Get the least significant bit of each component and combine them to form a character
            currentChar |= extractLSB(red);
            currentChar |= extractLSB(green) << 1;
            currentChar |= extractLSB(blue) << 2;

            // Check if we have read a complete character from the pixel
            if ((messageIndex % 3 == 2) || (messageIndex == BUFFER_SIZE * 3 - 1)) {
                // Append the current character to the message
                message[messageIndex / 3] = currentChar;
                currentChar = 0;
            }

            // Increment the message index
            messageIndex++;
        }
    }

    // Null terminate the message string
    message[messageIndex / 3] = '\0';

    // Close the input file
    fclose(fpImage);

    // Return the hidden message
    return message;
}

int main() {
    char *message = "This is a secret message";
    char *imageFilePath = "./input.bmp";
    char *outputFilePath = "./output.bmp";

    // Hide the message in the image file
    hideMessageInImage(message, imageFilePath, outputFilePath);

    // Get the hidden message from the output image file
    char *hiddenMessage = getHiddenMessageFromImage(outputFilePath);

    // Print the hidden message
    printf("Hidden message: %s\n", hiddenMessage);

    // Free the memory allocated for message and hiddenMessage
    free(message);
    free(hiddenMessage);

    return 0;
}