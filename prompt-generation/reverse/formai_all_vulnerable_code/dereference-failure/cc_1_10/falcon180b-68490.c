//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(FILE *input_file, FILE *output_file) {
    char buffer[BLOCK_SIZE];
    char key[strlen(KEY)];
    int i, j;

    for (i = 0; i < strlen(KEY); i++) {
        key[i] = tolower(KEY[i]);
    }

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input_file)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = buffer[i] ^ key[i % strlen(KEY)];
        }

        fwrite(buffer, sizeof(char), BLOCK_SIZE, output_file);
    }
}

void decrypt(FILE *input_file, FILE *output_file) {
    char buffer[BLOCK_SIZE];
    char key[strlen(KEY)];
    int i, j;

    for (i = 0; i < strlen(KEY); i++) {
        key[i] = tolower(KEY[i]);
    }

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input_file)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = buffer[i] ^ key[i % strlen(KEY)];
        }

        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        fwrite(buffer, sizeof(char), BLOCK_SIZE, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt/decrypt] [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(fopen(argv[2], "rb"), fopen(argv[3], "wb"));
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(fopen(argv[2], "rb"), fopen(argv[3], "wb"));
    } else {
        printf("Invalid operation. Use either 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    return 0;
}