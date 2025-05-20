//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom type for a SHA256 hash
typedef unsigned char SHA256_HASH[SHA256_DIGEST_LENGTH];

// Function to compute the SHA256 hash of a string
void compute_sha256_hash(const char *str, SHA256_HASH *hash) {
    SHA256_CTX ctx;

    // Initialize the SHA256 context
    if (!SHA256_Init(&ctx)) {
        fprintf(stderr, "Error initializing SHA256 context\n");
        exit(EXIT_FAILURE);
    }

    // Update the SHA256 context with the string
    if (!SHA256_Update(&ctx, str, strlen(str))) {
        fprintf(stderr, "Error updating SHA256 context\n");
        exit(EXIT_FAILURE);
    }

    // Finalize the SHA256 context and get the hash
    if (!SHA256_Final(*hash, &ctx)) {
        fprintf(stderr, "Error finalizing SHA256 context\n");
        exit(EXIT_FAILURE);
    }
}

// Function to print a SHA256 hash in hexadecimal format
void print_sha256_hash(const SHA256_HASH *hash) {
    int i;
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Function to generate a random string
char *generate_random_string(size_t length) {
    char *str = malloc(length + 1);
    if (!str) {
        fprintf(stderr, "Error allocating memory for random string\n");
        exit(EXIT_FAILURE);
    }

    // Generate a random string of the specified length
    int i;
    for (i = 0; i < length; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[length] = '\0';

    return str;
}

int main() {
    // Generate a random string
    char *str = generate_random_string(10);

    // Compute the SHA256 hash of the string
    SHA256_HASH hash;
    compute_sha256_hash(str, &hash);

    // Print the SHA256 hash
    printf("SHA256 Hash of \"%s\": ", str);
    print_sha256_hash(&hash);

    // Free the memory allocated for the random string
    free(str);

    return EXIT_SUCCESS;
}