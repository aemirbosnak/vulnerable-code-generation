//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress string using run-length encoding
char* compress(const char* input) {
    int len = strlen(input);
    if (len == 0) return "";

    // Allocate worst-case memory (each character could become "1x" format)
    char* compressed = malloc(len * 2 + 1);
    if (!compressed) return NULL;

    int count = 1; // To count occurrences
    int j = 0; // Index for compressed string

    for (int i = 1; i <= len; i++) {
        // Check for the end or when the character changes
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Store the character and its count
            j += snprintf(&compressed[j], len * 2 + 1 - j, "%d%c", count, input[i - 1]);
            count = 1; // Reset count
        }
    }
    compressed[j] = '\0'; // Null terminate the string

    return compressed;
}

// Function to decompress the string
char* decompress(const char* input) {
    int len = strlen(input);
    // Calculate maximum size for decompressed string
    char* decompressed = malloc(len * 2 + 1);
    if (!decompressed) return NULL;

    int j = 0; // Index for decompressed string

    for (int i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            // Capture the full number (can be more than 1 digit)
            int count = 0;
            while (i < len && isdigit(input[i])) {
                count = count * 10 + (input[i] - '0');
                i++;
            }
            // Now we expect a character after the number
            if (i < len) {
                for (int k = 0; k < count; k++) {
                    decompressed[j++] = input[i];
                }
            }
        }
    }
    
    decompressed[j] = '\0'; // Null terminate the decompressed string
    return decompressed;
}

int main() {
    printf("Welcome to the Compression Puzzle!\n");
    printf("Please enter a string to compress: ");

    char input[256];
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from string input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Try to compress and check for success
    char* compressed = compress(input);
    if (compressed) {
        printf("Compressed string: %s\n", compressed);
        char* decompressed = decompress(compressed);
        if (decompressed) {
            printf("Decompressed string: %s\n", decompressed);
            free(decompressed); // Free memory for decompressed string
        }
        free(compressed); // Free memory for compressed string
    }

    printf("Thank you for playing!\n");
    return 0; // All done!
}