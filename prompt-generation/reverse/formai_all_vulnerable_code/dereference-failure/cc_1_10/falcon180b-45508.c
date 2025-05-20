//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// XOR the key with the plaintext to get the ciphertext
void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == KEY_SIZE) {
            j = 0;
        }
        ciphertext[i] = plaintext[i] ^ key[j];
    }
}

// XOR the key with the ciphertext to get the plaintext
void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if (j == KEY_SIZE) {
            j = 0;
        }
        plaintext[i] = ciphertext[i] ^ key[j];
    }
}

// Read in the key from a file
char* read_key(FILE* file) {
    char* key = malloc(KEY_SIZE + 1);
    fread(key, KEY_SIZE, 1, file);
    key[KEY_SIZE] = '\0';
    return key;
}

// Read in the plaintext from a file
char* read_plaintext(FILE* file) {
    char* plaintext = malloc(BLOCK_SIZE * 2 + 1);
    fread(plaintext, BLOCK_SIZE, 2, file);
    plaintext[BLOCK_SIZE * 2] = '\0';
    return plaintext;
}

// Write the ciphertext to a file
void write_ciphertext(FILE* file, char* ciphertext) {
    fwrite(ciphertext, strlen(ciphertext), 1, file);
}

int main() {
    FILE* input_file = fopen("input.txt", "rb");
    FILE* output_file = fopen("output.txt", "wb");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char* key = read_key(input_file);
    char* plaintext = read_plaintext(input_file);

    char* ciphertext = malloc(strlen(plaintext) + 1);
    encrypt(plaintext, key, ciphertext);

    write_ciphertext(output_file, ciphertext);

    fclose(input_file);
    fclose(output_file);

    return 0;
}