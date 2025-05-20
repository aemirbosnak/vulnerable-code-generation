//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generate a random key for encryption
unsigned int generate_key() {
    return rand() % 1000000;
}

// Encrypt a file using the given key
void encrypt_file(char *filename, unsigned int key) {
    // Open the file for reading in binary mode
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate a buffer for the encrypted data
    unsigned char *encrypted_data = malloc(file_size);
    if (encrypted_data == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    fread(encrypted_data, file_size, 1, file);
    fclose(file);

    // Encrypt the data using the given key
    for (long i = 0; i < file_size; i++) {
        encrypted_data[i] ^= key;
    }

    // Write the encrypted data to a new file
    char *encrypted_filename = malloc(strlen(filename) + 5);
    strcpy(encrypted_filename, filename);
    strcat(encrypted_filename, ".enc");
    file = fopen(encrypted_filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(encrypted_data, file_size, 1, file);
    fclose(file);

    // Free the allocated memory
    free(encrypted_data);
    free(encrypted_filename);
}

// Decrypt a file using the given key
void decrypt_file(char *filename, unsigned int key) {
    // Open the file for reading in binary mode
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate a buffer for the decrypted data
    unsigned char *decrypted_data = malloc(file_size);
    if (decrypted_data == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    fread(decrypted_data, file_size, 1, file);
    fclose(file);

    // Decrypt the data using the given key
    for (long i = 0; i < file_size; i++) {
        decrypted_data[i] ^= key;
    }

    // Write the decrypted data to a new file
    char *decrypted_filename = malloc(strlen(filename) - 4);
    strncpy(decrypted_filename, filename, strlen(filename) - 4);
    file = fopen(decrypted_filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(decrypted_data, file_size, 1, file);
    fclose(file);

    // Free the allocated memory
    free(decrypted_data);
    free(decrypted_filename);
}

int main() {
    // Generate a random key
    unsigned int key = generate_key();

    // Encrypt a file
    encrypt_file("test.txt", key);

    // Decrypt the file
    decrypt_file("test.txt.enc", key);

    return 0;
}