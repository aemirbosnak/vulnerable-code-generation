//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 16 // Size of the encryption key in bytes
#define BLOCK_SIZE 64 // Size of each block of data to be encrypted/decrypted in bytes

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char buffer[BLOCK_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'a' + key[i % KEY_SIZE]) % 26 + 'a';
            }
            fwrite(&c, 1, 1, output_file);
        }
    }
}

void decrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char buffer[BLOCK_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'a' + 26 - key[i % KEY_SIZE]) % 26 + 'a';
            }
            fwrite(&c, 1, 1, output_file);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    char* operation = argv[1];
    FILE* input_file = fopen(argv[2], "rb");
    FILE* output_file = fopen(argv[3], "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s)\n");
        return 1;
    }

    char key[KEY_SIZE];
    generate_key(key);

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
        printf("File encrypted successfully\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
        printf("File decrypted successfully\n");
    } else {
        printf("Invalid operation\n");
        return 1;
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}