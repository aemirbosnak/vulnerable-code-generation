//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void generate_key(byte key[], int key_size) {
    for(int i=0; i<key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(byte input[], byte output[], byte key[], int input_size) {
    for(int i=0; i<input_size; i++) {
        output[i] = input[i] ^ key[i % 16];
    }
}

void decrypt(byte input[], byte output[], byte key[], int input_size) {
    for(int i=0; i<input_size; i++) {
        output[i] = input[i] ^ key[i % 16];
    }
}

int main() {
    int block_size = 16;

    byte *input = (byte *)malloc(sizeof(byte) * block_size);
    byte *output = (byte *)malloc(sizeof(byte) * block_size);
    byte *decrypted = (byte *)malloc(sizeof(byte) * block_size);
    byte *key = (byte *)malloc(sizeof(byte) * block_size);

    generate_key(key, block_size);

    printf("Key: ");
    for(int i=0; i<block_size; i++) {
        printf("%02X", key[i]);
    }

    printf("\nEnter input (16 bytes): ");
    scanf("%s", input);

    encrypt(input, output, key, block_size);

    printf("Encrypted output: ");
    for(int i=0; i<block_size; i++) {
        printf("%02X", output[i]);
    }

    decrypt(output, decrypted, key, block_size);

    printf("\nDecrypted output: %s", decrypted);

    free(input);
    free(output);
    free(decrypted);
    free(key);

    return 0;
}