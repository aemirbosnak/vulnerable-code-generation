//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(FILE *input, FILE *output, const char *key) {
    int key_length = strlen(key);
    int char_read;
    int index = 0;
    
    while ((char_read = fgetc(input)) != EOF) {
        // XOR the character read with the key character
        char encrypted_char = char_read ^ key[index % key_length];
        fputc(encrypted_char, output);
        index++;
    }
}

void print_usage() {
    printf("Usage: ./file_encryptor <encrypt/decrypt> <input_file> <output_file> <key>\n");
    printf("Example: ./file_encryptor encrypt myfile.txt myfile.enc secretkey\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage();
        return 1;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char *key = argv[4];

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        fprintf(stderr, "Could not open input file: %s\n", input_file);
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        fclose(input);
        fprintf(stderr, "Could not open output file: %s\n", output_file);
        return 1;
    }

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_decrypt(input, output, key);
        printf("File encrypted successfully to %s\n", output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        encrypt_decrypt(input, output, key);
        printf("File decrypted successfully to %s\n", output_file);
    } else {
        print_usage();
    }

    fclose(input);
    fclose(output);
    return 0;
}