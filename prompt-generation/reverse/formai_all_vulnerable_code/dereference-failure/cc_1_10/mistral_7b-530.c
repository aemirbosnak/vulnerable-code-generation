//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8
#define SCHEDULE_LENGTH (KEY_LENGTH * 2)

typedef unsigned char byte;
typedef unsigned int uint;

byte glitter_key[KEY_LENGTH];
byte glitter_schedule[SCHEDULE_LENGTH];

void glitter_setup(byte *key) {
    for (int i = 0; i < KEY_LENGTH; i++)
        glitter_key[i] = key[i];

    for (int i = 0; i < SCHEDULE_LENGTH; i++) {
        byte left = i / 2;
        byte right = i % 2;

        glitter_schedule[i] = key[left] ^ key[right];
    }
}

void glitter_encrypt(byte *plaintext, byte *ciphertext) {
    for (int i = 0; i < strlen(plaintext) / BLOCK_SIZE; i++) {
        byte left_block[BLOCK_SIZE];
        byte right_block[BLOCK_SIZE];

        memcpy(left_block, plaintext + i * BLOCK_SIZE, BLOCK_SIZE);
        memcpy(right_block, plaintext + (i + 1) * BLOCK_SIZE, BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            byte temp = left_block[j] ^ glitter_schedule[i * BLOCK_SIZE + j];
            left_block[j] = right_block[j] ^ glitter_key[j];
            right_block[j] = temp;
        }

        memcpy(ciphertext + i * BLOCK_SIZE, left_block, BLOCK_SIZE);
        memcpy(ciphertext + (i + 1) * BLOCK_SIZE, right_block, BLOCK_SIZE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <key> <plaintext>\n", argv[0]);
        return 1;
    }

    glitter_setup((byte *)argv[1]);

    byte *plaintext = (byte *)argv[2];
    byte *ciphertext = malloc(strlen(plaintext) / BLOCK_SIZE * 2 * BLOCK_SIZE);

    glitter_encrypt(plaintext, ciphertext);

    printf("Key: ");
    for (int i = 0; i < KEY_LENGTH; i++)
        printf("%02X ", glitter_key[i]);
    printf("\n");

    printf("Plaintext: %s\n", plaintext);

    printf("Ciphertext:\n");
    for (int i = 0; i < strlen(plaintext) / BLOCK_SIZE * 2; i++) {
        printf("%02X ", ciphertext[i * BLOCK_SIZE]);
        printf("%02X ", ciphertext[i * BLOCK_SIZE + BLOCK_SIZE]);
    }

    free(ciphertext);

    return 0;
}