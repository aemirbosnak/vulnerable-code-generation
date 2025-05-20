//FormAI DATASET v1.0 Category: Image compression ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8

// Function to compress a 24bit color pixel to 8bits
unsigned char compressPixel(unsigned char r, unsigned char g, unsigned char b) {
    return (((r >> 5) << 5) | ((g >> 5) << 2) | (b >> 6));
}

// Function to decompress an 8bit color pixel to 24bits
void decompressPixel(unsigned char compressed, unsigned char *r, unsigned char *g, unsigned char *b) {
    *r = (compressed & 0xE0) | (*r >> 3);
    *g = ((compressed & 0x1C) << 3) | (*g >> 3);
    *b = ((compressed & 0x03) << 6) | (*b >> 2);
}

// Function to compress an image in PPM format
void compressImage(char *inFile, char *outFile) {
    FILE *in = fopen(inFile, "rb");
    if (in == NULL) {
        printf("Error opening input file!\n");
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(outFile, "wb");
    if (out == NULL) {
        printf("Error creating output file!\n");
        exit(EXIT_FAILURE);
    }

    // Read and write the header
    char buffer[1024];
    fgets(buffer, 1024, in);
    fprintf(out, "%s", buffer);
    fgets(buffer, 1024, in);
    fprintf(out, "%s", buffer);
    fgets(buffer, 1024, in);
    fprintf(out, "%s", buffer);

    // Allocate memory for a block of pixels
    unsigned char **block = malloc(BLOCK_SIZE * sizeof(unsigned char *));
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = malloc(3 * sizeof(unsigned char));
    }

    while (!feof(in)) {
        // Read a block of pixels
        for (int i = 0; i < BLOCK_SIZE; i++) {
            for (int j = 0; j < 3; j++) {
                block[i][j] = fgetc(in);
            }
        }

        // Compress the block of pixels
        for (int i = 0; i < BLOCK_SIZE; i++) {
            unsigned char compressed = compressPixel(block[i][0], block[i][1], block[i][2]);
            fputc(compressed, out);
        }
    }

    // Free memory for the block of pixels
    for (int i = 0; i < BLOCK_SIZE; i++) {
        free(block[i]);
    }
    free(block);

    // Close input and output files
    fclose(in);
    fclose(out);
}

// Function to decompress an image in PPM format
void decompressImage(char *inFile, char *outFile) {
    FILE *in = fopen(inFile, "rb");
    if (in == NULL) {
        printf("Error opening input file!\n");
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(outFile, "wb");
    if (out == NULL) {
        printf("Error creating output file!\n");
        exit(EXIT_FAILURE);
    }

    // Read and write the header
    char buffer[1024];
    fgets(buffer, 1024, in);
    fprintf(out, "%s", buffer);
    fgets(buffer, 1024, in);
    fprintf(out, "%s", buffer);
    fgets(buffer, 1024, in);
    fprintf(out, "%s", buffer);

    // Allocate memory for a block of pixels
    unsigned char **block = malloc(BLOCK_SIZE * sizeof(unsigned char *));
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = malloc(3 * sizeof(unsigned char));
    }

    while (!feof(in)) {
        // Read a block of compressed pixels
        for (int i = 0; i < BLOCK_SIZE; i++) {
            unsigned char compressed = fgetc(in);
            decompressPixel(compressed, &block[i][0], &block[i][1], &block[i][2]);
        }

        // Write the block of uncompressed pixels
        for (int i = 0; i < BLOCK_SIZE; i++) {
            for (int j = 0; j < 3; j++) {
                fputc(block[i][j], out);
            }
        }
    }

    // Free memory for the block of pixels
    for (int i = 0; i < BLOCK_SIZE; i++) {
        free(block[i]);
    }
    free(block);

    // Close input and output files
    fclose(in);
    fclose(out);
}

int main() {
    compressImage("image.ppm", "compressed.ppm");
    decompressImage("compressed.ppm", "decompressed.ppm");
    return 0;
}