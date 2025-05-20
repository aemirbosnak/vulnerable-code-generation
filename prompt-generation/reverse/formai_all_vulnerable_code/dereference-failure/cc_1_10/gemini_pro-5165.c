//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compress a string using a simple run-length encoding algorithm.
char *compress(const char *str) {
    // Allocate a buffer for the compressed string.
    char *compressed = malloc(strlen(str) + 1);
    if (compressed == NULL) {
        return NULL;
    }

    // Initialize the compressed string.
    char *compressed_ptr = compressed;

    // Iterate over the input string.
    const char *str_ptr = str;
    while (*str_ptr) {
        // Count the number of consecutive characters.
        int count = 1;
        while (*str_ptr && *str_ptr == *(str_ptr + 1)) {
            count++;
            str_ptr++;
        }

        // Store the character and the count in the compressed string.
        *compressed_ptr++ = *str_ptr;
        *compressed_ptr++ = count;
        str_ptr++;
    }

    // Terminate the compressed string.
    *compressed_ptr = '\0';

    // Return the compressed string.
    return compressed;
}

// Decompress a string that was compressed using a simple run-length encoding algorithm.
char *decompress(const char *compressed) {
    // Allocate a buffer for the decompressed string.
    char *decompressed = malloc(strlen(compressed) * 2 + 1);
    if (decompressed == NULL) {
        return NULL;
    }

    // Initialize the decompressed string.
    char *decompressed_ptr = decompressed;

    // Iterate over the compressed string.
    const char *compressed_ptr = compressed;
    while (*compressed_ptr) {
        // Get the character and the count.
        char character = *compressed_ptr++;
        int count = *compressed_ptr++;

        // Append the character to the decompressed string the specified number of times.
        for (int i = 0; i < count; i++) {
            *decompressed_ptr++ = character;
        }
    }

    // Terminate the decompressed string.
    *decompressed_ptr = '\0';

    // Return the decompressed string.
    return decompressed;
}

// Print the usage of the program.
void usage(const char *program_name) {
    printf("Usage: %s <compress|decompress> <string>\n", program_name);
    printf("Examples:\n");
    printf("  %s compress \"Hello, world!\"\n", program_name);
    printf("  %s decompress \"H1e1l1l1o1 ,1 w1o1r1l1d1!\"\n", program_name);
}

// Main function.
int main(int argc, char **argv) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Get the operation and the string.
    char *operation = argv[1];
    char *string = argv[2];

    // Compress or decompress the string depending on the operation.
    char *result;
    if (strcmp(operation, "compress") == 0) {
        result = compress(string);
    } else if (strcmp(operation, "decompress") == 0) {
        result = decompress(string);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        usage(argv[0]);
        return 1;
    }

    // Print the result.
    printf("%s\n", result);

    // Free the allocated memory.
    free(result);

    return 0;
}