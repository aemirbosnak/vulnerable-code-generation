//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform run-length encoding
char* run_length_encode(const char* input) {
    int length = strlen(input);
    if (length == 0) return strdup("");

    char* encoded = (char*)malloc(length * 2); // Allocate enough memory for the encoded string
    if (!encoded) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int count = 1, j = 0;

    for (int i = 1; i <= length; i++) {
        // Count occurrences of each character
        if (i < length && input[i] == input[i - 1]) {
            count++;
        } else {
            // Save the character and its count
            j += sprintf(encoded + j, "%c%d", input[i - 1], count);
            count = 1; // Reset count
        }
    }

    return encoded;
}

// Function to perform run-length decoding
char* run_length_decode(const char* input) {
    int length = strlen(input);
    char* decoded = (char*)malloc(length * 2); // Allocate enough memory for the decoded string
    if (!decoded) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;

    for (int i = 0; i < length; i++) {
        char current_char = input[i];

        // Proceed to the next character to get the count
        i++;
        int count = 0;

        // Convert the digit after the character to an integer
        while (i < length && input[i] >= '0' && input[i] <= '9') {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--; // Adjust i for the outer loop increment

        for (int k = 0; k < count; k++) {
            decoded[j++] = current_char; // Add the character 'count' times
        }
    }

    decoded[j] = '\0'; // Null-terminate the decoded string
    return decoded;
}

int main() {
    char input[256];

    printf("Enter a string to compress: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character from fgets
    input[strcspn(input, "\n")] = 0;

    char* compressed = run_length_encode(input);
    char* decompressed = run_length_decode(compressed);

    printf("\nOriginal String: %s\n", input);
    printf("Compressed String: %s\n", compressed);
    printf("Decompressed String: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}