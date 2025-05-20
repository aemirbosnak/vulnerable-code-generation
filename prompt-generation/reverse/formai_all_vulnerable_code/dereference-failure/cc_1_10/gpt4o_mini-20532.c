//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define OUTPUT_SIZE (2 * BUFFER_SIZE) // max size after compression might be double in the worst case

// Function to perform Run-Length Encoding
void compressRLE(const char *input, FILE *output) {
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Write the character and its count to the output file
        fprintf(output, "%c%d", input[i], count);
    }
}

// Function to read input file and compress the content
void compressFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    // Read the entire file content into a buffer
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, inputFile) == NULL) {
        perror("Error reading input file");
        fclose(inputFile);
        return;
    }
    fclose(inputFile);

    // Open the output file for writing the compressed content
    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        perror("Error opening output file");
        return;
    }

    // Compress the buffer and write to output file
    compressRLE(buffer, outputFile);
    fclose(outputFile);

    printf("File successfully compressed to %s\n", outputFileName);
}

// Function to decompress the RLE compressed file
void decompressRLE(const char *input, FILE *output) {
    int length = strlen(input);
    
    for (int i = 0; i < length; i++) {
        char currentChar = input[i++];
        int count = 0;

        // Read the number next to the character
        while (i < length && input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        // Write the character 'count' times to the output file
        for (int j = 0; j < count; j++) {
            fputc(currentChar, output);
        }
        // Decrement i to compensate for the inner loop's increment
        i--;
    }
}

// Function to decompress the compressed file
void decompressFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    // Read the entire file content into a buffer
    char buffer[OUTPUT_SIZE];
    if (fgets(buffer, OUTPUT_SIZE, inputFile) == NULL) {
        perror("Error reading input file");
        fclose(inputFile);
        return;
    }
    fclose(inputFile);

    // Open the output file for writing the decompressed content
    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        perror("Error opening output file");
        return;
    }

    // Decompress the buffer and write to output file
    decompressRLE(buffer, outputFile);
    fclose(outputFile);

    printf("File successfully decompressed to %s\n", outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <compress/decompress> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "compress") == 0) {
        compressFile(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompressFile(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid action. Use 'compress' or 'decompress'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}