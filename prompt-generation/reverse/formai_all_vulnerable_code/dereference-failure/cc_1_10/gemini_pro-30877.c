//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

// Function to compress a string using run-length encoding
char* compress(char* input) {
    int input_length = strlen(input);

    // Allocate memory for the output buffer
    char* output = (char*)malloc(MAX_OUTPUT_SIZE);

    // Initialize the output buffer
    int output_index = 0;

    // Iterate over the input string
    int i;
    for (i = 0; i < input_length; i++) {
        // Get the current character and its count
        char current_char = input[i];
        int count = 1;
        while (i + 1 < input_length && input[i + 1] == current_char) {
            count++;
            i++;
        }

        // Write the character and its count to the output buffer
        output[output_index++] = current_char;
        output[output_index++] = count;
    }

    // Return the compressed string
    return output;
}

// Function to decompress a string using run-length encoding
char* decompress(char* input) {
    int input_length = strlen(input);

    // Allocate memory for the output buffer
    char* output = (char*)malloc(MAX_OUTPUT_SIZE);

    // Initialize the output buffer
    int output_index = 0;

    // Iterate over the input string
    int i;
    for (i = 0; i < input_length; i += 2) {
        // Get the current character and its count
        char current_char = input[i];
        int count = input[i + 1];

        // Write the character to the output buffer count times
        int j;
        for (j = 0; j < count; j++) {
            output[output_index++] = current_char;
        }
    }

    // Return the decompressed string
    return output;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter the string to be compressed: ");
    gets(input);

    // Compress the input string
    char* compressed_string = compress(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_string);

    // Decompress the compressed string
    char* decompressed_string = decompress(compressed_string);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_string);

    return 0;
}