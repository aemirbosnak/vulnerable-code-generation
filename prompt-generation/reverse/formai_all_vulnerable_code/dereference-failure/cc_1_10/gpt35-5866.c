//FormAI DATASET v1.0 Category: Image compression ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables
int width, height;

// Function declarations
void compress(char* filename);
void decompress(char* filename);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [compress/decompress] [filename]\n", argv[0]);
        return 0;
    }
    // Check if first argument is compress or decompress
    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2]);
    } else {
        printf("Invalid option. Usage: %s [compress/decompress] [filename]\n", argv[0]);
        return 0;
    }
    return 0;
}

void compress(char* filename) {
    printf("Compressing %s...\n", filename);
    FILE* input = fopen(filename, "rb");
    if (input == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    // Read width and height from file
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);
    // Allocate memory for image data
    unsigned char** data = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        data[i] = (unsigned char*)malloc(width * sizeof(unsigned char));
    }
    // Read image data from file
    for (int i = 0; i < height; i++) {
        fread(data[i], sizeof(unsigned char), width, input);
    }
    fclose(input);
    // Compress image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] /= 2; // Divide by 2 to compress
        }
    }
    // Write compressed data to file
    char output_filename[100];
    sprintf(output_filename, "%s_compressed", filename);
    FILE* output = fopen(output_filename, "wb");
    fwrite(&width, sizeof(int), 1, output);
    fwrite(&height, sizeof(int), 1, output);
    for (int i = 0; i < height; i++) {
        fwrite(data[i], sizeof(unsigned char), width, output);
    }
    fclose(output);
    printf("Compression complete. Output written to %s.\n", output_filename);
    // Free memory
    for (int i = 0; i < height; i++) {
        free(data[i]);
    }
    free(data);
}

void decompress(char* filename) {
    printf("Decompressing %s...\n", filename);
    FILE* input = fopen(filename, "rb");
    if (input == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    // Read width and height from file
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);
    // Allocate memory for image data
    unsigned char** data = (unsigned char**)malloc(height * sizeof(unsigned char*));
    for (int i = 0; i < height; i++) {
        data[i] = (unsigned char*)malloc(width * sizeof(unsigned char));
    }
    // Read image data from file
    for (int i = 0; i < height; i++) {
        fread(data[i], sizeof(unsigned char), width, input);
    }
    fclose(input);
    // Decompress image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] *= 2; // Multiply by 2 to decompress
        }
    }
    // Write decompressed data to file
    char output_filename[100];
    sprintf(output_filename, "%s_decompressed", filename);
    FILE* output = fopen(output_filename, "wb");
    fwrite(&width, sizeof(int), 1, output);
    fwrite(&height, sizeof(int), 1, output);
    for (int i = 0; i < height; i++) {
        fwrite(data[i], sizeof(unsigned char), width, output);
    }
    fclose(output);
    printf("Decompression complete. Output written to %s.\n", output_filename);
    // Free memory
    for (int i = 0; i < height; i++) {
        free(data[i]);
    }
    free(data);
}