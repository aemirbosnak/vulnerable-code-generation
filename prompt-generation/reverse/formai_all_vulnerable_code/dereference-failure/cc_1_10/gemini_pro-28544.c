//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 1000

// Define the maximum size of the compressed string
#define MAX_COMPRESSED_STRING_SIZE 500

// Function to compress a string using the Lempel-Ziv-Welch (LZW) algorithm
char* compress(char* input) {
    // Initialize the compression dictionary
    int dictionary_size = 256;
    char* dictionary[dictionary_size];
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = (char) i;
        dictionary[i][1] = '\0';
    }

    // Initialize the compressed string
    char* compressed = malloc(MAX_COMPRESSED_STRING_SIZE);
    int compressed_length = 0;

    // Initialize the current code
    int current_code = dictionary_size;

    // Loop through the input string
    for (int i = 0; i < strlen(input); i++) {
        // Find the longest prefix of the input string that is already in the dictionary
        int prefix_length = 0;
        while (i + prefix_length < strlen(input) && dictionary[current_code + prefix_length] != NULL && dictionary[current_code + prefix_length][prefix_length] == input[i + prefix_length]) {
            prefix_length++;
        }

        // If the longest prefix is not in the dictionary, add it to the dictionary
        if (dictionary[current_code + prefix_length] == NULL) {
            dictionary[current_code + prefix_length] = malloc(prefix_length + 2);
            strncpy(dictionary[current_code + prefix_length], input + i, prefix_length);
            dictionary[current_code + prefix_length][prefix_length] = '\0';
            dictionary_size++;
        }

        // Add the code for the longest prefix to the compressed string
        compressed[compressed_length++] = (char) current_code;

        // Update the current code
        current_code = current_code + prefix_length;

        // If the dictionary is full, reset it
        if (dictionary_size == 4096) {
            for (int i = 0; i < dictionary_size; i++) {
                free(dictionary[i]);
            }
            dictionary_size = 256;
            for (int i = 0; i < dictionary_size; i++) {
                dictionary[i] = malloc(2);
                dictionary[i][0] = (char) i;
                dictionary[i][1] = '\0';
            }
            current_code = dictionary_size;
        }
    }

    // Add the end-of-string code to the compressed string
    compressed[compressed_length++] = (char) current_code;

    // Return the compressed string
    return compressed;
}

// Function to decompress a string using the LZW algorithm
char* decompress(char* compressed) {
    // Initialize the decompression dictionary
    int dictionary_size = 256;
    char* dictionary[dictionary_size];
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = (char) i;
        dictionary[i][1] = '\0';
    }

    // Initialize the decompressed string
    char* decompressed = malloc(MAX_STRING_SIZE);
    int decompressed_length = 0;

    // Initialize the current code
    int current_code = dictionary_size;

    // Loop through the compressed string
    for (int i = 0; i < strlen(compressed); i++) {
        // Get the next code from the compressed string
        int code = (unsigned char) compressed[i];

        // If the code is not in the dictionary, add it to the dictionary
        if (dictionary[code] == NULL) {
            dictionary[code] = malloc(decompressed_length + 2);
            strncpy(dictionary[code], decompressed + decompressed_length - 1, decompressed_length);
            dictionary[code][decompressed_length] = dictionary[current_code][0];
            dictionary[code][decompressed_length + 1] = '\0';
            dictionary_size++;
        }

        // Add the decoded string to the decompressed string
        strcat(decompressed, dictionary[code]);
        decompressed_length += strlen(dictionary[code]);

        // Update the current code
        current_code = code;

        // If the dictionary is full, reset it
        if (dictionary_size == 4096) {
            for (int i = 0; i < dictionary_size; i++) {
                free(dictionary[i]);
            }
            dictionary_size = 256;
            for (int i = 0; i < dictionary_size; i++) {
                dictionary[i] = malloc(2);
                dictionary[i][0] = (char) i;
                dictionary[i][1] = '\0';
            }
            current_code = dictionary_size;
        }
    }

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_STRING_SIZE];
    printf("Enter a string to compress: ");
    gets(input);

    // Compress the string
    char* compressed = compress(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char* decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}