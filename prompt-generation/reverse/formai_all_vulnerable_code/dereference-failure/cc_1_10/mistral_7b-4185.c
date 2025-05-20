//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define KEY_SIZE 25
#define BUF_SIZE 1024
#define CRC_POLY 0xEDB88320

typedef struct {
    uint32_t crc;
    char data[BUF_SIZE];
} crc_buf_t;

void encrypt(char *plaintext, char *key) {
    int i, j;
    char temp;

    for (i = 0; plaintext[i]; i++) {
        j = (isalpha(plaintext[i]) ? plaintext[i] - 'a' : plaintext[i]);
        if (j < 0 || j > 25) continue;

        temp = key[j];
        key[j] = key[plaintext[i] - 'a'];
        key[plaintext[i] - 'a'] = temp;

        plaintext[i] = key[j] + 'a';
    }
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    char temp;

    for (i = 0; ciphertext[i]; i++) {
        j = (isalpha(ciphertext[i]) ? ciphertext[i] - 'a' : ciphertext[i]);
        if (j < 0 || j > 25) continue;

        temp = key[j];
        key[j] = key[ciphertext[i] - 'a'];
        key[ciphertext[i] - 'a'] = temp;

        ciphertext[i] = key[j] + 'a';
    }
}

void crc_calculate(uint32_t *crc, char *buf, size_t len) {
    size_t i;
    uint8_t byte;

    *crc = 0xFFFFFFFF;

    for (i = 0; i < len; i++) {
        byte = buf[i];
        *crc = (*crc) ^ byte;

        for (; *crc & 0x80000000; *crc <<= 1) *crc ^= CRC_POLY;
    }
}

int main(int argc, char **argv) {
    char key[KEY_SIZE];
    char plaintext[BUF_SIZE];
    char ciphertext[BUF_SIZE];
    crc_buf_t crc_buf;

    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    strcpy(plaintext, argv[1]);

    for (int i = 0; i < KEY_SIZE; i++) key[i] = 'z' + (i % 26);

    encrypt(plaintext, key);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key);

    strcpy(crc_buf.data, plaintext);
    crc_calculate(&crc_buf.crc, crc_buf.data, strlen(plaintext));

    if (crc_buf.crc == 0xFFFFFFFF) {
        printf("Error: Invalid message!\n");
        return 1;
    }

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}