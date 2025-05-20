//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA // Simple XOR Key

// Function to encrypt/decrypt a buffer using XOR
void xor_encrypt_decrypt(char *buffer, size_t length) {
    for (size_t i = 0; i < length; i++) {
        buffer[i] ^= KEY; // XOR operation
    }
}

// Function to process the file for encryption/decryption
void process_file(const char *file_path, int encrypt) {
    FILE *file = fopen(file_path, "r+b");
    if (!file) {
        perror("Could not open file");
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    // Read the file content into the buffer
    fread(buffer, 1, file_size, file);

    // Encrypt or Decrypt
    xor_encrypt_decrypt(buffer, file_size);

    // Move the file pointer to the beginning and write the new content
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, file_size, file);
    fflush(file);

    // Clean up
    free(buffer);
    fclose(file);
    printf("%s the file '%s' successfully.\n", encrypt ? "Encrypted" : "Decrypted", file_path);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        return 1;
    }

    // Determine whether to encrypt or decrypt
    int encrypt = 0;
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt = 1;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        encrypt = 0;
    } else {
        printf("Invalid option. Use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    const char *file_path = argv[2];
    process_file(file_path, encrypt);

    return 0;
}