//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define KEY 13 // Simple Caesar cipher key

void encrypt(char *input, char *output, int key) {
    while (*input) {
        if (*input >= 'a' && *input <= 'z') {
            *output = (*input - 'a' + key) % 26 + 'a';
        } else if (*input >= 'A' && *input <= 'Z') {
            *output = (*input - 'A' + key) % 26 + 'A';
        } else {
            *output = *input; // Non-alphabetic characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output, int key) {
    encrypt(input, output, 26 - key); // Reversal of Caesar cipher
}

void file_encrypt(const char *filename, const int key) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }

    char buffer[BUFFER_SIZE];
    char encrypted[BUFFER_SIZE];
    FILE *output_file = fopen("encrypted.txt", "wb");
    if (output_file == NULL) {
        perror("Could not open file for writing");
        fclose(file);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        encrypt(buffer, encrypted, key);
        fputs(encrypted, output_file);
    }

    fclose(file);
    fclose(output_file);
    printf("Encryption complete. Encrypted file: encrypted.txt\n");
}

void file_decrypt(const char *filename, const int key) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }

    char buffer[BUFFER_SIZE];
    char decrypted[BUFFER_SIZE];
    FILE *output_file = fopen("decrypted.txt", "wb");
    if (output_file == NULL) {
        perror("Could not open file for writing");
        fclose(file);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        decrypt(buffer, decrypted, key);
        fputs(decrypted, output_file);
    }

    fclose(file);
    fclose(output_file);
    printf("Decryption complete. Decrypted file: decrypted.txt\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        file_encrypt(argv[2], KEY);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        file_decrypt(argv[2], KEY);
    } else {
        fprintf(stderr, "Invalid option. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}