//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char byte;

int main() {
    // Open the cover image
    FILE *coverImage = fopen("cover.bmp", "rb");
    if (coverImage == NULL) {
        printf("Error opening cover image!\n");
        return 1;
    }

    // Read the cover image header
    byte header[54];
    fread(header, 54, 1, coverImage);

    // Get the cover image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create a new image to store the steganographed data
    FILE *stegoImage = fopen("stego.bmp", "wb");
    if (stegoImage == NULL) {
        printf("Error creating stego image!\n");
        return 1;
    }

    // Write the stego image header
    fwrite(header, 54, 1, stegoImage);

    // Read the secret message
    FILE *secretMessage = fopen("secret.txt", "rb");
    if (secretMessage == NULL) {
        printf("Error opening secret message!\n");
        return 1;
    }

    // Get the secret message length
    fseek(secretMessage, 0, SEEK_END);
    long secretMessageLength = ftell(secretMessage);
    fseek(secretMessage, 0, SEEK_SET);

    // Convert the secret message to a bit stream
    byte bitStream[secretMessageLength * 8];
    for (long i = 0; i < secretMessageLength; i++) {
        byte byte = fgetc(secretMessage);
        for (int j = 7; j >= 0; j--) {
            bitStream[i * 8 + j] = (byte >> j) & 1;
        }
    }

    // Embed the secret message in the cover image
    int bitIndex = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width * 3; j++) {
            // Get the current pixel value
            byte pixelValue = fgetc(coverImage);

            // Modify the least significant bit of the pixel value
            pixelValue &= 0xFE;
            pixelValue |= bitStream[bitIndex++];

            // Write the modified pixel value to the stego image
            fputc(pixelValue, stegoImage);
        }
    }

    // Close the files
    fclose(coverImage);
    fclose(stegoImage);
    fclose(secretMessage);

    printf("Steganography complete!\n");
    return 0;
}