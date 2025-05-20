//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(const char *prog_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", prog_name);
}

void xor_encrypt_decrypt(FILE *input, FILE *output, const char *key) {
    int key_len = strlen(key);
    int index = 0;
    int ch;

    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key[index % key_len], output);
        index++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char *key = argv[4];

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "encrypt") == 0) {
        printf("Encrypting file...\n");
        xor_encrypt_decrypt(input, output, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Decrypting file...\n");
        xor_encrypt_decrypt(input, output, key);
    } else {
        print_usage(argv[0]);
        fclose(input);
        fclose(output);
        return EXIT_FAILURE;
    }

    printf("Operation completed successfully.\n");
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}