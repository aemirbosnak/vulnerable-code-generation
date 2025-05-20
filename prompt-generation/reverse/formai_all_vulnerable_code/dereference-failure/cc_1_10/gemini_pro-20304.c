//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random number between 0 and 255
unsigned char generateRandomNumber() {
    return rand() % 256;
}

// Function to generate a salt of a given length
unsigned char *generateSalt(int length) {
    unsigned char *salt = malloc(length);
    for (int i = 0; i < length; i++) {
        salt[i] = generateRandomNumber();
    }
    return salt;
}

// Function to hash a password using a given salt
unsigned char *hashPassword(const char *password, unsigned char *salt) {
    int passwordLength = strlen(password);
    int saltLength = strlen((char *)salt);

    // Create a buffer to store the concatenated password and salt
    unsigned char *buffer = malloc(passwordLength + saltLength);

    // Copy the password and salt into the buffer
    memcpy(buffer, password, passwordLength);
    memcpy(buffer + passwordLength, salt, saltLength);

    // Create a SHA-256 hash of the buffer
    unsigned char *hash = malloc(32);
    SHA256((unsigned char *)buffer, passwordLength + saltLength, hash);

    // Free the buffer
    free(buffer);

    // Return the hash
    return hash;
}

// Function to compare two hashes
int compareHashes(unsigned char *hash1, unsigned char *hash2) {
    return memcmp(hash1, hash2, 32) == 0;
}

// Function to print a hash
void printHash(unsigned char *hash) {
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random salt
    unsigned char *salt = generateSalt(16);

    // Hash a password using the salt
    unsigned char *hash = hashPassword("password", salt);

    // Print the hash
    printf("Hash: ");
    printHash(hash);

    // Compare the hash to a known hash
    int result = compareHashes(hash, (unsigned char *)"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");

    // Print the result
    if (result) {
        printf("Hashes match!\n");
    } else {
        printf("Hashes do not match!\n");
    }

    // Free the salt and hash
    free(salt);
    free(hash);

    return 0;
}