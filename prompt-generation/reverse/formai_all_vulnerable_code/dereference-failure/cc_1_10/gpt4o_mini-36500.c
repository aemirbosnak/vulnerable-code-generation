//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to shift characters for encryption and decryption
char shift_char(char c, int shift) {
    return c + shift;
}

// Function to encrypt the file
void encrypt_file(const char *filename, int shift) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for encryption");
        exit(EXIT_FAILURE);
    }

    char *buffer;
    long file_size;

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = (char *)malloc(file_size * sizeof(char));
    if (!buffer) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(char), file_size, file);
    fclose(file);

    // Encrypt the contents
    for (long i = 0; i < file_size; i++) {
        buffer[i] = shift_char(buffer[i], shift);
    }

    // Write encrypted contents to a new file
    char encrypted_filename[100];
    snprintf(encrypted_filename, sizeof(encrypted_filename), "%s.enc", filename);
    
    file = fopen(encrypted_filename, "w");
    if (!file) {
        perror("Failed to open file for writing encrypted data");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, sizeof(char), file_size, file);
    fclose(file);
    free(buffer);
    
    printf("Encrypted the file '%s' and saved as '%s'\n", filename, encrypted_filename);
}

// Function to decrypt the file
void decrypt_file(const char *filename, int shift) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for decryption");
        exit(EXIT_FAILURE);
    }

    char *buffer;
    long file_size;

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = (char *)malloc(file_size * sizeof(char));
    if (!buffer) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(char), file_size, file);
    fclose(file);

    // Decrypt the contents
    for (long i = 0; i < file_size; i++) {
        buffer[i] = shift_char(buffer[i], -shift);
    }

    // Write decrypted contents to a new file
    char decrypted_filename[100];
    snprintf(decrypted_filename, sizeof(decrypted_filename), "%s.dec", filename);
    
    file = fopen(decrypted_filename, "w");
    if (!file) {
        perror("Failed to open file for writing decrypted data");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, sizeof(char), file_size, file);
    fclose(file);
    free(buffer);
    
    printf("Decrypted the file '%s' and saved as '%s'\n", filename, decrypted_filename);
}

// Main function to execute the encryption/decryption
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <filename> <shift>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *operation = argv[1];
    const char *filename = argv[2];
    int shift = atoi(argv[3]);

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(filename, shift);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(filename, shift);
    } else {
        fprintf(stderr, "Invalid operation: must be 'encrypt' or 'decrypt'\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}