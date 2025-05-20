//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void encode(char* msg, char* imgFileName, char* outFileName);
char* decode(char* imgFileName);

int main() {
    char* msg = "This is a secret message to be hidden in the image.";
    char* imgFileName = "image.bmp";
    char* outFileName = "output.bmp";
    encode(msg, imgFileName, outFileName);
    char* decodedMsg = decode(outFileName);
    printf("Decoded Message: %s\n", decodedMsg);
    free(decodedMsg);
    return 0;
}

void encode(char* msg, char* imgFileName, char* outFileName) {
    FILE* imgFile = fopen(imgFileName, "rb");
    if (imgFile == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }
    FILE* outFile = fopen(outFileName, "wb");
    if (outFile == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }
    // Copy header from imgFile to outFile
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, imgFile);
    fwrite(header, sizeof(uint8_t), 54, outFile);
    // Get image dimensions from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    // Calculate maximum message length
    int maxMsgLength = (width * height * 3) / 8;
    if (strlen(msg) > maxMsgLength) {
        printf("Message is too long to be encoded in selected image.\n");
        exit(1);
    }
    // Copy pixels from imgFile to outFile, encoding message along the way
    uint8_t pixel[3];
    int msgIndex = 0;
    int bitIndex = 0;
    while (fread(pixel, sizeof(uint8_t), 3, imgFile) == 3) {
        uint8_t mask = 1 << bitIndex;
        if (msg[msgIndex] & mask) {
            pixel[2] |= 1;
        } else {
            pixel[2] &= ~1;
        }
        bitIndex++;
        if (bitIndex == 8) {
            bitIndex = 0;
            msgIndex++;
        }
        fwrite(pixel, sizeof(uint8_t), 3, outFile);
        if (msgIndex == strlen(msg)) {
            break;
        }
    }
    // Copy remaining pixels from imgFile to outFile
    while (fread(pixel, sizeof(uint8_t), 3, imgFile) == 3) {
        fwrite(pixel, sizeof(uint8_t), 3, outFile);
    }
    // Close files
    fclose(imgFile);
    fclose(outFile);
}

char* decode(char* imgFileName) {
    FILE* imgFile = fopen(imgFileName, "rb");
    if (imgFile == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }
    // Skip header
    fseek(imgFile, 54, SEEK_SET);
    // Get image dimensions from header
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, imgFile);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    // Allocate memory for decoded message
    char* msg = (char*)malloc((width * height * 3) / 8 + 1);
    if (msg == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    // Decode message
    uint8_t pixel[3];
    int msgIndex = 0;
    int bitIndex = 0;
    while (fread(pixel, sizeof(uint8_t), 3, imgFile) == 3) {
        uint8_t mask = 1 << bitIndex;
        if (pixel[2] & 1) {
            msg[msgIndex] |= mask;
        } else {
            msg[msgIndex] &= ~mask;
        }
        bitIndex++;
        if (bitIndex == 8) {
            bitIndex = 0;
            msgIndex++;
        }
    }
    // Add null terminator to message
    msg[msgIndex] = '\0';
    // Close file
    fclose(imgFile);
    return msg;
}