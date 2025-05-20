//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 32
#define HASH_ALGORITHM "SHA-256"

// Function to generate hash
char* generateHash(char* input) {
    unsigned char hash[HASH_LENGTH];
    char hashString[HASH_LENGTH*2+1];
    hashString[HASH_LENGTH*2] = '\0';
    int i;

    // Convert input to lowercase
    for (i = 0; input[i]!= '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
    }

    // Generate hash using SHA-256 algorithm
    if (strcmp(HASH_ALGORITHM, "SHA-256") == 0) {
        SHA256((unsigned char*)input, strlen(input), hash);
    }

    // Convert hash to hexadecimal string
    for (i = 0; i < HASH_LENGTH; i++) {
        sprintf(&hashString[i*2], "%02x", hash[i]);
    }

    return strdup(hashString);
}

// Function to test hash function
void testHash() {
    char* input = "Hello, World! ";
    char* hash = generateHash(input);

    printf("Input: %s\n", input);
    printf("Hash: %s\n", hash);
}

int main() {
    srand(time(NULL));

    // Test hash function
    testHash();

    return 0;
}