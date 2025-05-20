//FormAI DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void encode(char *imagePath, char *message, char *outputPath)
{
    FILE *fp = fopen(imagePath, "rb");
    FILE *out = fopen(outputPath, "wb");

    if (fp == NULL) {
        printf("Error: could not open image file %s!", imagePath);
        exit(1);
    }
    if (out == NULL) {
        printf("Error: could not create output file %s!", outputPath);
        exit(1);
    }

    // Read image header and write to output file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    fwrite(header, sizeof(unsigned char), 54, out);

    // Convert message to binary
    size_t len = strlen(message);
    size_t bitCount = len * 8;
    char *binary = malloc(bitCount + 1);
    for (size_t i = 0; i < len; i++) {
        for (int j = 7; j >= 0; j--) {
            binary[i*8+(7-j)] = ((message[i] >> j) & 1) + '0';
        }
    }
    binary[bitCount] = '\0';

    // Write watermark to image
    unsigned char pixel[3];
    int bitIndex = 0;
    int doneFlag = 0;
    while (!doneFlag) {
        if (fread(pixel, sizeof(unsigned char), 3, fp) != 3) {
            doneFlag = 1;
        }

        for (int i = 0; i < 3; i++) {
            if (bitIndex < bitCount) {
                // Replace least significant bit with message bit
                if (binary[bitIndex] == '0') {
                    pixel[i] = pixel[i] & ~1;
                } else {
                    pixel[i] = pixel[i] | 1;
                }
                bitIndex++;
            }
        }

        fwrite(pixel, sizeof(unsigned char), 3, out);
    }

    // Clean up
    free(binary);
    fclose(fp);
    fclose(out);

    printf("Message encoded successfully!");
}

void decode(char *imagePath, char *outputPath)
{
    FILE *fp = fopen(imagePath, "rb");
    FILE *out = fopen(outputPath, "wb");

    if (fp == NULL) {
        printf("Error: could not open image file %s!", imagePath);
        exit(1);
    }
    if (out == NULL) {
        printf("Error: could not create output file %s!", outputPath);
        exit(1);
    }

    // Skip image header
    fseek(fp, 54, SEEK_SET);

    // Read watermark from image
    unsigned char pixel[3];
    char message[1024];
    int bitIndex = 0;
    int messageIndex = 0;
    int doneFlag = 0;
    while (!doneFlag) {
        if (fread(pixel, sizeof(unsigned char), 3, fp) != 3) {
            doneFlag = 1;
        }

        for (int i = 0; i < 3; i++) {
            if (bitIndex % 8 == 0) {
                message[messageIndex] = 0;
            }

            // Extract least significant bit
            message[messageIndex] |= ((pixel[i] & 1) << (7 - bitIndex % 8));
            bitIndex++;

            if (bitIndex % 8 == 0) {
                messageIndex++;
            }
        }
    }

    // Write decoded message to output file
    size_t len = strlen(message);
    size_t charCount = ceil(len/8.0);
    for (size_t i = 0; i < charCount; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            int bitIndex = i*8+j;
            if (bitIndex < len) {
                c |= ((message[bitIndex] & 1) << (7 - j));
            }
        }
        fwrite(&c, sizeof(unsigned char), 1, out);
    }

    fclose(fp);
    fclose(out);

    printf("Message decoded successfully!");
}

int main()
{
    // Encode message into image
    encode("image.bmp", "This is a secret message!", "output.bmp");

    // Decode message from image
    decode("output.bmp", "message.txt");

    return 0;
}