//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define HEADER_SIZE 54
#define MAX_FILE_SIZE 10000000

// Function to hide the data in the image
void hideData(FILE *image, FILE *data, char *output) {
    // Read image header
    unsigned char header[HEADER_SIZE];
    fread(&header, sizeof(unsigned char), HEADER_SIZE, image);

    // Read data
    fseek(data, 0, SEEK_END);
    long data_size = ftell(data);
    rewind(data);
    char *buffer = (char*)malloc(sizeof(char) * data_size);
    fread(buffer, sizeof(char), data_size, data);

    // Check if data fits in the image without increasing file size
    long image_size = 0;
    fseek(image, 0, SEEK_END);
    image_size = ftell(image);
    rewind(image);
    if (image_size - HEADER_SIZE < data_size * 8) {
        printf("Image file too small.\n");
        return;
    }

    // Create output file
    FILE *output_file = fopen(output, "wb");
    fwrite(&header, sizeof(unsigned char), HEADER_SIZE, output_file);

    // Hide the data in the image
    int index = 0;
    unsigned char pixel;
    while(fread(&pixel, sizeof(unsigned char), 1, image) == 1 && index < data_size * 8) {
        for (int bit = 0; bit < 8; bit++) {
            if (index < data_size * 8) {
                pixel = (pixel & 0xFE) | ((buffer[index / 8] >> (7 - index % 8)) & 0x01);
                index++;
            }
            fwrite(&pixel, sizeof(unsigned char), 1, output_file);
            fread(&pixel, sizeof(unsigned char), 1, image);
        }
        fwrite(&pixel, sizeof(unsigned char), 1, output_file);
    }
    // Write remaining pixels to the output file
    while(fread(&pixel, sizeof(unsigned char), 1, image) == 1) {
        fwrite(&pixel, sizeof(unsigned char), 1, output_file);
    }

    // Close files and free memory
    fclose(image);
    fclose(data);
    fclose(output_file);
    free(buffer);
}

// Function to extract hidden data from the image
void extractData(FILE *image, char *output) {
    // Read image header
    unsigned char header[HEADER_SIZE];
    fread(&header, sizeof(unsigned char), HEADER_SIZE, image);

    // Create output file
    FILE *output_file = fopen(output, "wb");

    // Extract hidden data from the image
    unsigned char pixel;
    char buffer = 0;
    int index = 0;
    while(fread(&pixel, sizeof(unsigned char), 1, image) == 1) {
        // Extract the bit from the pixel and store in the buffer
        buffer = (buffer << 1) | (pixel & 0x01);
        index++;
        // If the buffer is full, write to the output file
        if (index % 8 == 0) {
            fwrite(&buffer, sizeof(char), 1, output_file);
            buffer = 0;
        }
    }

    // Close files
    fclose(image);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <mode> <input_file> <output_file> <data_file>\n", argv[0]);
        printf("Example (hide data): %s -h image.bmp secret.bmp secret.txt\n", argv[0]);
        printf("Example (extract data): %s -e secret.bmp secret.txt\n", argv[0]);
        return 0;
    }

    // Open input file
    FILE *input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0) {
        // Open data file
        FILE *data_file = fopen(argv[4], "rb");
        if (data_file == NULL) {
            printf("Error opening data file.\n");
            return 0;
        }
        // Hide data in the image
        hideData(input_file, data_file, argv[3]);
    }
    else if (strcmp(argv[1], "-e") == 0) {
        // Extract data from the image
        extractData(input_file, argv[3]);
    }
    else {
        printf("Invalid mode.\n");
    }

    return 0;
}