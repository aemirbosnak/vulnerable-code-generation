//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Run-Length Encoding (RLE)
char* run_length_encode(const char* input) {
    int length = strlen(input);
    char* encoded = (char*)malloc(2 * length + 1); // Allocating maximum possible space
    int index = 0, count = 1;

    // Loop through the input string
    for (int i = 1; i <= length; i++) {
        // When the current character is the same as the previous one
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Store the character and its count in the encoded string
            index += sprintf(encoded + index, "%c%d", input[i - 1], count);
            count = 1; // Reset count for the new character
        }
    }
    // Return the encoded string
    return encoded;
}

// Function to perform Run-Length Decoding (RLD)
char* run_length_decode(const char* input) {
    char* decoded = (char*)malloc(strlen(input) * 2); // Length estimation for decoding
    int index = 0;

    // Reading the input string
    for (int i = 0; input[i] != '\0'; i += 2) {
        char ch = input[i];          // Character to decode
        int count = input[i + 1] - '0'; // Count of repetitions, assuming single-digit

        // Filling the decoded output
        for (int j = 0; j < count; j++) {
            decoded[index++] = ch;
        }
    }
    decoded[index] = '\0'; // Null-terminate the string
    return decoded;
}

int main() {
    // Input string for compression
    char input_string[100];

    // Curious about the input?
    printf("Enter a string for Run-Length Encoding (RLE): ");
    fgets(input_string, sizeof(input_string), stdin);

    // Remove newline character if present
    input_string[strcspn(input_string, "\n")] = 0;

    printf("\nOriginal String: %s\n", input_string);
    
    // Performing Run-Length Encoding
    char* compressed = run_length_encode(input_string);
    printf("Compressed String (RLE): %s\n", compressed);

    // Performing Run-Length Decoding
    char* decompressed = run_length_decode(compressed);
    printf("Decompressed String: %s\n", decompressed);
    
    // Free the allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}