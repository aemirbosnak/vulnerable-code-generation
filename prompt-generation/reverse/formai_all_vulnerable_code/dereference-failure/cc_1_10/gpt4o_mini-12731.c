//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size for the input data
#define MAX_SIZE 1024

// Function to compress the data using a simple RLE (Run Length Encoding) method
void compressRLE(char *input, char *output) {
    int count, length = strlen(input);
    int i, j = 0;

    for (i = 0; i < length; i++) {
        // Count occurrences of the same character
        count = 1;
        while (i + 1 < length && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Store the character and the count in the output
        output[j++] = input[i];
        output[j++] = count + '0';   // Convert count to char and add to output
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to decompress the data using a simple RLE method
void decompressRLE(char *input, char *output) {
    int i, j = 0;
    int length = strlen(input);

    for (i = 0; i < length; i += 2) {
        char character = input[i];
        int count = input[i + 1] - '0'; // Convert char back to int

        for (int k = 0; k < count; k++) {
            output[j++] = character;
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to print usage instructions
void printUsage() {
    printf("Usage:\n");
    printf("1. Compress: ./compressor <input_string>\n");
    printf("2. Decompress: ./compressor -d <compressed_string>\n");
}

int main(int argc, char *argv[]) {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    
    if (argc < 2) {
        printUsage();
        return 1;
    }

    if (strcmp(argv[1], "-d") == 0 && argc == 3) {
        // Decompression mode
        strcpy(input, argv[2]);
        decompressRLE(input, output);
        printf("Decompressed: %s\n", output);
    } else if (argc == 2) {
        // Compression mode
        strcpy(input, argv[1]);
        compressRLE(input, output);
        printf("Compressed: %s\n", output);
    } else {
        printUsage();
        return 1;
    }

    return 0;
}