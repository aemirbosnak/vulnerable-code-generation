//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_LENGTH 32
#define HASH_ROUNDS 10000

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
}

// Function to calculate the hash of a string
char* hashString(char* str) {
    int len = strlen(str);
    char* hash = (char*) malloc(HASH_LENGTH * sizeof(char));
    int i, j;

    // Convert the string to lowercase
    toLowerCase(str);

    // Initialize the hash value
    for (i = 0; i < HASH_LENGTH; i++) {
        hash[i] = '0';
    }

    // Perform the hash rounds
    for (i = 0; i < HASH_ROUNDS; i++) {
        for (j = 0; j < len; j++) {
            hash[j % HASH_LENGTH] ^= str[j];
        }
    }

    return hash;
}

// Function to compare two hashes
int compareHashes(char* hash1, char* hash2) {
    int i;
    for (i = 0; i < HASH_LENGTH; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* input1 = "Hello, world! ";
    char* input2 = "Hello, world! ";
    char* hash1 = hashString(input1);
    char* hash2 = hashString(input2);

    if (compareHashes(hash1, hash2)) {
        printf("The strings are the same! \n");
    } else {
        printf("The strings are different. \n");
    }

    free(hash1);
    free(hash2);

    return 0;
}