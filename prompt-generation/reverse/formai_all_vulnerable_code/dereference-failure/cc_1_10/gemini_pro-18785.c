//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate the SHA256 hash of a string
unsigned char *sha256(const unsigned char *str, size_t len) {
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, len);
    SHA256_Final(hash, &sha256);
    return hash;
}

// Function to compare two strings
int strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Function to print a hex string
void print_hex(unsigned char *str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", str[i]);
    }
    printf("\n");
}

// Function to test the SHA256 function
int main() {
    // Define the input string
    const char *str = "Hello, world!";

    // Calculate the SHA256 hash of the string
    unsigned char *hash = sha256((unsigned char *)str, strlen(str));

    // Print the hex string representation of the hash
    printf("SHA256 hash: ");
    print_hex(hash, SHA256_DIGEST_LENGTH);

    // Free the allocated memory
    free(hash);

    // Verify the hash
    const char *expected_hash = "7f83b163e082735c3f047b41e491f19b045f89cd8b7d7598768e14f1916f1a81";
    if (strcmp(hash, expected_hash) == 0) {
        printf("Hash verified successfully.\n");
    } else {
        printf("Hash verification failed.\n");
    }

    return 0;
}