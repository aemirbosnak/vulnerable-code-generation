//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32
#define HASH_SIZE 64

// Function to convert a string to a number
unsigned long long str_to_num(char* str) {
    unsigned long long num = 0;
    int i = strlen(str) - 1;
    while (str[i]!= '\0') {
        num = num * 10 + str[i] - '0';
        i--;
    }
    return num;
}

// Function to generate a hash
char* generate_hash(char* input) {
    char* hash = malloc(HASH_SIZE);
    if (hash == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }
    unsigned long long num = str_to_num(input);
    for (int i = 0; i < HASH_SIZE; i++) {
        hash[i] = (char) (num % 256);
        num /= 256;
    }
    hash[HASH_SIZE - 1] = '\0';
    return hash;
}

// Function to compare two hashes
int compare_hashes(char* hash1, char* hash2) {
    if (strlen(hash1)!= HASH_SIZE || strlen(hash2)!= HASH_SIZE) {
        printf("Error: Hashes are not the same size\n");
        exit(1);
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* input = "Hello, world!";
    char* hash = generate_hash(input);
    printf("Input: %s\n", input);
    printf("Hash: %s\n", hash);
    printf("Hash size: %d\n", strlen(hash));
    if (compare_hashes(hash, hash)) {
        printf("Hashes match!\n");
    } else {
        printf("Hashes do not match!\n");
    }
    free(hash);
    return 0;
}