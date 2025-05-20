//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(char* plaintext, int plaintext_len, char* ciphertext) {
    int i, j;
    char key[16];
    strncpy(key, KEY, BLOCK_SIZE);

    for (i = 0; i < plaintext_len; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < plaintext_len; j++) {
            char ch = plaintext[i + j];
            ch ^= key[j % BLOCK_SIZE];
            ciphertext[i + j] = ch;
        }
    }
}

void decrypt(char* ciphertext, int ciphertext_len, char* plaintext) {
    int i, j;
    char key[16];
    strncpy(key, KEY, BLOCK_SIZE);

    for (i = 0; i < ciphertext_len; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < ciphertext_len; j++) {
            char ch = ciphertext[i + j];
            ch ^= key[j % BLOCK_SIZE];
            plaintext[i + j] = ch;
        }
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    int input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char* input_buffer = malloc(input_file_size + 1);
    if (input_buffer == NULL) {
        printf("Error allocating memory for input buffer.\n");
        exit(1);
    }

    fread(input_buffer, input_file_size, 1, input_file);
    fclose(input_file);
    input_buffer[input_file_size] = '\0';

    char* output_buffer = malloc(input_file_size + 1);
    if (output_buffer == NULL) {
        printf("Error allocating memory for output buffer.\n");
        exit(1);
    }

    encrypt(input_buffer, input_file_size, output_buffer);

    FILE* output_file = fopen("output.txt", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    fwrite(output_buffer, input_file_size, 1, output_file);
    fclose(output_file);

    free(input_buffer);
    free(output_buffer);

    return 0;
}