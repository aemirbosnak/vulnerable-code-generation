//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a simple compression algorithm that works by replacing repeated sequences of characters with a single character.
// The algorithm is not very efficient, but it is easy to understand and implement.

// The maximum length of a repeated sequence that the algorithm can handle.
#define MAX_REPEAT_LENGTH 10

// The character that is used to represent repeated sequences.
#define REPEAT_CHAR '$'

// Compresses the given string using the simple compression algorithm.
char *compress(char *str) {
    // The compressed string.
    char *compressed = malloc(strlen(str) + 1);

    // The current position in the compressed string.
    int compressed_pos = 0;

    // The current position in the original string.
    int str_pos = 0;

    // The current length of the repeated sequence.
    int repeat_length = 0;

    // The current character being processed.
    char current_char = str[str_pos];

    // Loop through the original string.
    while (str_pos < strlen(str)) {
        // If the current character is the same as the previous character, increment the repeat length.
        if (current_char == str[str_pos + 1]) {
            repeat_length++;
        }
        // Otherwise, write the repeat length and the repeated character to the compressed string.
        else {
            compressed[compressed_pos++] = repeat_length;
            compressed[compressed_pos++] = current_char;

            // Reset the repeat length.
            repeat_length = 0;
        }

        // Increment the position in the original string.
        str_pos++;

        // Update the current character.
        current_char = str[str_pos];
    }

    // Write the last repeat length and the last repeated character to the compressed string.
    compressed[compressed_pos++] = repeat_length;
    compressed[compressed_pos++] = current_char;

    // Null-terminate the compressed string.
    compressed[compressed_pos] = '\0';

    // Return the compressed string.
    return compressed;
}

// Decompresses the given string using the simple compression algorithm.
char *decompress(char *str) {
    // The decompressed string.
    char *decompressed = malloc(strlen(str) * MAX_REPEAT_LENGTH + 1);

    // The current position in the decompressed string.
    int decompressed_pos = 0;

    // The current position in the compressed string.
    int str_pos = 0;

    // The current repeat length.
    int repeat_length = 0;

    // The current character being processed.
    char current_char = str[str_pos];

    // Loop through the compressed string.
    while (str_pos < strlen(str)) {
        // Read the repeat length.
        repeat_length = str[str_pos++];

        // Read the repeated character.
        current_char = str[str_pos++];

        // Write the repeated character to the decompressed string.
        for (int i = 0; i < repeat_length; i++) {
            decompressed[decompressed_pos++] = current_char;
        }
    }

    // Null-terminate the decompressed string.
    decompressed[decompressed_pos] = '\0';

    // Return the decompressed string.
    return decompressed;
}

// Prints the usage of the program.
void print_usage() {
    printf("Usage: %s <compress|decompress> <string>\n", __FILE__);
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user has provided enough arguments.
    if (argc != 3) {
        print_usage();
        return 1;
    }

    // Get the command and the string.
    char *command = argv[1];
    char *str = argv[2];

    // Compress the string.
    if (strcmp(command, "compress") == 0) {
        char *compressed = compress(str);

        // Print the compressed string.
        printf("Compressed string: %s\n", compressed);

        // Free the compressed string.
        free(compressed);
    }
    // Decompress the string.
    else if (strcmp(command, "decompress") == 0) {
        char *decompressed = decompress(str);

        // Print the decompressed string.
        printf("Decompressed string: %s\n", decompressed);

        // Free the decompressed string.
        free(decompressed);
    }
    // Print the usage.
    else {
        print_usage();
        return 1;
    }

    return 0;
}