//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This C program implements a paranoid-style digital watermarking technique that adds an invisible watermark to 
an image file. The watermark is designed to be robust to common image processing operations but can still
be detected using a specific algorithm. 
*/

#define BPP 3 // Bytes per pixel, assuming RGB image
#define WATERMARK_LENGTH 50 // Maximum length of the watermark

// Function to convert a string to binary
char * strToBin(char *str) {
    int i, j, len;
    char *binString = malloc((strlen(str) * 8) + 1); // 8 bits per character

    for (i = 0, j = 0, len = strlen(str); i < len; i++, j+=8) {
        int val = (int) str[i];
        for (int k = 7; k >= 0; k--) {
            binString[j+k] = (val & 1) ? '1' : '0';
            val >>= 1;
        }
    }
    binString[j] = '\0';
    return binString;
}

// Function to convert a binary string to a char array
char * binToStr(char *binStr) {
    int i, j, len;
    char *str = malloc((strlen(binStr) / 8) + 1);

    for (i = 0, j = 0, len = strlen(binStr); i < len; i+=8, j++) {
        int val = 0;
        for (int k = 0; k < 8; k++) {
            val <<= 1;
            if (binStr[i+k] == '1')
                val |= 1;
        }
        str[j] = (char) val;
    }
    str[j] = '\0';
    return str;
}

// Function to hide the watermark in the least significant bits of the image pixels
void hideWatermark(char *imageFilename, char *watermark) {
    FILE *imageFile = fopen(imageFilename, "rb+");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile); // Size of the image in bytes

    // Check if the image is large enough to hold the watermark
    if (imageSize < WATERMARK_LENGTH * 8 * BPP) {
        printf("Error: Image too small to hold watermark.\n");
        exit(1);
    }

    rewind(imageFile);

    char *watermarkBin = strToBin(watermark);
    unsigned char pixel[BPP];
    int bitPos = 0;

    while (fread(pixel, 1, BPP, imageFile) == BPP && bitPos < WATERMARK_LENGTH * 8) {
        for (int i = 0; i < BPP; i++) {
            if (bitPos < WATERMARK_LENGTH * 8) {
                pixel[i] = ((pixel[i] & 0xFE) | (watermarkBin[bitPos++] - 48));
            }
        }
        fwrite(pixel, 1, BPP, imageFile);
    }

    fclose(imageFile);
    free(watermarkBin);

    printf("Watermark hidden successfully!\n");
}

// Function to extract the watermark from the least significant bits of the image pixels
char * extractWatermark(char *imageFilename) {
    FILE *imageFile = fopen(imageFilename, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile); // Size of the image in bytes

    // Check if the image is large enough to hold the watermark
    if (imageSize < WATERMARK_LENGTH * 8 * BPP) {
        printf("Error: Image too small to hold watermark.\n");
        exit(1);
    }

    rewind(imageFile);

    char *watermarkBin = malloc((WATERMARK_LENGTH * 8) + 1);
    memset(watermarkBin, 0, (WATERMARK_LENGTH * 8) + 1);

    unsigned char pixel[BPP];
    int bitPos = 0;

    while (fread(pixel, 1, BPP, imageFile) == BPP && bitPos < WATERMARK_LENGTH * 8) {
        for (int i = 0; i < BPP; i++) {
            if (bitPos < WATERMARK_LENGTH * 8) {
                watermarkBin[bitPos++] = (pixel[i] & 1) ? '1' : '0';
            }
        }
    }

    fclose(imageFile);

    char *watermark = binToStr(watermarkBin);
    free(watermarkBin);

    if (strlen(watermark) == 0) {
        printf("Error: Watermark not found.\n");
        exit(1);
    }

    printf("Watermark extracted successfully!\n");
    return watermark;
}

// Function to calculate the watermark checksum to detect modifications to the watermark
int calculateChecksum(char *watermark) {
    int checksum = 0;
    for (int i = 0; i < strlen(watermark); i++) {
        checksum += (int) watermark[i];
    }
    return checksum;
}

int main() {
    char *filename = "image.bmp";
    char *watermark = "This image has been watermarked.";

    printf("Hiding watermark in image...\n");
    hideWatermark(filename, watermark);

    printf("Extracting watermark from image...\n");
    char *extractedMark = extractWatermark(filename);
    printf("Extracted watermark: %s\n", extractedMark);

    // Checking for modifications to the watermark
    int originalChecksum = calculateChecksum(watermark);
    int extractedChecksum = calculateChecksum(extractedMark);
    if (originalChecksum != extractedChecksum) {
        printf("Warning: Watermark has been modified or corrupted.\n");
    } else {
        printf("Watermark is intact.\n");
    }

    free(extractedMark);
    return 0;
}