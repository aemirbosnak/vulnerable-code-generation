//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

const unsigned char encrypt_key[BLOCK_SIZE] = {0x4A,0x36,0x99,0x8F,0x21,0x0F,0xAC,0xE7,0x3D,0x70,0x51,0x9A,0x05,0x26,0xC8,0xD3};

void xor_encrypt(unsigned char *plaintext, int plaintext_length, unsigned char *key, int key_length, unsigned char *encrypted_text) {

    int block_number = plaintext_length / BLOCK_SIZE;
    int last_block_length = plaintext_length % BLOCK_SIZE;
    unsigned char last_block_padding = BLOCK_SIZE - last_block_length;

    for (int i = 0; i < block_number; i++) {

        unsigned char block_to_encrypt[BLOCK_SIZE];
        memcpy(block_to_encrypt, plaintext + (i * BLOCK_SIZE), BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            block_to_encrypt[j] ^= key[j % key_length]; // XOR encryption
        }

        memcpy(encrypted_text + (i * BLOCK_SIZE), block_to_encrypt, BLOCK_SIZE);
    }

    if (last_block_length != 0) {

        unsigned char last_block[BLOCK_SIZE];
        memcpy(last_block, plaintext + (block_number * BLOCK_SIZE), last_block_length);

        for (int i = 0; i < last_block_padding; i++) {
            last_block[last_block_length + i] = last_block_padding;
        }

        for (int i = 0; i < BLOCK_SIZE; i++) {
            last_block[i] ^= key[i % key_length]; // XOR encryption
        }

        memcpy(encrypted_text + (block_number * BLOCK_SIZE), last_block, BLOCK_SIZE);
    }
}

void xor_decrypt(unsigned char *encrypted_text, int encrypted_text_length, unsigned char *key, int key_length, unsigned char *decrypted_text) {

    int block_number = encrypted_text_length / BLOCK_SIZE;
    int last_block_length = encrypted_text[encrypted_text_length - 1];
    int last_block_padding = BLOCK_SIZE - last_block_length;

    for (int i = 0; i < block_number; i++) {

        unsigned char block_to_decrypt[BLOCK_SIZE];
        memcpy(block_to_decrypt, encrypted_text + (i * BLOCK_SIZE), BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            block_to_decrypt[j] ^= key[j % key_length]; // XOR decryption
        }

        memcpy(decrypted_text + (i * BLOCK_SIZE), block_to_decrypt, BLOCK_SIZE);
    }

    if (last_block_length != 0) {

        unsigned char last_block[BLOCK_SIZE];
        memcpy(last_block, encrypted_text + (block_number * BLOCK_SIZE), BLOCK_SIZE);

        for (int i = 0; i < BLOCK_SIZE; i++) {
            last_block[i] ^= key[i % key_length]; // XOR decryption
        }

        memcpy(decrypted_text + (block_number * BLOCK_SIZE), last_block, last_block_length);
    }
}

int main() {

    unsigned char plaintext[] = "This is a test message. It should be encrypted and then decrypted.";
    int plaintext_length = strlen(plaintext);

    unsigned char encrypted_text[plaintext_length];
    xor_encrypt(plaintext, plaintext_length, (unsigned char *) encrypt_key, BLOCK_SIZE, encrypted_text);

    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted Text: ");

    for (int i = 0; i < plaintext_length; i++) {
        printf("%02x", encrypted_text[i]);
    }

    printf("\n");

    unsigned char decrypted_text[plaintext_length];
    xor_decrypt(encrypted_text, plaintext_length, (unsigned char *) encrypt_key, BLOCK_SIZE, decrypted_text);

    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}