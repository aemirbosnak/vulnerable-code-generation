//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
// Peaceful Digital Watermarking - A Serene Harmony of Data and Art

#include <stdio.h>
#include <stdlib.h>

// Embeds a secret message into an image
void embedWaterMark(char *image, int imageSize, char *message, int msgSize) {
    for (int i = 0; i < msgSize; i++) {
        // Convert message character to binary code
        int charCode = message[i];
        for (int bit = 7; bit >= 0; bit--) {
            // Extract the bit value
            int bitValue = (charCode >> bit) & 1;
            // Embed the bit in the image's least significant bit
            image[i % imageSize] &= 0xFE;
            image[i % imageSize] |= bitValue;
        }
    }
}

// Extracts the secret message from the image
char *extractWaterMark(char *image, int imageSize) {
    // Initialize the extracted message
    char *message = malloc(imageSize / 8 + 1);
    for (int i = 0; i < imageSize / 8 + 1; i++) {
        message[i] = 0;
    }

    // Extract the message bit by bit
    for (int i = 0; i < imageSize / 8; i++) {
        for (int bit = 0; bit < 8; bit++) {
            // Extract the bit value from the image's least significant bit
            int bitValue = image[i * 8 + bit] & 1;
            // Shift the message character to accommodate the new bit
            message[i] <<= 1;
            // Add the extracted bit to the message character
            message[i] |= bitValue;
        }
    }

    return message;
}

int main() {
    // Embellish the image with a serene message
    char image[] = "Tranquil.ppm";
    char message[] = "May this symphony of pixels bring solace to your soul";

    // Perform the sacred act of embedding
    embedWaterMark(image, sizeof(image), message, sizeof(message));

    // Reveal the hidden harmony
    char *extracted = extractWaterMark(image, sizeof(image));

    // Share the unveiled message with the world
    printf("The whispered message hidden within the image:\n%s\n", extracted);

    // Cast away memories of this tranquil deed
    free(extracted);

    // As the sun sets on this digital canvas, may its secrets remain forever concealed
    return 0;
}