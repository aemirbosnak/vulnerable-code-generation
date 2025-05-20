//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define the size of the input and output buffers
#define INPUT_BUFFER_SIZE 1024
#define OUTPUT_BUFFER_SIZE 65

// Define the SHA-256 hash function
void sha256(const char *input, char *output) {
    // Create a SHA-256 context
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    // Update the context with the input data
    SHA256_Update(&ctx, input, strlen(input));

    // Finalize the context and get the hash digest
    SHA256_Final((unsigned char *)output, &ctx);
}

// Print the SHA-256 hash of the input string
void print_sha256(const char *input) {
    // Allocate memory for the output buffer
    char *output = malloc(OUTPUT_BUFFER_SIZE);

    // Compute the SHA-256 hash of the input string
    sha256(input, output);

    // Print the hash as a hexadecimal string
    for (int i = 0; i < OUTPUT_BUFFER_SIZE; i++) {
        printf("%02x", output[i]);
    }

    // Free the memory allocated for the output buffer
    free(output);
}

int main(int argc, char **argv) {
    // Check if the user has provided an input string
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the input string from the user
    char *input = argv[1];

    // Print the SHA-256 hash of the input string
    printf("SHA-256 hash: ");
    print_sha256(input);
    printf("\n");

    return EXIT_SUCCESS;
}