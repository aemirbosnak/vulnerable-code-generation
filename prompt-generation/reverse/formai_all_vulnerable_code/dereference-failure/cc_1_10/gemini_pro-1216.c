//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Constants
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define MAX_MESSAGE_LENGTH 1024

// Function to hide the message in the image
void hideMessage(unsigned char *image, char *message) {
    int i, j, k;
    int messageLength = strlen(message);
    
    // Iterate over the image pixels
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            // Get the least significant bit of the pixel
            unsigned char lsb = image[i * IMAGE_WIDTH + j] & 1;

            // If there is still a character to hide, replace the lsb with the lsb of the character
            if (k < messageLength) {
                image[i * IMAGE_WIDTH + j] |= ((message[k] >> (7 - lsb)) & 1) << lsb;
                k++;
            }
        }
    }
}

// Function to extract the message from the image
char *extractMessage(unsigned char *image) {
    int i, j, k;
    char *message = malloc(MAX_MESSAGE_LENGTH + 1);
    
    // Iterate over the image pixels
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            // Get the least significant bit of the pixel
            unsigned char lsb = image[i * IMAGE_WIDTH + j] & 1;

            // If the lsb is 1, append the character to the message
            if (lsb) {
                message[k++] = '1';
            } else {
                message[k++] = '0';
            }
        }
    }
    
    // Null-terminate the message
    message[k] = '\0';
    
    return message;
}

int main() {
    // Load the image from a file
    FILE *imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }
    unsigned char *image = malloc(IMAGE_WIDTH * IMAGE_HEIGHT);
    fread(image, 1, IMAGE_WIDTH * IMAGE_HEIGHT, imageFile);
    fclose(imageFile);

    // Get the message to hide
    char *message = "Hello, world!";

    // Hide the message in the image
    hideMessage(image, message);

    // Save the modified image to a file
    FILE *outputImageFile = fopen("output.bmp", "wb");
    if (outputImageFile == NULL) {
        printf("Error opening output image file.\n");
        return 1;
    }
    fwrite(image, 1, IMAGE_WIDTH * IMAGE_HEIGHT, outputImageFile);
    fclose(outputImageFile);

    // Extract the message from the modified image
    char *extractedMessage = extractMessage(image);

    // Print the extracted message
    printf("Extracted message: %s\n", extractedMessage);

    // Free the allocated memory
    free(image);
    free(extractedMessage);

    return 0;
}