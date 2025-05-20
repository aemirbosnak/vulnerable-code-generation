//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

void encrypt(char *data, char *key) {
    int i, j;
    unsigned char plaintext[BLOCK_SIZE];
    unsigned char ciphertext[BLOCK_SIZE];
    unsigned char key_expanded[KEY_SIZE * BLOCK_SIZE];
    unsigned char round_key[BLOCK_SIZE];

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            key_expanded[i * BLOCK_SIZE + j] = key[i] ^ 0xAA;
        }
    }

    int data_length = strlen(data);
    int num_blocks = data_length / BLOCK_SIZE;

    for (i = 0; i < num_blocks; i++) {
        memcpy(plaintext, data + i * BLOCK_SIZE, BLOCK_SIZE);
        memcpy(ciphertext, plaintext, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            round_key[j] = key_expanded[i * BLOCK_SIZE + j];
        }

        for (j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[j] ^= round_key[j];
        }

        memcpy(data + i * BLOCK_SIZE, ciphertext, BLOCK_SIZE);
    }
}

void decrypt(char *data, char *key) {
    encrypt(data, key);
}

int main() {
    char data[] = "Hello, world! ";
    char key[] = "mysecretkey";

    encrypt(data, key);

    printf("Encrypted data: %s\n", data);
    printf("Decrypted data: %s\n", data);

    return 0;
}