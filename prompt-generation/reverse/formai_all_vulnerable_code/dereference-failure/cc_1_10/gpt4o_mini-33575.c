//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Function to perform Run Length Encoding
char *run_length_encode(const char *input) {
    int len = strlen(input);
    if (len == 0) return strdup("");

    char *encoded = malloc(MAX_LEN);
    if (encoded == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count = 1, index = 0;

    // Iterate through the input string to encode it
    for (int i = 1; i <= len; i++) {
        // Check if the current character is the same as the previous one
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Append the character and its count to the encoded string
            index += snprintf(&encoded[index], MAX_LEN - index, "%c%d", input[i - 1], count);
            count = 1; // Reset count for new character
        }
    }

    // Null-terminate the encoded string
    encoded[index] = '\0';

    return encoded;
}

// Function to perform Run Length Decoding
char *run_length_decode(const char *input) {
    int len = strlen(input);
    char *decoded = malloc(MAX_LEN);
    if (decoded == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;

    // Iterate through the encoded string to decode it
    for (int i = 0; i < len; i++) {
        char currentChar = input[i];
        i++;

        // Read the count which can be one or more digits
        int count = 0;
        while (i < len && input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // Decrement to adjust for the outer loop increment

        // Append characters to the decoded string
        for (int j = 0; j < count; j++) {
            decoded[index++] = currentChar;
        }
    }

    // Null-terminate the decoded string
    decoded[index] = '\0';

    return decoded;
}

int main() {
    char input[MAX_LEN];

    // Get user input
    printf("Enter a string to compress: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    // Perform compression
    char *compressed = run_length_encode(input);
    printf("Compressed: %s\n", compressed);

    // Perform decompression
    char *decompressed = run_length_decode(compressed);
    printf("Decompressed: %s\n", decompressed);

    // Free allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}