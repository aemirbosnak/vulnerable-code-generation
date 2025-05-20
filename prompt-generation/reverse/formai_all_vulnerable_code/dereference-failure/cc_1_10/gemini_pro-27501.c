//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 1024

// Define the maximum number of characters to be repeated in a row
#define MAX_REPEAT_COUNT 9

// Function to compress a string using run-length encoding
char *compress(char *input) {
    // Allocate memory for the compressed string
    char *output = malloc(MAX_STRING_SIZE);

    // Initialize the output string
    output[0] = '\0';

    // Iterate over the input string
    int i = 0;
    while (input[i] != '\0') {
        // Count the number of consecutive occurrences of the current character
        int count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // If the count is greater than 1, add the character and the count to the output string
        if (count > 1) {
            char buffer[10];
            sprintf(buffer, "%c%d", input[i], count);
            strcat(output, buffer);
        } else {
            // Otherwise, just add the character to the output string
            strcat(output, &input[i]);
        }

        // Increment the index of the input string
        i++;
    }

    // Return the compressed string
    return output;
}

// Function to decompress a string using run-length encoding
char *decompress(char *input) {
    // Allocate memory for the decompressed string
    char *output = malloc(MAX_STRING_SIZE);

    // Initialize the output string
    output[0] = '\0';

    // Iterate over the input string
    int i = 0;
    while (input[i] != '\0') {
        // If the current character is a digit, it represents the count of the next character
        if (isdigit(input[i])) {
            int count = input[i] - '0';
            i++;

            // Repeat the next character count times
            while (count--) {
                strcat(output, &input[i]);
            }

            // Increment the index of the input string
            i++;
        } else {
            // Otherwise, just add the character to the output string
            strcat(output, &input[i]);

            // Increment the index of the input string
            i++;
        }
    }

    // Return the decompressed string
    return output;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_STRING_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", input);

    // Compress the input string
    char *compressed_string = compress(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_string);

    // Decompress the compressed string
    char *decompressed_string = decompress(compressed_string);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_string);

    // Free the memory allocated for the compressed and decompressed strings
    free(compressed_string);
    free(decompressed_string);

    return 0;
}