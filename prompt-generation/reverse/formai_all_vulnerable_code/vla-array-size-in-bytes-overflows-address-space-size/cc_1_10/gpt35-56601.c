//FormAI DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
unsigned char image[100][100][3]; // Our Image
int width, height; // Dimensions of the image

// Function Prototypes
void readImageFromDisk(char *);
void writeImageToDisk(char *);
void encodeMessageToImage(char *);
void decodeMessageFromImage();

// Main function
int main(int argc, char **argv) {
    char message[100] = "This is a secret message!"; // Message to be encoded
    char imageFilename[100] = "image.bmp"; // Image filename
    readImageFromDisk(imageFilename); // Read image from disk
    encodeMessageToImage(message); // Encode message into image
    writeImageToDisk("encoded_image.bmp"); // Write image with message to disk
    decodeMessageFromImage(); // Decode and print message from the image
    return 0; // Exit program
}

// Function to read image from disk
void readImageFromDisk(char *filename) {
    FILE *file = fopen(filename, "rb"); // Open file in binary read mode
    if (file == NULL) {
        printf("Error: Unable to open image file!");
        exit(1);
    }
    unsigned char bmpHeader[54]; // BMP Header is 54 bytes long
    fread(bmpHeader, sizeof(unsigned char), 54, file); // Read BMP Header
    width = *(int *)&bmpHeader[18]; // Read width from BMP Header
    height = *(int *)&bmpHeader[22]; // Read height from BMP Header
    int padding = 0; // BMP Image Row Data is padded by multiples of 4
    while ((width * 3 + padding) % 4 != 0) padding++;
    unsigned char bmpImageData[height][width][3]; // BMP Image Data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(bmpImageData[i][j], sizeof(unsigned char), 3, file); // Read BMP Image Data
            image[i][j][0] = bmpImageData[i][j][2]; // BMP uses BGR, we need RGB
            image[i][j][1] = bmpImageData[i][j][1];
            image[i][j][2] = bmpImageData[i][j][0];
        }
        fseek(file, padding, SEEK_CUR); // Skip padded bytes
    }
    fclose(file); // Close file
}

// Function to write image to disk
void writeImageToDisk(char *filename) {
    FILE *file = fopen(filename, "wb"); // Open file in binary write mode
    if (file == NULL) {
        printf("Error: Unable to open output image file!");
        exit(1);
    }
    unsigned char bmpHeader[54] = {
        0x42, 0x4D, 0x36, 0x57, 0x60, 0x09, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x64, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x10, 0x57, 0x60, 0x09, 0x13, 0x0B,
        0x00, 0x00, 0x13, 0x0B, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }; // BMP Header
    *(int *)&bmpHeader[18] = width; // Write width to BMP Header
    *(int *)&bmpHeader[22] = height; // Write height to BMP Header
    int padding = 0; // BMP Image Row Data is padded by multiples of 4
    while ((width * 3 + padding) % 4 != 0) padding++;
    unsigned char bmpImageData[height][width][3]; // BMP Image Data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            bmpImageData[i][j][0] = image[i][j][2]; // BMP uses BGR, we need RGB
            bmpImageData[i][j][1] = image[i][j][1];
            bmpImageData[i][j][2] = image[i][j][0];
        }
        fwrite(bmpImageData[i], sizeof(unsigned char), width * 3 + padding, file); // Write BMP Image Data
        unsigned char paddingByte = 0x00;
        for (int k = 0; k < padding; k++) {
            fwrite(&paddingByte, sizeof(unsigned char), 1, file); // Write padded bytes
        }
    }
    fclose(file); // Close file
}

// Function to encode message into image
void encodeMessageToImage(char *message) {
    int messageLen = strlen(message); // Calculate message length
    int messageIndex = 0; // Index of current message character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (messageIndex < messageLen) {
                for (int k = 0; k < 3; k++) {
                    unsigned char pixelValue = image[i][j][k];
                    unsigned char messageChar = message[messageIndex++];
                    pixelValue &= 0xFC; // Replace last 2 bits with 0
                    pixelValue |= (messageChar >> 6); // Shift message character 6 bits to the right, then copy first 2 bits
                    image[i][j][k] = pixelValue;
                    if (messageIndex < messageLen) {
                        pixelValue = image[i][j][k];
                        messageChar = message[messageIndex++];
                        pixelValue &= 0xFC; // Replace last 2 bits with 0
                        pixelValue |= ((messageChar >> 4) & 0x03); // Shift message character 4 bits to the right, then copy first 2 bits
                        image[i][j][k] = pixelValue;
                        if (messageIndex < messageLen) {
                            pixelValue = image[i][j][k];
                            messageChar = message[messageIndex++];
                            pixelValue &= 0xFC; // Replace last 2 bits with 0
                            pixelValue |= ((messageChar >> 2) & 0x03); // Shift message character 2 bits to the right, then copy first 2 bits
                            image[i][j][k] = pixelValue;
                            if (messageIndex < messageLen) {
                                pixelValue = image[i][j][k];
                                messageChar = message[messageIndex++];
                                pixelValue &= 0xFC; // Replace last 2 bits with 0
                                pixelValue |= (messageChar & 0x03); // Copy first 2 bits to the last 2 bits
                                image[i][j][k] = pixelValue;
                            }
                        }
                    }
                }
            }
        }
    }
}

// Function to decode and print message from image
void decodeMessageFromImage() {
    char message[100] = ""; // Decoded message
    int messageLen = 0; // Decoded message length
    int messageIndex = 0; // Index of current decoded message character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (messageIndex < 100) { // Maximum message length is 100 characters
                for (int k = 0; k < 3; k++) {
                    unsigned char pixelValue = image[i][j][k];
                    unsigned char messageChar = 0x00;
                    messageChar |= ((pixelValue << 6) & 0xC0); // Copy first 2 bits to the first 2 bits of message character
                    if (++messageIndex <= messageLen) {
                        message[messageLen++] = messageChar; // Append message character to decoded message
                    }
                    if (messageIndex < 100 && messageIndex <= messageLen) {
                        pixelValue = image[i][j][k];
                        messageChar = 0x00;
                        messageChar |= ((pixelValue << 4) & 0xC0); // Copy first 2 bits to the first 2 bits of message character
                        if (++messageIndex <= messageLen) {
                            message[messageLen++] = messageChar; // Append message character to decoded message
                        }
                        if (messageIndex < 100 && messageIndex <= messageLen) {
                            pixelValue = image[i][j][k];
                            messageChar = 0x00;
                            messageChar |= ((pixelValue << 2) & 0xC0); // Copy first 2 bits to the first 2 bits of message character
                            if (++messageIndex <= messageLen) {
                                message[messageLen++] = messageChar; // Append message character to decoded message
                            }
                            if (messageIndex < 100 && messageIndex <= messageLen) {
                                pixelValue = image[i][j][k];
                                messageChar = 0x00;
                                messageChar |= (pixelValue & 0x03); // Copy last 2 bits to the last 2 bits of message character
                                if (++messageIndex <= messageLen) {
                                    message[messageLen++] = messageChar; // Append message character to decoded message
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Decoded Message: %s\n", message); // Print decoded message
}