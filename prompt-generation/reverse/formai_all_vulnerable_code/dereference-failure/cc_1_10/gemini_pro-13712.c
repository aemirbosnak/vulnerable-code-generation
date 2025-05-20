//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Custom hash function using SHA256
unsigned char* hash(const char* input, int length) {
    unsigned char* hashValue = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, input, length);
    SHA256_Final(hashValue, &context);
    return hashValue;
}

// Verifies the integrity of a message using a hash function
int verify(const char* input, const unsigned char* expectedHash) {
    unsigned char* actualHash = hash(input, strlen(input));
    int result = memcmp(actualHash, expectedHash, SHA256_DIGEST_LENGTH);
    free(actualHash);
    return result == 0;
}

// Demonstrate the hash function and verification process
int main() {
    // Original message and its hash
    const char* message = "This is a secret message";
    unsigned char* hashValue = hash(message, strlen(message));

    // Corrupt the message
    char* corruptedMessage = malloc(strlen(message) + 1);
    strcpy(corruptedMessage, message);
    corruptedMessage[5] = 'X';

    // Verify the message with the original hash
    printf("Original message: %s\n", message);
    printf("Original hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hashValue[i]);
    }
    printf("\n");

    // Verify the corrupted message with the original hash
    int verificationResult = verify(corruptedMessage, hashValue);
    printf("Corrupted message: %s\n", corruptedMessage);
    printf("Verification result: %s\n", verificationResult ? "PASS" : "FAIL");

    free(hashValue);
    free(corruptedMessage);
    return 0;
}