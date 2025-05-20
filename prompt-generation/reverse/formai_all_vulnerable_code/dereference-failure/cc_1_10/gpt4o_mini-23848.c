//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

void encrypt_decrypt(FILE *input, FILE *output, const char *key) {
    int c;
    size_t key_length = strlen(key);
    size_t i = 0;

    while ((c = fgetc(input)) != EOF) {
        // XOR encryption/decryption
        fputc(c ^ key[i % key_length], output);
        i++;
    }
}

void handle_file(const char *filename, const char *key, int encrypt) {
    FILE *input = fopen(filename, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }

    char output_filename[256];
    if (encrypt)
        snprintf(output_filename, sizeof(output_filename), "%s.enc", filename);
    else
        snprintf(output_filename, sizeof(output_filename), "%s.dec", filename);

    FILE *output = fopen(output_filename, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    encrypt_decrypt(input, output, key);
    
    fclose(input);
    fclose(output);
    printf("File %s successfully %s in '%s'.\n", filename, encrypt ? "encrypted" : "decrypted", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <filename> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int encrypt = strcmp(argv[1], "encrypt") == 0;
    if (!encrypt && strcmp(argv[1], "decrypt") != 0) {
        fprintf(stderr, "First argument must be 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    const char *filename = argv[2];
    const char *key = argv[3];

    if (strlen(key) > KEY_SIZE) {
        fprintf(stderr, "Key must not exceed %d characters.\n", KEY_SIZE);
        return EXIT_FAILURE;
    }

    handle_file(filename, key, encrypt);

    return EXIT_SUCCESS;
}