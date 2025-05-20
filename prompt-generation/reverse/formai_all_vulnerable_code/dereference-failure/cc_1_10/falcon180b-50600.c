//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32

// Function to convert a string to uppercase
void to_uppercase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to compute the hash of a string
void hash(char* input, char* output) {
    int i = 0;
    int j = 0;
    int index = 0;

    // Convert the input string to uppercase
    to_uppercase(input);

    // Initialize the hash value
    unsigned int hash_value = 0xdeadbeef;

    // Compute the hash value
    while (input[i]) {
        hash_value ^= input[i];
        i++;
    }

    // Convert the hash value to a string
    char* hash_str = malloc(HASH_SIZE * sizeof(char));
    sprintf(hash_str, "%08X", hash_value);

    // Copy the hash value to the output string
    int hash_len = strlen(hash_str);
    while (hash_len < HASH_SIZE) {
        output[index] = '0';
        index++;
        hash_len++;
    }

    int str_len = strlen(hash_str);
    for (i = 0; i < str_len; i++) {
        output[index] = hash_str[i];
        index++;
    }

    free(hash_str);
}

int main() {
    char* input = "Hello, world! ";
    char* output = malloc(HASH_SIZE * sizeof(char));

    hash(input, output);

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    free(output);
    return 0;
}