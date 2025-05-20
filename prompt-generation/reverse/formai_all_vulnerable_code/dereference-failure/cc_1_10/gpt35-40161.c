//FormAI DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_FILENAME_LENGTH 100
#define MAX_SECRET_LENGTH 1000
#define BYTE_SIZE 8

// Prototypes
void printUsage();
long getFileSize(FILE *file);
bool hideDataInImage(FILE *image, char *secret, char *outputFilename);
char *retrieveDataFromImage(FILE *image);

int main(int argc, char *argv[]) {
	// Check for correct usage
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    // Read in arguments
    char *filename = argv[1];
    char *secret = argv[2];
    char *outputFilename = argv[3];

    // Open image file
    FILE *image = fopen(filename, "rb");
    if (!image) {
        printf("Error opening file: %s\n", filename);
        return EXIT_FAILURE;
    }

    // Check if secret message fits in image
    long imageSize = getFileSize(image);
    if (strlen(secret) * BYTE_SIZE > imageSize) {
        printf("Secret message too large for image!\n");
        return EXIT_FAILURE;
    }

    // Hide data in image
    if (!hideDataInImage(image, secret, outputFilename)) {
        printf("Error hiding data in image!\n");
        return EXIT_FAILURE;
    }

    printf("Data successfully hidden in image!\n");

    // Retrieve data from image for demonstration purposes
    char *retrievedData = retrieveDataFromImage(image);
    printf("Retrieved data: %s\n", retrievedData);

    // Clean up
    free(retrievedData);
    fclose(image);

    return EXIT_SUCCESS;
}

void printUsage() {
    printf("Usage: image_steg <image filename> <secret message> <output filename>\n");
}

long getFileSize(FILE *file) {
	// Save current position
    long currentPosition = ftell(file);

    // Seek to end
    fseek(file, 0L, SEEK_END);

    // Get file size
    long fileSize = ftell(file);

    // Return to previous position
    fseek(file, currentPosition, SEEK_SET);

    return fileSize;
}

bool hideDataInImage(FILE *image, char *secret, char *outputFilename) {
	// Open output file
    FILE *output = fopen(outputFilename, "wb");
    if (!output) {
        return false;
    }

    // Copy image header to output file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);
    fwrite(header, sizeof(unsigned char), 54, output);

    // Hide secret message in image data
    int i = 0;
    while (*secret != '\0') {
        for (int j = 0; j < BYTE_SIZE; j++) {
            // Read in next pixel value
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, image);

            // Set least significant bit to secret bit
            if (*secret & (1 << i)) {
                pixel |= 0x01;
            } else {
                pixel &= 0xFE;
            }

            // Write pixel value to output file
            fwrite(&pixel, sizeof(unsigned char), 1, output);

            i = (i + 1) % BYTE_SIZE;
        }

        secret++;
    }

    // Copy remaining image data to output file
    char data;
    while (fread(&data, sizeof(char), 1, image)) {
        fwrite(&data, sizeof(char), 1, output);
    }

    // Clean up
    fclose(output);

    return true;
}

char *retrieveDataFromImage(FILE *image) {
	// Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);

    // Allocate buffer for retrieved data
    char *retrievedData = (char *)malloc(MAX_SECRET_LENGTH);

    // Retrieve data from image
    int i = 0;
    int dataRead = 0;
    char byte = 0;
    while (dataRead < MAX_SECRET_LENGTH * BYTE_SIZE) {
        // Read in next pixel value
        unsigned char pixel;
        fread(&pixel, sizeof(unsigned char), 1, image);

        // Get least significant bit from pixel
        if (pixel & 0x01) {
            byte |= 0x01;
        }

        i++;
        dataRead++;

        // Check if byte is complete
        if (i == BYTE_SIZE) {
            retrievedData[dataRead / BYTE_SIZE - 1] = byte;
            byte = 0;
            i = 0;
        }
    }

    return retrievedData;
}