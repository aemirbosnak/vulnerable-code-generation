//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define KEY_SIZE 10
#define BLOCK_SIZE 8
#define FILE_MODE "r+b"

typedef struct {
    char char_key[KEY_SIZE];
    int number_key;
    bool boolean_key;
} Key;

void encrypt_block(FILE *fp, char block[BLOCK_SIZE], Key key);
void decrypt_block(FILE *fp, char block[BLOCK_SIZE], Key key);

void generate_key(Key *key);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_fp = fopen(argv[1], FILE_MODE);
    FILE *output_fp = fopen(argv[2], "wb");

    if (!input_fp || !output_fp) {
        perror("Error opening file.");
        return 1;
    }

    Key input_key, output_key;
    generate_key(&input_key);
    generate_key(&output_key);

    char buffer[BLOCK_SIZE];

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input_fp) > 0) {
        encrypt_block(output_fp, buffer, input_key);
    }

    fclose(input_fp);
    fclose(output_fp);

    free(input_key.char_key);
    free(output_key.char_key);

    printf("Encryption completed.\n");

    return 0;
}

void generate_key(Key *key) {
    key->boolean_key = rand() % 2;
    key->number_key = rand() % 100;

    for (int i = 0; i < KEY_SIZE; i++) {
        key->char_key[i] = (char)rand() % 128;
    }
}

void encrypt_block(FILE *fp, char block[BLOCK_SIZE], Key key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = (char)(block[i] ^ key.char_key[i % KEY_SIZE] ^ key.number_key);
        if (key.boolean_key) {
            block[i] = (char)~block[i];
        }
    }

    fwrite(block, sizeof(char), BLOCK_SIZE, fp);
}

void decrypt_block(FILE *fp, char block[BLOCK_SIZE], Key key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = (char)(block[i] ^ key.char_key[i % KEY_SIZE] ^ ~key.number_key);
        if (!key.boolean_key) {
            block[i] = (char)~block[i];
        }
    }

    fwrite(block, sizeof(char), BLOCK_SIZE, fp);
}