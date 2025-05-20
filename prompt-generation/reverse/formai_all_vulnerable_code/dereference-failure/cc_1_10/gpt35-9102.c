//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54  // BMP header size is 54 bytes

// Function to read bitmap data from file
unsigned char *readBitmapData(char *filename, int *width, int *height) {
    FILE *f;
    int fileSize, dataOffset;
    unsigned char *data;

    // Open the file in binary read mode
    f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file size from header
    fseek(f, 2, SEEK_SET);
    fread(&fileSize, sizeof(int), 1, f);

    // Read data offset from header
    fseek(f, 10, SEEK_SET);
    fread(&dataOffset, sizeof(int), 1, f);

    // Read width and height from header
    fseek(f, 18, SEEK_SET);
    fread(width, sizeof(int), 1, f);
    fread(height, sizeof(int), 1, f);

    // Allocate memory for bitmap data
    data = (unsigned char *) malloc(fileSize - dataOffset);

    // Read bitmap data from file
    fseek(f, dataOffset, SEEK_SET);
    fread(data, fileSize - dataOffset, 1, f);

    fclose(f);

    return data;
}

// Function to write bitmap data to file
void writeBitmapData(char *filename, unsigned char *data, int width, int height) {
    FILE *f;
    int fileSize, dataOffset, imageSize;

    // Calculate image size
    imageSize = width * height * 3;

    // Calculate file size
    fileSize = imageSize + HEADER_SIZE;

    // Calculate data offset
    dataOffset = HEADER_SIZE;

    // Open the file in binary write mode
    f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write BMP header
    fwrite("BM", 1, 2, f);
    fwrite(&fileSize, sizeof(int), 1, f);
    fwrite("\0\0\0\0", 1, 4, f);
    fwrite(&dataOffset, sizeof(int), 1, f);
    fwrite("\x28\0\0\0", 1, 4, f);
    fwrite(&width, sizeof(int), 1, f);
    fwrite(&height, sizeof(int), 1, f);
    fwrite("\x01\0\x18\0", 1, 4, f);
    fwrite("\0\0\0\0", 1, 4, f);
    fwrite(&imageSize, sizeof(int), 1, f);
    fwrite("\x12\x0b\0\0", 1, 4, f);
    fwrite("\x12\x0b\0\0", 1, 4, f);
    fwrite("\0\0\0\0", 1, 4, f);
    fwrite("\0\0\0\0", 1, 4, f);

    // Write bitmap data to file
    fwrite(data, imageSize, 1, f);

    fclose(f);
}

// Function to embed a message into an image using LSB steganography
void embedMessage(unsigned char *imageData, int imageSize, char *message) {
    int i, j, messageLength, bitIndex;
    char bit;

    // Length of message + terminating null character
    messageLength = strlen(message) + 1;

    // Embed message length into the first 4 bytes of image data
    for (i = 0; i < 4; i++) {
        imageData[i] = (unsigned char) (messageLength >> (i * 8));
    }

    // Embed each bit of the message into LSB of each byte of image data
    bitIndex = 0;
    for (i = 4; i < imageSize; i++) {
        bit = message[bitIndex / 8] & (1 << (bitIndex % 8));
        if (bit == 0) {
            imageData[i] &= ~(1 << 0);
        } else {
            imageData[i] |= 1 << 0;
        }
        bitIndex++;
        if (bitIndex >= messageLength * 8) {
            break;
        }
    }
}

// Function to extract a message from an image using LSB steganography
char *extractMessage(unsigned char *imageData, int imageSize) {
    int i, j, messageLength, bitIndex;
    char bit, *message;

    // Extract message length from the first 4 bytes of image data
    messageLength = 0;
    for (i = 0; i < 4; i++) {
        messageLength |= imageData[i] << (i * 8);
    }

    // Allocate memory to store message
    message = (char *) malloc(messageLength);

    // Extract each bit of the message from LSB of each byte of image data
    bitIndex = 0;
    for (i = 4; i < imageSize; i++) {
        bit = imageData[i] & (1 << 0);
        if (bit == 0) {
            message[bitIndex / 8] &= ~(1 << (bitIndex % 8));
        } else {
            message[bitIndex / 8] |= 1 << (bitIndex % 8);
        }
        bitIndex++;
        if (bitIndex >= messageLength * 8) {
            break;
        }
    }

    return message;
}

int main() {
    unsigned char *imageData, *newImageData;
    char *message, *extractedMessage;
    int imageWidth, imageHeight, imageSize, i;

    // Read original bitmap data from file
    imageData = readBitmapData("image.bmp", &imageWidth, &imageHeight);

    // Calculate image size
    imageSize = imageWidth * imageHeight * 3;

    // Allocate memory for modified bitmap data
    newImageData = (unsigned char *) malloc(imageSize);

    // Copy original bitmap data to modified bitmap data
    memcpy(newImageData, imageData, imageSize);

    // Embed message into image using LSB steganography
    message = "Hello, world!";
    embedMessage(newImageData, imageSize, message);

    // Write modified bitmap data to file
    writeBitmapData("new_image.bmp", newImageData, imageWidth, imageHeight);

    // Extract message from image using LSB steganography
    extractedMessage = extractMessage(newImageData, imageSize);

    printf("Extracted message: %s\n", extractedMessage);

    free(imageData);
    free(newImageData);
    free(extractedMessage);

    return 0;
}