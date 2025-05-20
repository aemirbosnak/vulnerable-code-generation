//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

#define ROTATE_LEFT(x, y) (((x) << (y)) | ((x)  (32 - (y))))
#define ROTATE_RIGHT(x, y) (((x)  (y)) | ((x) << (32 - (y))))

void encrypt(unsigned char *input, unsigned char *key, unsigned char *output) {
    AES_KEY aes_key;
    int i;
    unsigned char *p = (unsigned char*)malloc(BLOCK_SIZE * 2);
    AES_set_encrypt_key((unsigned char*)key, KEY_SIZE, &aes_key);
    AES_encrypt((unsigned char*)input, p, &aes_key);
    for (i = 0; i < BLOCK_SIZE; i++) {
        output[i] = p[i];
        output[i + BLOCK_SIZE] = p[i];
    }
    free(p);
}

void decrypt(unsigned char *input, unsigned char *key, unsigned char *output) {
    AES_KEY aes_key;
    int i;
    unsigned char *p = (unsigned char*)malloc(BLOCK_SIZE * 2);
    AES_set_decrypt_key((unsigned char*)key, KEY_SIZE, &aes_key);
    AES_decrypt((unsigned char*)input, p, &aes_key);
    for (i = 0; i < BLOCK_SIZE; i++) {
        output[i] = p[i];
        output[i + BLOCK_SIZE] = p[i];
    }
    free(p);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <key> <output_file>\n", argv[0]);
        return 1;
    }
    unsigned char input[10000], key[KEY_SIZE], output[10000];
    unsigned char *p;
    FILE *fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }
    fread(input, 1, 10000, fp);
    fclose(fp);
    encrypt(input, key, output);
    fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        printf("Failed to open %s\n", argv[3]);
        return 1;
    }
    fwrite(output, 1, 10000, fp);
    fclose(fp);
    return 0;
}