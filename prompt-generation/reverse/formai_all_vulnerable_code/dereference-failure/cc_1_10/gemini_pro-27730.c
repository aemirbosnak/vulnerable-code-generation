//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define SHA256_DIGEST_LENGTH 32

// A simple function to calculate the SHA256 hash of a string
unsigned char* sha256(const unsigned char *str, size_t len) {
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, len);
    SHA256_Final(hash, &sha256);
    return hash;
}

// A function to print the SHA256 hash of a string
void print_sha256(const unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// A function to calculate the SHA256 hash of a file
unsigned char* sha256_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);

    unsigned char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        SHA256_Update(&sha256, buffer, bytes_read);
    }

    SHA256_Final(hash, &sha256);

    fclose(file);

    return hash;
}

int main() {
    // Calculate the SHA256 hash of a string
    unsigned char *hash = sha256("Hello, world!", strlen("Hello, world!"));

    // Print the hash
    printf("The SHA256 hash of 'Hello, world!' is: ");
    print_sha256(hash);

    // Calculate the SHA256 hash of a file
    hash = sha256_file("test.txt");

    // Print the hash
    printf("The SHA256 hash of 'test.txt' is: ");
    print_sha256(hash);

    free(hash);

    return 0;
}