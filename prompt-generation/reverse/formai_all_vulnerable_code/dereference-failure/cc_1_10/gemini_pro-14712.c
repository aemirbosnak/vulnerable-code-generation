//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom hash function using SHA-256
unsigned char* custom_hash(const char* message) {
    unsigned char* hash = malloc(SHA256_DIGEST_LENGTH);
    if (hash == NULL) {
        perror("malloc");
        exit(1);
    }

    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, message, strlen(message));
    SHA256_Final(hash, &context);

    return hash;
}

// Function to convert a byte array to a hex string
char* bytes_to_hex(const unsigned char* bytes, size_t len) {
    char* hex = malloc(2 * len + 1);
    if (hex == NULL) {
        perror("malloc");
        exit(1);
    }

    for (size_t i = 0; i < len; i++) {
        sprintf(hex + 2 * i, "%02x", bytes[i]);
    }

    hex[2 * len] = '\0';

    return hex;
}

// Main function
int main() {
    // Message to be hashed
    char* message = "Hello, world!";

    // Calculate the hash
    unsigned char* hash = custom_hash(message);

    // Convert the hash to a hex string
    char* hex_hash = bytes_to_hex(hash, SHA256_DIGEST_LENGTH);

    // Print the hex hash
    printf("Hash: %s\n", hex_hash);

    // Free the allocated memory
    free(hash);
    free(hex_hash);

    return 0;
}