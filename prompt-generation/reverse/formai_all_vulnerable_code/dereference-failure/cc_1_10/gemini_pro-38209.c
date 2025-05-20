//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key to the apocalypse
unsigned char key[] = "VOID_RADIOACTIVE_WASTE_DECRYPT";

// Encrypts a file using the key
void encrypt_file(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create a buffer to store the encrypted data
    unsigned char* data = malloc(size);
    if (!data) {
        perror("malloc");
        exit(1);
    }

    // Read the file into the buffer
    fread(data, size, 1, file);

    // Encrypt the data
    for (long i = 0; i < size; i++) {
        data[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted data to a new file
    FILE* encrypted_file = fopen("encrypted.dat", "wb");
    if (!encrypted_file) {
        perror("fopen");
        exit(1);
    }

    fwrite(data, size, 1, encrypted_file);

    // Close the files
    fclose(file);
    fclose(encrypted_file);

    // Free the buffer
    free(data);

    printf("File encrypted successfully!\n");
}

// Decrypts a file using the key
void decrypt_file(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create a buffer to store the decrypted data
    unsigned char* data = malloc(size);
    if (!data) {
        perror("malloc");
        exit(1);
    }

    // Read the file into the buffer
    fread(data, size, 1, file);

    // Decrypt the data
    for (long i = 0; i < size; i++) {
        data[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted data to a new file
    FILE* decrypted_file = fopen("decrypted.dat", "wb");
    if (!decrypted_file) {
        perror("fopen");
        exit(1);
    }

    fwrite(data, size, 1, decrypted_file);

    // Close the files
    fclose(file);
    fclose(decrypted_file);

    // Free the buffer
    free(data);

    printf("File decrypted successfully!\n");
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2]);
    } else {
        printf("Invalid command. Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        exit(1);
    }

    return 0;
}