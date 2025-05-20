//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

void encrypt(unsigned char* input, unsigned char* key, unsigned char* output) {
    int i;
    unsigned char temp[BLOCK_SIZE];

    for (i = 0; i < BLOCK_SIZE; i++) {
        temp[i] = input[i];
    }

    for (i = 0; i < KEY_SIZE; i++) {
        temp[i] ^= key[i];
    }

    for (i = 0; i < BLOCK_SIZE; i++) {
        output[i] = temp[i];
    }
}

void decrypt(unsigned char* input, unsigned char* key, unsigned char* output) {
    int i;
    unsigned char temp[BLOCK_SIZE];

    for (i = 0; i < BLOCK_SIZE; i++) {
        temp[i] = input[i];
    }

    for (i = 0; i < KEY_SIZE; i++) {
        temp[i] ^= key[i];
    }

    for (i = 0; i < BLOCK_SIZE; i++) {
        output[i] = temp[i];
    }
}

int main() {
    unsigned char input[] = "This is a secret message.";
    unsigned char key[] = "mysecretkey";
    unsigned char output[strlen(input) + 1];
    int i;

    encrypt(input, key, output);

    printf("Encrypted message: ");
    for (i = 0; i < strlen(output); i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    decrypt(output, key, input);

    printf("Decrypted message: ");
    for (i = 0; i < strlen(input); i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}