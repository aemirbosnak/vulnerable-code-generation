//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256

// Function prototypes
void display_usage(const char *program_name);
void encrypt_file(const char *input_file, const char *output_file, const char *key);
void decrypt_file(const char *input_file, const char *output_file, const char *key);
char xor_cipher(char input, char key);
void generate_key(const char *password, char *key);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *password = argv[4];
    char key[KEY_SIZE];

    generate_key(password, key);

    if (strcmp(action, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void display_usage(const char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <password>\n", program_name);
    printf("Encrypt or decrypt a file using a simple XOR cipher.\n");
}

void encrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input || !output) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    int character, i = 0;
    while ((character = fgetc(input)) != EOF) {
        fputc(xor_cipher(character, key[i % KEY_SIZE]), output);
        i++;
    }

    fclose(input);
    fclose(output);
    printf("File encrypted successfully: %s\n", output_file);
}

void decrypt_file(const char *input_file, const char *output_file, const char *key) {
    encrypt_file(input_file, output_file, key); // Decryption is the same as encryption
    printf("File decrypted successfully: %s\n", output_file);
}

char xor_cipher(char input, char key) {
    return input ^ key;
}

void generate_key(const char *password, char *key) {
    size_t len = strlen(password);
    for (size_t i = 0; i < KEY_SIZE; ++i) {
        key[i] = password[i % len] + i; // simplistic key generation
    }
}