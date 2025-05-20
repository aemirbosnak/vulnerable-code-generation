//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void encrypt_block(unsigned char *block, unsigned char key[]) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] = block[i] ^ key[i % KEY_LENGTH];
    }
}

void randomize_key(unsigned char key[]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = (unsigned char) rand() % 256;
    }
}

void print_hex(unsigned char *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <plaintext file> <output file> \n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");

    if (!input || !output) {
        perror("Error opening files");
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];
    unsigned char key[KEY_LENGTH];

    randomize_key(key);

    while (fread(buffer, sizeof(buffer), 1, input)) {
        encrypt_block(buffer, key);
        fwrite(buffer, sizeof(buffer), 1, output);
    }

    fclose(input);
    fclose(output);

    print_hex(key, KEY_LENGTH);
    printf("Key:\n");

    return 0;
}