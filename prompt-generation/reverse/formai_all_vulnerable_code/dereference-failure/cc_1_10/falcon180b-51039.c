//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 32

// Function to convert string to lowercase
void toLowerCase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to hash a string
char* hashString(char* str) {
    int len = strlen(str);
    char* hash = malloc(HASH_LENGTH + 1);
    memset(hash, 0, HASH_LENGTH + 1);
    for (int i = 0; i < len; i++) {
        hash[i % HASH_LENGTH] ^= str[i];
    }
    return hash;
}

// Function to compare two hashes
int compareHashes(char* hash1, char* hash2) {
    int len = strlen(hash1);
    for (int i = 0; i < len; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* input = "Hello, World!";
    toLowerCase(input);
    char* hash = hashString(input);
    printf("Hash: %s\n", hash);

    char* input2 = "Hello, World!";
    toLowerCase(input2);
    char* hash2 = hashString(input2);
    if (compareHashes(hash, hash2)) {
        printf("Hashes match!\n");
    } else {
        printf("Hashes do not match.\n");
    }

    return 0;
}