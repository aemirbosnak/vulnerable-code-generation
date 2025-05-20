//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to compress the string using LZW algorithm
uint8_t *compress(char *str, uint32_t *len) {
    // Create a dictionary to store the code for each substring
    char dictionary[MAX_SIZE][MAX_SIZE];
    uint32_t dict_size = 0;

    // Create a buffer to store the compressed string
    uint8_t *compressed = malloc(MAX_SIZE);
    uint32_t comp_size = 0;

    // Initialize the dictionary with the first character of the string
    strcpy(dictionary[dict_size++], str);

    // Iterate over the string and search for substrings in the dictionary
    for (uint32_t i = 0; i < *len; i++) {
        char code[MAX_SIZE] = {0};
        uint32_t code_len = 0;

        // Find the longest substring that matches a key in the dictionary
        for (uint32_t j = 0; i + j < *len; j++) {
            char substring[MAX_SIZE] = {0};
            strncpy(substring, str + i, j + 1);

            uint32_t k;
            for (k = 0; k < dict_size; k++) {
                if (!strcmp(substring, dictionary[k])) {
                    break;
                }
            }

            if (k < dict_size) {
                code_len = j + 1;
                strcpy(code, substring);
                break;
            }
        }

        // If the substring is not found in the dictionary, add it to the dictionary and encode it with a special code
        if (code_len == 0) {
            strcpy(code, str + i);
            code_len = 1;
            strcpy(dictionary[dict_size++], code);
        }

        // Encode the substring using the code and store it in the compressed buffer
        compressed[comp_size++] = dict_size - 1;

        // Update the string with the substring that follows the encoded substring
        i += code_len - 1;
    }

    *len = comp_size;
    return compressed;
}

// Function to decompress the string using LZW algorithm
char *decompress(uint8_t *compressed, uint32_t len) {
    // Create a dictionary to store the code for each substring
    char dictionary[MAX_SIZE][MAX_SIZE];
    uint32_t dict_size = 0;

    // Create a buffer to store the decompressed string
    char *decompressed = malloc(MAX_SIZE);
    uint32_t decomp_size = 0;

    // Initialize the dictionary with the first character of the compressed string
    strcpy(dictionary[dict_size++], compressed);

    // Iterate over the compressed string and decode the substrings
    for (uint32_t i = 0; i < len; i++) {
        uint8_t code = compressed[i];

        // If the code is not in the dictionary, add it to the dictionary and decode it with a special code
        if (code >= dict_size) {
            strcpy(dictionary[dict_size++], strcat(dictionary[code - 1], dictionary[code - 1]));
            code = dict_size - 1;
        }

        // Decode the substring using the code and store it in the decompressed buffer
        strcat(decompressed, dictionary[code]);

        // Update the dictionary with the substring that follows the decoded substring
        strcpy(dictionary[dict_size++], strcat(dictionary[code - 1], dictionary[code]));
    }

    return decompressed;
}

int main() {
    // Get the input string from the user
    char str[MAX_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", str);

    // Get the length of the input string
    uint32_t len = strlen(str);

    // Compress the string using LZW algorithm
    uint8_t *compressed = compress(str, &len);

    // Print the compressed string
    printf("Compressed string: ");
    for (uint32_t i = 0; i < len; i++) {
        printf("%02X", compressed[i]);
    }
    printf("\n");

    // Decompress the compressed string using LZW algorithm
    char *decompressed = decompress(compressed, len);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}