//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compress a string using LZW algorithm
char* compress(char* str) {
    // Create a dictionary of all unique characters in the string
    int dictSize = 256;
    char* dict[dictSize];
    for (int i = 0; i < dictSize; i++) {
        dict[i] = malloc(2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    // Initialize the compressed string
    char* compressed = malloc(strlen(str) + 1);
    compressed[0] = '\0';

    // Initialize the codeword dictionary
    int codewordDict[dictSize];
    for (int i = 0; i < dictSize; i++) {
        codewordDict[i] = -1;
    }

    // Initialize the current codeword
    int codeword = dictSize;

    // Initialize the previous codeword
    int prevCodeword = -1;

    // Iterate over the string
    for (int i = 0; i < strlen(str); i++) {
        // Get the current character
        char c = str[i];

        // Check if the current character is already in the dictionary
        int index = -1;
        for (int j = 0; j < dictSize; j++) {
            if (strcmp(dict[j], &c) == 0) {
                index = j;
                break;
            }
        }

        // If the current character is not in the dictionary, add it
        if (index == -1) {
            dict[codeword][0] = c;
            dict[codeword][1] = '\0';
            codewordDict[index] = codeword;
            codeword++;
        }

        // If the current character is already in the dictionary, get its codeword
        else {
            index = codewordDict[index];
        }

        // Append the codeword to the compressed string
        sprintf(compressed, "%s%d", compressed, index);

        // Update the previous codeword
        prevCodeword = index;
    }

    // Free the memory allocated for the dictionary
    for (int i = 0; i < dictSize; i++) {
        free(dict[i]);
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string using LZW algorithm
char* decompress(char* compressed) {
    // Create a dictionary of all unique characters in the string
    int dictSize = 256;
    char* dict[dictSize];
    for (int i = 0; i < dictSize; i++) {
        dict[i] = malloc(2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    // Initialize the decompressed string
    char* decompressed = malloc(strlen(compressed) + 1);
    decompressed[0] = '\0';

    // Initialize the codeword dictionary
    int codewordDict[dictSize];
    for (int i = 0; i < dictSize; i++) {
        codewordDict[i] = -1;
    }

    // Initialize the current codeword
    int codeword = dictSize;

    // Initialize the previous codeword
    int prevCodeword = -1;

    // Iterate over the compressed string
    for (int i = 0; i < strlen(compressed); i++) {
        // Get the current codeword
        int codeword = compressed[i] - '0';

        // Check if the current codeword is already in the dictionary
        int index = -1;
        for (int j = 0; j < dictSize; j++) {
            if (codewordDict[j] == codeword) {
                index = j;
                break;
            }
        }

        // If the current codeword is not in the dictionary, add it
        if (index == -1) {
            dict[codeword][0] = dict[prevCodeword][0];
            dict[codeword][1] = dict[prevCodeword][1];
            codewordDict[index] = codeword;
            codeword++;
        }

        // If the current codeword is already in the dictionary, get its character
        else {
            index = codewordDict[index];
        }

        // Append the character to the decompressed string
        sprintf(decompressed, "%s%s", decompressed, dict[index]);

        // Update the previous codeword
        prevCodeword = codeword;
    }

    // Free the memory allocated for the dictionary
    for (int i = 0; i < dictSize; i++) {
        free(dict[i]);
    }

    // Return the decompressed string
    return decompressed;
}

// Function to test the compression and decompression algorithms
void test() {
    // Create a test string
    char* str = "Hello world! This is a test string to test the compression and decompression algorithms.";

    // Compress the string
    char* compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char* decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Check if the decompressed string is equal to the original string
    if (strcmp(str, decompressed) == 0) {
        printf("Compression and decompression successful!\n");
    } else {
        printf("Compression or decompression failed!\n");
    }
}

// Main function
int main() {
    // Test the compression and decompression algorithms
    test();

    return 0;
}