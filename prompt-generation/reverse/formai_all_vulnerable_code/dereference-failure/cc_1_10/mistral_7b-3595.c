//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define KEY_SIZE 10
#define BLOCK_SIZE 8
#define ALPHABET_SIZE 26
#define FILENAME_MAX_LENGTH 100

// Function to generate random key
void generate_key(char key[KEY_SIZE]) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 65 + rand() % ALPHABET_SIZE;
    }
    key[KEY_SIZE] = '\0';
}

// Function to encrypt a single block of text using XOR encryption
void xor_encrypt_block(char plaintext[BLOCK_SIZE], char key[KEY_SIZE], char ciphertext[BLOCK_SIZE]) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

// Function to encrypt the entire file using XOR encryption
void encrypt_file(char *input_filename, char *output_filename, char key[KEY_SIZE]) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");
    char plaintext[BLOCK_SIZE];
    char ciphertext[BLOCK_SIZE];
    char ch;
    int bytes_read;

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    generate_key(key);

    while ((bytes_read = fread(plaintext, sizeof(char), BLOCK_SIZE, input_file)) > 0) {
        xor_encrypt_block(plaintext, key, ciphertext);
        fwrite(ciphertext, sizeof(char), BLOCK_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

// Function to read user input and validate it
void get_input(char *filename, char *output_filename) {
    int i = 0;
    char c;

    printf("Enter input filename: ");
    while ((c = getchar()) != '\n') {
        filename[i] = c;
        i++;
        if (i >= FILENAME_MAX_LENGTH - 1) {
            printf("Filename too long.\n");
            exit(1);
        }
    }
    filename[i] = '\0';

    printf("Enter output filename: ");
    i = 0;
    while ((c = getchar()) != '\n') {
        output_filename[i] = c;
        i++;
        if (i >= FILENAME_MAX_LENGTH - 1) {
            printf("Filename too long.\n");
            exit(1);
        }
    }
    output_filename[i] = '\0';
}

int main() {
    srand(time(NULL));
    char input_filename[FILENAME_MAX_LENGTH];
    char output_filename[FILENAME_MAX_LENGTH];
    char key[KEY_SIZE];

    get_input(input_filename, output_filename);
    encrypt_file(input_filename, output_filename, key);

    printf("File encrypted successfully.\n");

    return 0;
}