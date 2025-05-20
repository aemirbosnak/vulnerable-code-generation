//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define a custom hash function using SHA-256
unsigned char* hash_function(const unsigned char* input, size_t input_length) {
    unsigned char* hash_value = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    if (hash_value == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for hash value.\n");
        return NULL;
    }

    SHA256_CTX sha256_context;
    SHA256_Init(&sha256_context);
    SHA256_Update(&sha256_context, input, input_length);
    SHA256_Final(hash_value, &sha256_context);

    return hash_value;
}

// Define a secure comparison function for constant-time string comparison
int secure_string_compare(const unsigned char* str1, const unsigned char* str2, size_t length) {
    unsigned char result = 0;
    for (size_t i = 0; i < length; i++) {
        result |= (str1[i] ^ str2[i]);
    }
    return (int)result;
}

int main() {
    // Define a secret key and plaintext message
    const unsigned char* secret_key = "MySecret";
    const unsigned char* plaintext = "Hello, world!";

    // Generate a hash value for the plaintext
    size_t plaintext_length = strlen((char*)plaintext);
    unsigned char* plaintext_hash = hash_function(plaintext, plaintext_length);
    if (plaintext_hash == NULL) {
        return EXIT_FAILURE;
    }

    // Perform a secure comparison to check if the secret key is correct
    const unsigned char* expected_hash = hash_function(secret_key, strlen((char*)secret_key));
    if (expected_hash == NULL) {
        return EXIT_FAILURE;
    }
    int comparison_result = secure_string_compare(plaintext_hash, expected_hash, SHA256_DIGEST_LENGTH);

    // Free the allocated memory
    free(plaintext_hash);
    free(expected_hash);

    // Print the comparison result
    if (comparison_result == 0) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return EXIT_SUCCESS;
}