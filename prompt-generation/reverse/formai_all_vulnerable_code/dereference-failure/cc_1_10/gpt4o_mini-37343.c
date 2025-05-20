//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 5
#define MAX_FILENAME_LENGTH 256

void encrypt_char(char *c) {
    *c = *c + SHIFT;
}

void decrypt_char(char *c) {
    *c = *c - SHIFT;
}

void process_file(const char *input_filename, const char *output_filename, int encrypt) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    char c;
    while (fread(&c, sizeof(char), 1, input_file) == 1) {
        if (encrypt) {
            encrypt_char(&c);
        } else {
            decrypt_char(&c);
        }
        fwrite(&c, sizeof(char), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", program_name);
    printf("  encrypt: Encrypts the input file\n");
    printf("  decrypt: Decrypts the input file\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int encrypt = 0;
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt = 1;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        encrypt = 0;
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[2];
    const char *output_filename = argv[3];

    process_file(input_filename, output_filename, encrypt);

    printf("%s operation completed successfully!\n", encrypt ? "Encryption" : "Decryption");

    return EXIT_SUCCESS;
}