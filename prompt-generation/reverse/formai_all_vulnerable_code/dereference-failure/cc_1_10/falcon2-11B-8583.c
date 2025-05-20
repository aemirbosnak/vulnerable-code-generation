//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate SHA-256 hash
unsigned char* sha256(const char* message, int len) {
    unsigned char hash[64];
    unsigned char digest[16];
    unsigned char temp[64];

    // Initializing the digest
    memset(digest, 0, sizeof(digest));

    // Initializing the temporary array
    memset(temp, 0, sizeof(temp));

    // Loop through the message
    int i = 0;
    while (i < len) {
        int index = i % 64;
        temp[index] = message[i];
        i++;
    }

    // Looping through the temporary array
    for (i = 0; i < 64; i++) {
        int index = i % 16;
        digest[index] = temp[i];
    }

    // Converting the digest to hexadecimal string
    char hex_digest[33];
    for (i = 0; i < 16; i++) {
        sprintf(hex_digest + i * 2, "%02x", digest[i]);
    }

    // Converting the hexadecimal string to byte array
    unsigned char* result = malloc(sizeof(unsigned char) * 32);
    for (i = 0; i < 16; i++) {
        result[i] = hex_digest[i * 2] - '0';
        result[i + 16] = hex_digest[i * 2 + 1] - '0';
    }

    return result;
}

int main() {
    const char* message = "Hello, World!";
    int len = strlen(message);
    unsigned char* hash = sha256(message, len);
    printf("SHA-256 Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}