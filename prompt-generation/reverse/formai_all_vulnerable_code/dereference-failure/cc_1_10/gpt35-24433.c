//FormAI DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to hide the secret message inside the image
void hideMessageInImage(char* imagePath, char* secretMessage) {

    // Open the image file
    FILE* imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    // Find the size of the image
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Read the image data into a buffer
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);

    // Open a new file to write the steganographed image
    FILE* outputImageFile = fopen("steganographed_image.bmp", "wb");
    if (outputImageFile == NULL) {
        printf("Error opening output image file.\n");
        return;
    }

    // Write the image header to the output image file
    fwrite(imageData, 1, 54, outputImageFile);

    // Calculate the size of the secret message
    int secretMessageSize = strlen(secretMessage);

    // Iterate over each pixel in the image
    for (int i = 54; i < imageSize; i += 3) {

        // Get the RGB values of the pixel
        unsigned char redPixel = imageData[i + 2];
        unsigned char greenPixel = imageData[i + 1];
        unsigned char bluePixel = imageData[i];

        // Encode the secret message in the LSB of each RGB value
        if (secretMessageSize > 0) {

            // Get the first character of the secret message
            char secretCharacter = secretMessage[0];

            // Get the bit representation of the secret character
            unsigned char bitMask = 1;
            unsigned char bitRepresentation[8];
            for (int j = 0; j < 8; j++) {
                bitRepresentation[j] = (secretCharacter & bitMask) ? 1 : 0;
                bitMask <<= 1;
            }

            // Set the LSB of the red pixel to the first bit of the secret character
            redPixel = (redPixel & 0xFE) | bitRepresentation[0];

            // Set the LSB of the green pixel to the second bit of the secret character
            greenPixel = (greenPixel & 0xFE) | bitRepresentation[1];

            // Set the LSB of the blue pixel to the third bit of the secret character
            bluePixel = (bluePixel & 0xFE) | bitRepresentation[2];

            // Write the modified RGB values to the output image file
            imageData[i + 2] = redPixel;
            imageData[i + 1] = greenPixel;
            imageData[i] = bluePixel;

            // Move on to the next character of the secret message
            secretMessage++;
            secretMessageSize--;
        }
        else {

            // If the entire message has been encoded, just write the original RGB values
            imageData[i + 2] = redPixel;
            imageData[i + 1] = greenPixel;
            imageData[i] = bluePixel;
        }
    }

    // Write the modified image data to the output image file
    fwrite(imageData, 1, imageSize, outputImageFile);

    // Close the file pointers and free the allocated memory
    fclose(imageFile);
    fclose(outputImageFile);
    free(imageData);

    printf("Steganography complete - secret message encoded in image.\n");
}

// Function to extract the secret message from the steganographed image
char* extractMessageFromImage(char* imagePath) {

    // Open the steganographed image file
    FILE* imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return "";
    }

    // Find the size of the image
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    // Read the image data into a buffer
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);

    // Allocate memory for the secret message
    char* secretMessage = (char*)malloc(256);
    memset(secretMessage, 0, sizeof(secretMessage));

    // Iterate over each pixel in the image
    for (int i = 54; i < imageSize; i += 3) {

        // Get the RGB values of the pixel
        unsigned char redPixel = imageData[i + 2];
        unsigned char greenPixel = imageData[i + 1];
        unsigned char bluePixel = imageData[i];

        // Extract the LSB of each RGB value to reconstruct the secret message
        unsigned char secretCharacter = (redPixel & 0x1) |
            ((greenPixel & 0x1) << 1) |
            ((bluePixel & 0x1) << 2);

        // Append the reconstructed character to the secret message
        strncat(secretMessage, (char*)&secretCharacter, 1);
    }

    // Close the file pointer and free the allocated memory
    fclose(imageFile);
    free(imageData);

    printf("Secret message extracted from image: %s\n", secretMessage);

    return secretMessage;
}

int main() {
    // Hide the secret message inside the image
    hideMessageInImage("image.bmp", "This is a secret message!");

    // Extract the secret message from the steganographed image
    extractMessageFromImage("steganographed_image.bmp");

    return 0;
}