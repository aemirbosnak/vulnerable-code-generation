//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define BLOCK_SIZE 4096

// Function to calculate the frequency of each character in the input data
void calculateFrequency(const char *input, int *frequency) {
    for (int i = 0; input[i] != '\0'; i++) {
        frequency[(unsigned char)input[i]]++;
    }
}

// Function to compress data using a simple Run-Length Encoding technique
void compressData(const char *input, char *output) {
    int count;
    int i = 0, j = 0;
    while (input[i]) {
        count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[j++] = input[i];
        output[j++] = count + '0';  // Convert to character
        i++;
    }
    output[j] = '\0';  // Null-terminate the output string
}

// Function to decompress data compressed using Run-Length Encoding
void decompressData(const char *input, char *output) {
    int i = 0, j = 0;
    while (input[i]) {
        char currentChar = input[i++];
        int count = input[i++] - '0';  // Convert to integer
        for (int k = 0; k < count; k++) {
            output[j++] = currentChar;
        }
    }
    output[j] = '\0';  // Null-terminate the output string
}

// Function to read input from a file
char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }
    
    char *buffer = (char *)malloc(BLOCK_SIZE);
    size_t bytesRead = fread(buffer, sizeof(char), BLOCK_SIZE - 1, file);
    buffer[bytesRead] = '\0';  // Null-terminate the string
    fclose(file);
    return buffer;
}

// Function to write the compressed output to a file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }
    
    fprintf(file, "%s", data);
    fclose(file);
}

// Main function to drive the program
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *inputData = readFile(argv[1]);
    if (inputData == NULL) {
        return EXIT_FAILURE;
    }
    
    // Initialize frequency array
    int frequency[MAX_CHAR] = {0};
    calculateFrequency(inputData, frequency);

    // Preparing arrays for compression
    char compressedData[BLOCK_SIZE] = {0};
    compressData(inputData, compressedData);

    // Display original and compressed data lengths
    printf("Original data length: %lu\n", strlen(inputData));
    printf("Compressed data length: %lu\n", strlen(compressedData));

    writeFile(argv[2], compressedData);
    printf("Compressed data written to %s\n", argv[2]);

    // Now, let's decompress just to verify it works
    char decompressedData[BLOCK_SIZE] = {0};
    decompressData(compressedData, decompressedData);
    
    // Compare original and decompressed data
    if (strcmp(inputData, decompressedData) == 0) {
        printf("Decompression successful, data matches original.\n");
    } else {
        printf("Decompression failed, data does not match original.\n");
    }

    // Clean up allocated memory
    free(inputData);
    return EXIT_SUCCESS;
}