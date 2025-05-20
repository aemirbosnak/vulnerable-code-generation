//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define SHA256_DIGEST_LENGTH 32

// Custom hash function using SHA256
unsigned char* custom_hash(const unsigned char* input, size_t input_len, unsigned char* output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, input_len);
    SHA256_Final(output, &ctx);
    return output;
}

// Generate a random salt
unsigned char* generate_salt(size_t salt_len) {
    unsigned char* salt = malloc(salt_len);
    for (size_t i = 0; i < salt_len; i++) {
        salt[i] = rand() % 256;
    }
    return salt;
}

// Hash a password with a salt
unsigned char* hash_password(const unsigned char* password, size_t password_len, const unsigned char* salt, size_t salt_len, unsigned char* output) {
    unsigned char* salted_password = malloc(password_len + salt_len);
    memcpy(salted_password, password, password_len);
    memcpy(salted_password + password_len, salt, salt_len);
    return custom_hash(salted_password, password_len + salt_len, output);
}

// Verify a password against a hash
int verify_password(const unsigned char* password, size_t password_len, const unsigned char* hash, const unsigned char* salt) {
    unsigned char* hashed_password = malloc(SHA256_DIGEST_LENGTH);
    hash_password(password, password_len, salt, strlen((char*)salt), hashed_password);
    return memcmp(hash, hashed_password, SHA256_DIGEST_LENGTH) == 0;
}

int main() {
    // Example usage:
    const char* password = "my_password";
    const char* salt = "random_salt";
    unsigned char* hash = malloc(SHA256_DIGEST_LENGTH);
    hash_password((unsigned char*)password, strlen(password), (unsigned char*)salt, strlen(salt), hash);

    // Verify the password
    printf("Password is correct: %d\n", verify_password((unsigned char*)password, strlen(password), hash, (unsigned char*)salt));

    // Free allocated memory
    free(hash);

    return 0;
}