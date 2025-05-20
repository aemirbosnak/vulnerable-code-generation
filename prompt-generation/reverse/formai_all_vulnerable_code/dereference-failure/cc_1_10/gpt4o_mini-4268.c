//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <errno.h>

// Buffer sizes
#define BUFFER_SIZE 1024
#define HASH_SIZE SHA256_DIGEST_LENGTH

// Function to handle errors
void handle_error(const char *msg) {
    fprintf(stderr, "Error: %s. %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

// Function to compute the SHA-256 hash of a given input
void compute_sha256(const unsigned char *data, size_t len, unsigned char *hash_output) {
    if (data == NULL || len == 0 || hash_output == NULL) {
        handle_error("Invalid data or output buffer for SHA-256 computation.");
    }

    SHA256_CTX sha256;
    if (SHA256_Init(&sha256) != 1) {
        handle_error("Failed to initialize SHA-256 context.");
    }

    if (SHA256_Update(&sha256, data, len) != 1) {
        handle_error("Failed to update SHA-256 context.");
    }

    if (SHA256_Final(hash_output, &sha256) != 1) {
        handle_error("Failed to finalize SHA-256 hashing.");
    }
}

// Function to convert the hash to a hex string
void hash_to_hex_string(const unsigned char *hash, char *outputBuffer) {
    if (hash == NULL || outputBuffer == NULL) {
        handle_error("Invalid input for hash to hex conversion.");
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[HASH_SIZE * 2] = '\0'; // Null-terminate the string
}

// Main function
int main(int argc, char *argv[]) {
    // Paranoid checks: Ensure users provide valid input
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string to hash>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Prepare to hash the input
    const char *input_string = argv[1];
    size_t input_length = strlen(input_string);
    unsigned char hash[HASH_SIZE];
    char hash_hex[(HASH_SIZE * 2) + 1];

    // Compute the hash
    compute_sha256((unsigned char *)input_string, input_length, hash);

    // Convert to hex string
    hash_to_hex_string(hash, hash_hex);

    // Output the hash
    printf("Input: %s\n", input_string);
    printf("SHA-256 Hash: %s\n", hash_hex);

    // Detailed paranoia: Verify the output length
    if (strlen(hash_hex) != (HASH_SIZE * 2)) {
        handle_error("Hash output length mismatch. Possible corruption.");
    }

    // Successful execution
    return EXIT_SUCCESS;
}