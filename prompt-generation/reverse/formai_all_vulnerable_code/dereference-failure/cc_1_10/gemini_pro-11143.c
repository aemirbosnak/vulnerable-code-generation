//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom SHA-256 hash function using OpenSSL
unsigned char *custom_sha256(const unsigned char *input, size_t length, unsigned char *output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, length);
    SHA256_Final(output, &ctx);
    return output;
}

// Enhanced SHA-256 hash function that incorporates salting and iteration
unsigned char *enhanced_sha256(const unsigned char *input, size_t length, unsigned char *output,
                                 const unsigned char *salt, size_t salt_length, size_t iterations) {
    unsigned char *hashed_input = malloc(SHA256_DIGEST_LENGTH);
    memcpy(hashed_input, input, length);

    for (size_t i = 0; i < iterations; i++) {
        // Append salt to input and hash it
        memcpy(hashed_input + length, salt, salt_length);
        custom_sha256(hashed_input, length + salt_length, hashed_input);
    }

    memcpy(output, hashed_input, SHA256_DIGEST_LENGTH);
    free(hashed_input);
    return output;
}

int main() {
    unsigned char input[] = "Hello, world!";
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // Basic SHA-256 hash
    custom_sha256(input, strlen(input), hash);
    printf("Basic SHA-256 hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // Salted and iterated SHA-256 hash
    unsigned char salt[] = "My secret salt";
    enhanced_sha256(input, strlen(input), hash, salt, strlen(salt), 1000);
    printf("Enhanced SHA-256 hash (salted, iterated 1000 times): ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}