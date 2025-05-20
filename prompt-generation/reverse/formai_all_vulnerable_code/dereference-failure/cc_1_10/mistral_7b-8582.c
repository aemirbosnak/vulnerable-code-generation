//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 256
#define MAX_PLAIN_TEXT_LENGTH 1024
#define BLOCK_SIZE 8

typedef struct {
    unsigned char key[KEY_LENGTH];
    unsigned char iv[BLOCK_SIZE];
} SquidKey;

void generate_key(SquidKey *key) {
    FILE *fp;
    char filename[32] = "squid_key.bin";

    if ((fp = fopen(filename, "rb")) != NULL) {
        fread(key->key, sizeof(unsigned char), KEY_LENGTH, fp);
        fclose(fp);
    } else {
        srand(time(NULL));
        for (int i = 0; i < KEY_LENGTH; i++) {
            key->key[i] = (unsigned char)rand() % 256;
        }
        fp = fopen(filename, "wb");
        fwrite(key->key, sizeof(unsigned char), KEY_LENGTH, fp);
        fclose(fp);
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        key->iv[i] = (unsigned char)rand() % 256;
    }
}

void encrypt_block(unsigned char *plain_text, unsigned char *key, unsigned char *iv) {
    unsigned char xor_output[BLOCK_SIZE];

    for (int i = 0; i < BLOCK_SIZE; i++) {
        xor_output[i] = plain_text[i] ^ key[i % KEY_LENGTH] ^ iv[i];
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        plain_text[i] = xor_output[i];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <plain_text> <output_file>\n", argv[0]);
        return 1;
    }

    SquidKey key;
    generate_key(&key);

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file.");
        return 1;
    }

    unsigned char *plain_text = malloc(MAX_PLAIN_TEXT_LENGTH);
    size_t plain_text_size = fread(plain_text, sizeof(unsigned char), MAX_PLAIN_TEXT_LENGTH, input_file);
    fclose(input_file);

    unsigned char *cipher_text = malloc(MAX_PLAIN_TEXT_LENGTH);
    int blocks = plain_text_size / BLOCK_SIZE;

    for (int i = 0; i < blocks; i++) {
        encrypt_block(&plain_text[i * BLOCK_SIZE], key.key, key.iv);
        memcpy(&cipher_text[i * BLOCK_SIZE], key.iv, BLOCK_SIZE);
        memcpy(&cipher_text[i * BLOCK_SIZE + BLOCK_SIZE], &plain_text[i * BLOCK_SIZE], BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            cipher_text[i * BLOCK_SIZE + j + BLOCK_SIZE] = plain_text[i * BLOCK_SIZE + j] ^ key.key[j % KEY_LENGTH];
        }
    }

    FILE *output_file = fopen(argv[2], "wb");
    fwrite(cipher_text, sizeof(unsigned char), plain_text_size, output_file);
    fclose(output_file);

    free(plain_text);
    free(cipher_text);

    return 0;
}