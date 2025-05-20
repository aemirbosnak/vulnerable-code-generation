//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void print_usage() {
    printf("File Encryptor v1.0\n");
    printf("Usage: ./file_encryptor <encrypt|decrypt> <file> <key>\n");
    printf("Encrypts or decrypts the contents of a file using a simple XOR cipher.\n");
}

void xor_encrypt_decrypt(const char *input, const char *output, const uint8_t *key, size_t key_len) {
    FILE *input_file = fopen(input, "rb");
    FILE *output_file = fopen(output, "wb");
    
    if (!input_file || !output_file) {
        perror("File operation failed");
        exit(EXIT_FAILURE);
    }

    int ch;
    size_t index = 0;
    while ((ch = fgetc(input_file)) != EOF) {
        // XOR each byte with the key byte
        fputc(ch ^ key[index % key_len], output_file);
        index++;
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *file = argv[2];
    const char *key_string = argv[3];
    size_t key_len = strlen(key_string);
    uint8_t *key = (uint8_t *)key_string;

    char output_file[256];
    
    if (strcmp(mode, "encrypt") == 0) {
        snprintf(output_file, sizeof(output_file), "%s.enc", file);
        xor_encrypt_decrypt(file, output_file, key, key_len);
        printf("File %s has been encrypted to %s\n", file, output_file);
    } 
    else if (strcmp(mode, "decrypt") == 0) {
        snprintf(output_file, sizeof(output_file), "%s.dec", file);
        xor_encrypt_decrypt(file, output_file, key, key_len);
        printf("File %s has been decrypted to %s\n", file, output_file);
    } 
    else {
        fprintf(stderr, "Invalid mode! Must be 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}