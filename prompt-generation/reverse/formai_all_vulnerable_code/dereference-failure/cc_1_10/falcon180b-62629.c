//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32
#define CHARSET_SIZE 64

// Convert a string to uppercase
void strtoupper(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Calculate the hash of a string
char* hash(char* str) {
    // Convert the input string to uppercase
    strtoupper(str);

    // Initialize the hash value to zero
    unsigned char hash[HASH_SIZE] = {0};

    // Initialize the index to zero
    int index = 0;

    // Iterate over each character in the input string
    while (*str) {
        // Calculate the index based on the current character
        int c = *str % CHARSET_SIZE;

        // XOR the current character with the previous hash value
        hash[index] ^= c;

        // Increment the index
        index++;

        // Move to the next character in the input string
        str++;
    }

    // Convert the hash to a string representation
    char hash_str[HASH_SIZE * 2 + 1];
    sprintf(hash_str, "%02x", hash[0]);
    for (int i = 1; i < HASH_SIZE; i++) {
        sprintf(hash_str + (i * 2), "%02x", hash[i]);
    }

    // Add a terminating null character
    hash_str[HASH_SIZE * 2] = '\0';

    // Return the hash string
    return hash_str;
}

int main() {
    // Test the hash function
    char* input = "Hello, world!";
    char* hash_str = hash(input);
    printf("Input: %s\n", input);
    printf("Hash: %s\n", hash_str);

    return 0;
}