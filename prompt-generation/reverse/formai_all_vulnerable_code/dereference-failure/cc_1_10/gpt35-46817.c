//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
#include <stdio.h>

// Function to extract individual bits from a byte
int getBit(unsigned char byte, int index) {
    return (byte >> (7 - index)) & 1;
}

// Function to set individual bits of a byte
void setBit(unsigned char* byte, int index, int value) {
    if (value == 0) {
        *byte &= ~(1 << (7 - index));
    } else {
        *byte |= (1 << (7 - index));
    }
}

// Function to add a digital watermark to an image
void addWatermark(unsigned char* image, int width, int height, char* message) {
    // Calculate the length of the message in bits
    int messageLength = 0;
    char* current = message;
    while (*current != '\0') {
        messageLength += 8;
        current++;
    }

    // Initialize the seed value for random number generator
    srand(time(NULL));

    // Loop through each pixel of the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the current pixel from the image
            unsigned char* pixel = &image[(y * width + x) * 3];

            // Generate a random number between 0 and messageLength - 1
            int bitIndex = rand() % messageLength;

            // Get the corresponding bit from the message
            int bit = getBit(message[bitIndex / 8], bitIndex % 8);

            // Set the least significant bit of the blue channel
            setBit(&pixel[2], 0, bit);
        }
    }
}

// Function to extract a digital watermark from an image
void extractWatermark(unsigned char* image, int width, int height, char* message) {
    // Initialize the seed value for random number generator
    srand(time(NULL));

    // Loop through each pixel of the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Get the current pixel from the image
            unsigned char* pixel = &image[(y * width + x) * 3];

            // Generate a random number between 0 and 7
            int bitIndex = rand() % 8;

            // Get the least significant bit of the blue channel
            int bit = getBit(pixel[2], 0);

            // Set the corresponding bit of the message
            setBit(&message[bitIndex / 8], bitIndex % 8, bit);
        }
    }
}

int main() {
    // Load the image from file
    unsigned char image[9] = {
        255, 255, 255,   // White pixel
        0, 0, 0,         // Black pixel
        128, 128, 128    // Gray pixel
    };

    // Add a digital watermark to the image
    char message[] = "Hello, world!";
    addWatermark(image, 3, 3, message);

    // Extract the digital watermark from the image
    char extractedMessage[sizeof(message) / sizeof(message[0])];
    extractWatermark(image, 3, 3, extractedMessage);

    // Print the original message and the extracted message
    printf("Original message: %s\n", message);
    printf("Extracted message: %s\n", extractedMessage);

    return 0;
}