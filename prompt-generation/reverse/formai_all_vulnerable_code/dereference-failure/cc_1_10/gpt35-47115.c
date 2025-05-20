//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned char red, green, blue;
} RGB;

// Function to get a single bit from a byte
unsigned char getBit(unsigned char byte, int bitIndex) {
    return (byte >> bitIndex) & 1;
}

// Function to set a single bit in a byte
unsigned char setBit(unsigned char byte, int bitIndex, unsigned char bitValue) {
    if (bitValue) {
        return byte | (1 << bitIndex);
    } else {
        return byte & ~(1 << bitIndex);
    }
}

// Function to encode a message into an image
void encodeMessage(char *message, RGB *pixels, int numPixels) {
    int messageLen = strlen(message);
    int pixelsUsed = 0;
    char c;

    for (int i = 0; i < messageLen; i++) {
        for (int j = 7; j >= 0; j--) {
            if (pixelsUsed >= numPixels) {
                printf("ERROR: Message too long for image.\n");
                exit(1);
            }

            c = message[i];
            unsigned char bit = getBit(c, j);
            pixels[pixelsUsed].red = setBit(pixels[pixelsUsed].red, 0, bit);
            pixelsUsed++;
        }
    }

    // Terminate message with null character
    for (int j = 7; j >= 0; j--) {
        if (pixelsUsed >= numPixels) {
            printf("ERROR: Message too long for image.\n");
            exit(1);
        }

        pixels[pixelsUsed].red = setBit(pixels[pixelsUsed].red, 0, 0);
        pixelsUsed++;
    }
}

// Function to decode a message from an image
char *decodeMessage(RGB *pixels, int numPixels) {
    char *message = malloc(numPixels / 8);
    int messageIndex = 0;
    char currentByte = 0;
    int bitIndex = 7;

    for (int i = 0; i < numPixels; i++) {
        if (messageIndex % 8 == 0 && messageIndex != 0) {
            if (currentByte == '\0') {
                return message;
            } else {
                message[messageIndex / 8 - 1] = currentByte;
                currentByte = 0;
                bitIndex = 7;
            }
        }

        unsigned char bit = getBit(pixels[i].red, 0);
        currentByte = setBit(currentByte, bitIndex, bit);
        bitIndex--;
        messageIndex++;
    }

    return message;
}

// Function to read in image from file
RGB *readImage(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("ERROR: File '%s' not found.\n", filename);
        exit(1);
    }

    fseek(file, 18, SEEK_SET); // Skip header information

    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);
    fseek(file, 28, SEEK_SET); // Re-position to pixel data

    int numPixels = *width * *height;
    RGB *pixels = malloc(numPixels * sizeof(RGB));
    fread(pixels, sizeof(RGB), numPixels, file);

    fclose(file);
    return pixels;
}

// Function to write out image to file
void writeImage(char *filename, RGB *pixels, int width, int height) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("ERROR: Could not write to file '%s'.\n", filename);
        exit(1);
    }

    // Write header information
    unsigned char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + width * height * 3; // Size of file
    *(int *)&header[10] = 54; // Pixel data offset
    *(int *)&header[14] = 40; // Size of bitmap info header
    *(int *)&header[18] = width;
    *(int *)&header[22] = height;
    *(short *)&header[26] = 1; // Number of color planes
    *(short *)&header[28] = 24; // Bits per pixel

    fwrite(header, sizeof(unsigned char), 54, file);

    // Write pixel data
    fwrite(pixels, sizeof(RGB), width * height, file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR: Image file not specified.\n");
        exit(1);
    }

    RGB *pixels = NULL;
    int width, height;

    pixels = readImage(argv[1], &width, &height);

    if (argc == 3) {
        // Decode message
        char *message = decodeMessage(pixels, width * height);
        printf("Message: %s\n", message);
    } else if (argc == 4) {
        // Encode message
        encodeMessage(argv[3], pixels, width * height);
        writeImage(argv[2], pixels, width, height);
    } else {
        printf("ERROR: Invalid number of arguments.\n");
        exit(1);
    }

    free(pixels);
    return 0;
}