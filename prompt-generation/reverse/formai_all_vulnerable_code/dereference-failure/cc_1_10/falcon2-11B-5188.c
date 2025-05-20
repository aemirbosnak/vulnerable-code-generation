//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64

// Encrypt function
void encrypt(char *input, char *output, int key) {
    int i;
    char *block = (char*) malloc(BLOCK_SIZE);

    for (i = 0; i < strlen(input); i += BLOCK_SIZE) {
        memcpy(block, (input + i), BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = (char)(block[j] + key);
            if (block[j] > 'Z') {
                block[j] = 'A' - 1;
            }
            else if (block[j] < 'A') {
                block[j] = 'Z' + 1;
            }
        }
        memcpy(output, block, BLOCK_SIZE);
        output += BLOCK_SIZE;
    }

    free(block);
}

// Decrypt function
void decrypt(char *input, char *output, int key) {
    int i;
    char *block = (char*) malloc(BLOCK_SIZE);

    for (i = 0; i < strlen(input); i += BLOCK_SIZE) {
        memcpy(block, (input + i), BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = (char)(block[j] - key);
            if (block[j] > 'Z') {
                block[j] = 'A' - 1;
            }
            else if (block[j] < 'A') {
                block[j] = 'Z' + 1;
            }
        }
        memcpy(output, block, BLOCK_SIZE);
        output += BLOCK_SIZE;
    }

    free(block);
}

int main() {
    char input[] = "Hello World!";
    char output[strlen(input)];
    int key = 3;

    encrypt(input, output, key);
    printf("Encrypted: %s\n", output);

    decrypt(output, output, key);
    printf("Decrypted: %s\n", output);

    return 0;
}