//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 32
#define BLOCK_SIZE 64

typedef struct {
    unsigned char *data;
    int length;
} Hash;

// Initializes the hash object
void initHash(Hash *hash) {
    hash->data = (unsigned char *)malloc(SIZE);
    hash->length = 0;
    memset(hash->data, 0, SIZE);
}

// Updates the hash object with new data
void updateHash(Hash *hash, unsigned char *data, int length) {
    int i;
    for (i = 0; i < length; i++) {
        hash->data[hash->length / 8] ^= data[i];
        hash->length++;
        if (hash->length == SIZE) {
            hash->length = 0;
            memset(hash->data, 0, SIZE);
        }
    }
}

// Finalizes the hash and returns the result as a string
char *finalizeHash(Hash *hash) {
    char *result = (char *)malloc(2 * SIZE + 1);
    int i;
    for (i = 0; i < SIZE; i++) {
        sprintf(result + (i * 2), "%02x", hash->data[i]);
    }
    free(hash->data);
    return result;
}

// Computes the SHA-256 hash of a given string
char *sha256(char *message) {
    Hash hash;
    initHash(&hash);
    updateHash(&hash, (unsigned char *)message, strlen(message));
    return finalizeHash(&hash);
}

// Main function to test the hash function
int main() {
    char *message = "Hello, world!";
    char *hash = sha256(message);
    printf("Message: %s\n", message);
    printf("SHA-256 hash: %s\n", hash);
    free(hash);
    return 0;
}