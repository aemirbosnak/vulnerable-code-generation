//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define NUM_ROUNDS 10

struct SHANNON_SBOX {
    unsigned char input;
    unsigned char output;
};

const struct SHANNON_SBOX sbox[16] = {
    {0x00, 0x01},
    {0x01, 0x03},
    {0x02, 0x07},
    {0x03, 0x0E},
    {0x04, 0x30},
    {0x05, 0x5C},
    {0x06, 0xAA},
    {0x07, 0xF4},
    {0x08, 0x01},
    {0x09, 0x03},
    {0x0A, 0x07},
    {0x0B, 0x0E},
    {0x0C, 0x30},
    {0x0D, 0x5C},
    {0x0E, 0xAA},
    {0x0F, 0xF4}
};

void shannon_encrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    int i, round;
    unsigned char temp;

    for (round = 0; round < NUM_ROUNDS; round++) {
        for (i = 0; i < 16; i++) {
            temp = sbox[key[i] ^ plaintext[i]].output;
            ciphertext[i] = temp;
        }
        for (i = 0; i < 16; i++) {
            key[i] = sbox[key[i] ^ ciphertext[i]].output;
        }
    }
}

void shannon_decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *plaintext) {
    int i, round;
    unsigned char temp;

    for (round = NUM_ROUNDS - 1; round >= 0; round--) {
        for (i = 15; i >= 0; i--) {
            key[i] = sbox[key[i] ^ ciphertext[i]].output;
        }
        for (i = 15; i >= 0; i--) {
            temp = sbox[key[i] ^ plaintext[i]].output;
            ciphertext[i] = temp;
        }
    }
}

int main(int argc, char **argv) {
    unsigned char key[MAX_KEY_SIZE];
    unsigned char plaintext[16];
    unsigned char ciphertext[16];
    int i;

    if (argc != 4) {
        printf("Usage: %s key plaintext ciphertext\n", argv[0]);
        return 1;
    }

    if (strlen(argv[1]) > MAX_KEY_SIZE) {
        printf("Error: key is too long\n");
        return 1;
    }

    if (strlen(argv[2]) != 16) {
        printf("Error: plaintext must be 16 bytes long\n");
        return 1;
    }

    if (strlen(argv[3]) != 16) {
        printf("Error: ciphertext must be 16 bytes long\n");
        return 1;
    }

    strcpy(key, argv[1]);
    strcpy(plaintext, argv[2]);
    strcpy(ciphertext, argv[3]);

    printf("Key: ");
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        printf("%02X", key[i]);
    }
    printf("\n");

    printf("Plaintext: ");
    for (i = 0; i < 16; i++) {
        printf("%02X", plaintext[i]);
    }
    printf("\n");

    shannon_encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: ");
    for (i = 0; i < 16; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    shannon_decrypt(key, ciphertext, plaintext);

    printf("Decrypted Plaintext: ");
    for (i = 0; i < 16; i++) {
        printf("%02X", plaintext[i]);
    }
    printf("\n");

    return 0;
}