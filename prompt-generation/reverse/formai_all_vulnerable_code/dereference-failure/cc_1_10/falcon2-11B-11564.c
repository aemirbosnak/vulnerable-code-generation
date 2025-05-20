//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 16

void encrypt(char* key, char* plaintext, char* ciphertext) {
    int i;
    char c;

    // Key expansion
    for (i = 0; i < BLOCK_SIZE; i++) {
        c = key[i % (BLOCK_SIZE / 2)] + key[i % (BLOCK_SIZE / 2) + BLOCK_SIZE / 2];
        key[i] = c;
    }

    // Encryption loop
    for (i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        int j;
        char* block = malloc(BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] = plaintext[i + j];
        }

        // Substitution
        for (j = 0; j < BLOCK_SIZE; j++) {
            int k = (int) block[j];
            k = k + c - 'A';
            k = k % 26;
            k = k + 'A';
            block[j] = k;
        }

        // Permutation
        for (j = 0; j < BLOCK_SIZE; j++) {
            int temp = block[j];
            int i = j;

            while (i < BLOCK_SIZE) {
                int k = block[i];
                block[i] = block[i + 1];
                i++;
            }

            block[i] = temp;
        }

        // XOR
        for (j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[i + j] = 'A' + (block[j] ^ ciphertext[i + j]);
        }

        free(block);
    }
}

int main() {
    char key[BLOCK_SIZE] = "secretkey";
    char plaintext[100] = "Hello, world!";
    char ciphertext[100];

    encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}