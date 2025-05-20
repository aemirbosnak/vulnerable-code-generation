//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define ROUNDS 10

// Function to generate a random key
void generate_key(unsigned char key[KEY_SIZE]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a block of data
void encrypt(unsigned char plaintext[BLOCK_SIZE], unsigned char key[KEY_SIZE], unsigned char ciphertext[BLOCK_SIZE]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

// Function to decrypt a block of data
void decrypt(unsigned char ciphertext[BLOCK_SIZE], unsigned char key[KEY_SIZE], unsigned char plaintext[BLOCK_SIZE]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

// Function to encrypt a file
void encrypt_file(FILE *input_file, FILE *output_file, unsigned char key[KEY_SIZE]) {
    unsigned char buffer[BLOCK_SIZE];
    unsigned char ciphertext[BLOCK_SIZE];

    while (fread(buffer, BLOCK_SIZE, 1, input_file) > 0) {
        encrypt(buffer, key, ciphertext);
        fwrite(ciphertext, BLOCK_SIZE, 1, output_file);
    }
}

// Function to decrypt a file
void decrypt_file(FILE *input_file, FILE *output_file, unsigned char key[KEY_SIZE]) {
    unsigned char buffer[BLOCK_SIZE];
    unsigned char plaintext[BLOCK_SIZE];

    while (fread(buffer, BLOCK_SIZE, 1, input_file) > 0) {
        decrypt(buffer, key, plaintext);
        fwrite(plaintext, BLOCK_SIZE, 1, output_file);
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);

    FILE *input_file = fopen("input.txt", "rb");
    FILE *output_file = fopen("output.txt", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    return 0;
}