//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54

unsigned char* read_bmp_image(const char* filename, int* width, int* height);
void write_bmp_image(const char* filename, unsigned char* image, int width, int height);

/**
 * Embeds a message in an image using LSB steganography
 * @param image The original image data
 * @param size The size of the image in bytes
 * @param message The message to be hidden in the image
 * @param messageSize The size of the message in bytes
 * @return 0 on success, -1 on failure
 */
int image_hide_message(unsigned char* image, int size, const char* message, int messageSize) {
    // Check if the message size is too big to fit in the image
    int maxMessageSize = (size - HEADER_SIZE) / 8;
    if (messageSize > maxMessageSize) {
        return -1;
    }

    // Copy the message size to the first 4 bytes of the image
    memcpy(image, &messageSize, 4);

    // Embed each bit of the message in the least significant bit of the image byte
    int imageIndex = HEADER_SIZE;
    for (int i = 0; i < messageSize; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (c >> j) & 1;
            image[imageIndex] = (image[imageIndex] & 0xFE) | bit;
            imageIndex++;
        }
    }

    return 0;
}

/**
 * Extracts a message from an image using LSB steganography
 * @param image The image data
 * @param size The size of the image in bytes
 * @param message The buffer to store the extracted message
 * @param maxSize The maximum size of the message buffer
 * @return The size of the extracted message in bytes, or -1 on failure
 */
int image_extract_message(unsigned char* image, int size, char* message, int maxSize) {
    int messageSize;
    memcpy(&messageSize, image, 4);

    if (messageSize > maxSize) {
        return -1;
    }

    int messageIndex = 0;
    int imageIndex = HEADER_SIZE;
    for (int i = 0; i < messageSize; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char bit = image[imageIndex] & 1;
            c |= (bit << j);
            imageIndex++;
        }
        message[messageIndex++] = c;
    }

    return messageSize;
}

int main() {
    int width, height;
    unsigned char* image = read_bmp_image("input.bmp", &width, &height);

    char message[] = "Hello, world!";
    int messageSize = strlen(message) + 1;

    int result = image_hide_message(image, width * height * 3, message, messageSize);
    if (result == -1) {
        printf("Error: message size too big\n");
        return 1;
    }

    char extractedMessage[256];
    int extractedSize = image_extract_message(image, width * height * 3, extractedMessage, 256);

    printf("Extracted message: %s\n", extractedMessage);

    write_bmp_image("output.bmp", image, width, height);

    free(image);

    return 0;
}

/**
 * Reads a BMP image from file and returns it as a byte array
 * @param filename The name of the image file
 * @param width A pointer to store the width of the image in pixels
 * @param height A pointer to store the height of the image in pixels
 * @return A byte array containing the image data, or NULL on failure
 */
unsigned char* read_bmp_image(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, 1, HEADER_SIZE, file);

    // Verify that the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(file);
        return NULL;
    }

    // Read the image metadata
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Read the image data
    int imageSize = *(int*)&header[34];
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, 1, imageSize, file);

    fclose(file);

    return imageData;
}

/**
 * Writes a BMP image to file
 * @param filename The name of the output file
 * @param image The image data to be written
 * @param width The width of the image in pixels
 * @param height The height of the image in pixels
 */
void write_bmp_image(const char* filename, unsigned char* image, int width, int height) {
    FILE* file = fopen(filename, "wb");

    // Write the image header
    unsigned char header[HEADER_SIZE] = {
        'B', 'M',       // magic
        0, 0, 0, 0,     // size of file (filled in later)
        0, 0,           // unused
        0, 0,           // unused
        HEADER_SIZE, 0, 0, 0, // offset to data
        40, 0, 0, 0,    // size of info header
        0, 0, 0, 0,     // width of image (filled in later)
        0, 0, 0, 0,     // height of image (filled in later)
        1, 0,           // number of color planes
        24, 0,          // bits per pixel
        0, 0, 0, 0,     // compression type
        0, 0, 0, 0,     // size of compressed data (can be zero for uncompressed)
        0, 0, 0, 0,     // x pixels per meter
        0, 0, 0, 0,     // y pixels per meter
        0, 0, 0, 0,     // number of colors in palette
        0, 0, 0, 0,     // number of important colors
    };

    *(int*)&header[2] = HEADER_SIZE + width * height * 3;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;

    fwrite(header, 1, HEADER_SIZE, file);

    // Write the image data
    fwrite(image, 1, width * height * 3, file);

    fclose(file);
}