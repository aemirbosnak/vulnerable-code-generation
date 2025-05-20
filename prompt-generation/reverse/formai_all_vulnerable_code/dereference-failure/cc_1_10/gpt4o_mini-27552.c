//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function to perform Run-Length Encoding (RLE) Compression
void RLECompress(char *input, char *output) {
    int count;
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        sprintf(output + strlen(output), "%d%c", count, input[i]);
    }
}

// Function to perform Run-Length Encoding (RLE) Decompression
void RLEDecompress(char *input, char *output) {
    int count;
    char character;

    for (int i = 0; i < strlen(input); i++) {
        if (sscanf(input + i, "%d%c", &count, &character) == 2) {
            for (int j = 0; j < count; j++) {
                output[strlen(output)] = character;
            }
            output[strlen(output)] = '\0'; // Null-terminate the output string
            while (input[i] && input[i] >= '0' && input[i] <= '9') i++; // move to character
            i++; // move past the character
        }
    }
}

// Function to read a file
char *readFile(char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    char *buffer = (char *)malloc(MAX_LEN);
    fread(buffer, MAX_LEN, 1, file);
    fclose(file);
    
    return buffer;
}

// Function to write generated data to a file
void writeFile(char *filePath, char *data) {
    FILE *file = fopen(filePath, "w");
    if (!file) {
        perror("Unable to create file!");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", data);
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has supplied the appropriate parameters
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <compressed_file> <decompressed_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read the input file
    char *input = readFile(argv[1]);
    printf("Original Data:\n%s\n", input);

    // Prepare buffers for compression and decompression
    char *compressed = (char *)calloc(MAX_LEN, sizeof(char));
    char *decompressed = (char *)calloc(MAX_LEN, sizeof(char));

    // Perform compression
    RLECompress(input, compressed);
    printf("Compressed Data:\n%s\n", compressed);

    // Write compressed data to file
    writeFile(argv[2], compressed);

    // Perform decompression
    RLEDecompress(compressed, decompressed);
    printf("Decompressed Data:\n%s\n", decompressed);

    // Write decompressed data to file
    writeFile(argv[3], decompressed);

    // Free allocated memory
    free(input);
    free(compressed);
    free(decompressed);

    return 0;
}