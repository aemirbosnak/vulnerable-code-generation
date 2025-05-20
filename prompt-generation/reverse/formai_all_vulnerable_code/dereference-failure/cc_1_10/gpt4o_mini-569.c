//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

// Function to compress the input string using run-length encoding
char *compress(const char *input) {
    if (input == NULL) {
        return NULL;
    }

    size_t input_length = strlen(input);
    char *output = (char *)malloc(MAX_INPUT_LENGTH);
    if (output == NULL) {
        perror("Failed to allocate memory for output");
        exit(EXIT_FAILURE);
    }

    int count = 1, index = 0;
    for (size_t i = 1; i <= input_length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            index += snprintf(output + index, MAX_INPUT_LENGTH - index, "%d%c", count, input[i - 1]);
            count = 1;
        }
    }

    return output;
}

// Function to decompress the run-length encoded string
char *decompress(const char *input) {
    if (input == NULL) {
        return NULL;
    }

    char *output = (char *)malloc(MAX_INPUT_LENGTH);
    if (output == NULL) {
        perror("Failed to allocate memory for output");
        exit(EXIT_FAILURE);
    }

    size_t index = 0, length = strlen(input);
    for (size_t i = 0; i < length; i++) {
        int count = 0;

        while (isdigit(input[i])) { // Read the number
            count = count * 10 + (input[i] - '0');
            i++;
        }

        if (i < length) {
            for (int j = 0; j < count; j++) {
                output[index++] = input[i];
            }
        }
    }
    output[index] = '\0'; // Null-terminate the output string

    return output;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string to compress (max length %d): ", MAX_INPUT_LENGTH - 1);
    if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
        perror("Failed to read input");
        return EXIT_FAILURE;
    }

    // Remove the newline character from input if present
    input[strcspn(input, "\n")] = 0;

    char *compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    char *decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    // Cleanup allocated memory
    free(compressed);
    free(decompressed);

    return EXIT_SUCCESS;
}