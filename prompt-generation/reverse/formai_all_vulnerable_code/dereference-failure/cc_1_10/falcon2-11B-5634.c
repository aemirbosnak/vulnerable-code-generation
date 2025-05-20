//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define KEY_SIZE_HALF 8
#define MSG_SIZE 24
#define S_BOX_SIZE 8

void xor(unsigned char *output, unsigned char *input1, unsigned char *input2, int size);

void encrypt(unsigned char key[], unsigned char *plaintext, unsigned char *ciphertext, int block_count);

void decrypt(unsigned char key[], unsigned char *ciphertext, unsigned char *plaintext, int block_count);

int main() {
    unsigned char key[KEY_SIZE] = {0x1b, 0x2a, 0x34, 0x41, 0x42, 0x43, 0x4a, 0x4b, 0x3f, 0x3d, 0x3b, 0x3e, 0x3a, 0x3c, 0x36, 0x37};
    unsigned char plaintext[MSG_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    unsigned char ciphertext[MSG_SIZE];

    encrypt(key, plaintext, ciphertext, MSG_SIZE / BLOCK_SIZE);
    printf("Ciphertext: ");
    for (int i = 0; i < MSG_SIZE; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    decrypt(key, ciphertext, plaintext, MSG_SIZE / BLOCK_SIZE);
    printf("Plaintext: ");
    for (int i = 0; i < MSG_SIZE; i++) {
        printf("%c ", plaintext[i]);
    }
    printf("\n");

    return 0;
}

void xor(unsigned char *output, unsigned char *input1, unsigned char *input2, int size) {
    int i;
    for (i = 0; i < size; i++) {
        output[i] = input1[i] ^ input2[i];
    }
}

void encrypt(unsigned char key[], unsigned char *plaintext, unsigned char *ciphertext, int block_count) {
    int i, j;
    for (i = 0; i < block_count; i++) {
        unsigned char key_block[KEY_SIZE] = {0};
        for (j = 0; j < KEY_SIZE; j++) {
            key_block[j] = key[j * 2 + KEY_SIZE_HALF];
        }

        xor(ciphertext + i * BLOCK_SIZE, plaintext + i * BLOCK_SIZE, key_block, KEY_SIZE);
        for (j = 0; j < S_BOX_SIZE; j++) {
            ciphertext[i * BLOCK_SIZE + j] ^= key_block[j];
        }
    }
}

void decrypt(unsigned char key[], unsigned char *ciphertext, unsigned char *plaintext, int block_count) {
    int i, j;
    for (i = 0; i < block_count; i++) {
        unsigned char key_block[KEY_SIZE] = {0};
        for (j = 0; j < KEY_SIZE; j++) {
            key_block[j] = key[j * 2 + KEY_SIZE_HALF];
        }

        xor(plaintext + i * BLOCK_SIZE, ciphertext + i * BLOCK_SIZE, key_block, KEY_SIZE);
        for (j = 0; j < S_BOX_SIZE; j++) {
            ciphertext[i * BLOCK_SIZE + j] ^= key_block[j];
        }
    }
}