//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xor_encrypt_decrypt(char *input, char *output, char *key) {
    int key_len = strlen(key);
    FILE *input_file = fopen(input, "rb");
    FILE *output_file = fopen(output, "wb");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    int ch;
    int i = 0;

    // Read each byte from input file and apply XOR with key
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ key[i % key_len], output_file);
        i++;
    }

    fclose(input_file);
    fclose(output_file);
}

void display_usage() {
    printf("Usage: file_encryptor <encrypt|decrypt> <input_file> <output_file> <key>\n");
    printf("Example: file_encryptor encrypt example.txt encrypted_file.txt mysecretkey\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        display_usage();
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char *key = argv[4];

    if (strcmp(mode, "encrypt") == 0) {
        xor_encrypt_decrypt(input_file, output_file, key);
        printf("File encrypted successfully to '%s'.\n", output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        xor_encrypt_decrypt(input_file, output_file, key);
        printf("File decrypted successfully to '%s'.\n", output_file);
    } else {
        display_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}