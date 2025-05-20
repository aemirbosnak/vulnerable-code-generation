//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to compress a string using the LZW algorithm
char *compress(char *uncompressed) {
    // Create a dictionary to store the compressed codes, and initialize it with the first 256 ASCII characters
    int dictionarySize = 256;
    char *dictionary[dictionarySize];
    for (int i = 0; i < 256; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Create a compressed string to store the compressed codes
    char *compressed = malloc(MAX_SIZE);
    int compressedSize = 0;

    // Create a string to store the current substring being processed
    char *substring = malloc(MAX_SIZE);
    int substringSize = 0;

    // Iterate over the uncompressed string
    for (int i = 0; i < strlen(uncompressed); i++) {
        // Add the current character to the substring
        substring[substringSize++] = uncompressed[i];

        // Check if the substring is in the dictionary
        int code = -1;
        for (int j = 0; j < dictionarySize; j++) {
            if (strcmp(substring, dictionary[j]) == 0) {
                code = j;
                break;
            }
        }

        // If the substring is not in the dictionary, add it to the dictionary and compress the substring
        if (code == -1) {
            dictionary[dictionarySize++] = malloc(strlen(substring) + 1);
            strcpy(dictionary[dictionarySize - 1], substring);

            // Compress the substring by adding its code to the compressed string
            compressed[compressedSize++] = (code >> 8) & 0xFF;
            compressed[compressedSize++] = code & 0xFF;

            // Reset the substring size
            substringSize = 0;
        }
    }

    // Compress the remaining substring
    if (substringSize > 0) {
        int code = -1;
        for (int j = 0; j < dictionarySize; j++) {
            if (strcmp(substring, dictionary[j]) == 0) {
                code = j;
                break;
            }
        }

        // Compress the substring by adding its code to the compressed string
        compressed[compressedSize++] = (code >> 8) & 0xFF;
        compressed[compressedSize++] = code & 0xFF;
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string using the LZW algorithm
char *decompress(char *compressed) {
    // Create a dictionary to store the decompressed codes, and initialize it with the first 256 ASCII characters
    int dictionarySize = 256;
    char *dictionary[dictionarySize];
    for (int i = 0; i < 256; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Create a decompressed string to store the decompressed characters
    char *decompressed = malloc(MAX_SIZE);
    int decompressedSize = 0;

    // Create a string to store the current code being processed
    int code = -1;

    // Iterate over the compressed string
    for (int i = 0; i < strlen(compressed); i++) {
        // Read the next code from the compressed string
        code = (code << 8) | compressed[i];

        // Check if the code is in the dictionary
        char *string = NULL;
        if (code < dictionarySize) {
            string = dictionary[code];
        } else if (code == dictionarySize) {
            string = malloc(strlen(dictionary[code - 1]) + 2);
            strcpy(string, dictionary[code - 1]);
            strcat(string, dictionary[code - 1][0]);
        }

        // Add the decompressed string to the decompressed string
        for (int j = 0; j < strlen(string); j++) {
            decompressed[decompressedSize++] = string[j];
        }

        // Add the current code to the dictionary
        if (code < dictionarySize) {
            dictionary[dictionarySize++] = malloc(strlen(dictionary[code - 1]) + 2);
            strcpy(dictionary[dictionarySize - 1], dictionary[code - 1]);
            dictionary[dictionarySize - 1][strlen(dictionary[dictionarySize - 1])] = string[0];
            dictionary[dictionarySize - 1][strlen(dictionary[dictionarySize - 1]) + 1] = '\0';
        }
    }

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the uncompressed string from the user
    char *uncompressed = malloc(MAX_SIZE);
    printf("Enter the uncompressed string: ");
    gets(uncompressed);

    // Compress the string using the LZW algorithm
    char *compressed = compress(uncompressed);

    // Print the compressed string
    printf("Compressed string: ");
    for (int i = 0; i < strlen(compressed); i++) {
        printf("%02X", compressed[i]);
    }
    printf("\n");

    // Decompress the string using the LZW algorithm
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}