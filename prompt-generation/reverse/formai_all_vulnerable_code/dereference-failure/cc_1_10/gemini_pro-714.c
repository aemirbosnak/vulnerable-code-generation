//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to compress a string using Lempel-Ziv-Welch (LZW) algorithm
char *compress(char *str) {
    // Initialize the dictionary with the ASCII codes of all characters
    int dictionary_size = 256;
    char *dictionary[dictionary_size];
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Initialize the compressed string
    char *compressed = malloc(MAX_SIZE);
    int compressed_length = 0;

    // Initialize the current prefix and code
    char *prefix = malloc(MAX_SIZE);
    int code = 0;

    // Loop through the input string
    for (int i = 0; str[i] != '\0'; i++) {
        char *current_prefix = malloc(strlen(prefix) + 2);
        strcpy(current_prefix, prefix);
        current_prefix[strlen(prefix)] = str[i];
        current_prefix[strlen(prefix) + 1] = '\0';

        // Check if the current prefix is in the dictionary
        int found = 0;
        for (int j = 0; j < dictionary_size; j++) {
            if (!strcmp(current_prefix, dictionary[j])) {
                code = j;
                found = 1;
                break;
            }
        }

        // If the current prefix is not in the dictionary, add it to the dictionary and compress the previous prefix
        if (!found) {
            dictionary[dictionary_size++] = current_prefix;
            compressed[compressed_length++] = prefix[0];
            prefix = current_prefix;
            code = dictionary_size - 1;
        }
    }

    // Compress the last prefix
    compressed[compressed_length++] = prefix[0];

    // Return the compressed string
    return compressed;
}

// Function to decompress a compressed string using LZW algorithm
char *decompress(char *compressed) {
    // Initialize the dictionary with the ASCII codes of all characters
    int dictionary_size = 256;
    char *dictionary[dictionary_size];
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(2);
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Initialize the decompressed string
    char *decompressed = malloc(MAX_SIZE);
    int decompressed_length = 0;

    // Initialize the current code and prefix
    int code = 0;
    char *prefix = malloc(MAX_SIZE);

    // Loop through the compressed string
    for (int i = 0; i < strlen(compressed); i++) {
        code = compressed[i];

        // Check if the code is in the dictionary
        int found = 0;
        for (int j = 0; j < dictionary_size; j++) {
            if (code == j) {
                found = 1;
                break;
            }
        }

        // If the code is not in the dictionary, add the current prefix to the dictionary and decompress the previous prefix
        if (!found) {
            char *current_prefix = malloc(strlen(prefix) + 2);
            strcpy(current_prefix, prefix);
            current_prefix[strlen(prefix)] = prefix[0];
            current_prefix[strlen(prefix) + 1] = '\0';
            dictionary[dictionary_size++] = current_prefix;
            decompressed[decompressed_length++] = prefix[0];
            prefix = current_prefix;
        }

        // Decompress the current prefix
        decompressed[decompressed_length++] = dictionary[code][0];

        // Update the prefix
        char *new_prefix = malloc(strlen(prefix) + 2);
        strcpy(new_prefix, prefix);
        new_prefix[strlen(prefix)] = dictionary[code][0];
        new_prefix[strlen(prefix) + 1] = '\0';
        prefix = new_prefix;
    }

    // Return the decompressed string
    return decompressed;
}

int main() {
    // Get the input string from the user
    char *input_string = malloc(MAX_SIZE);
    printf("Enter the string to be compressed: ");
    scanf("%s", input_string);

    // Compress the string
    char *compressed_string = compress(input_string);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_string);

    // Decompress the compressed string
    char *decompressed_string = decompress(compressed_string);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_string);

    return 0;
}