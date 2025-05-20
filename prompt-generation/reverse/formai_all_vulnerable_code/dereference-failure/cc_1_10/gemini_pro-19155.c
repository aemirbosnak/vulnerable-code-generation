//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt_file(char *file_name, char *key) {
    // Open the file in read mode
    FILE *file = fopen(file_name, "rb");

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create a buffer to store the encrypted file
    char *encrypted_file = malloc(file_size);

    // Encrypt the file
    int key_len = strlen(key);
    for (long i = 0; i < file_size; i++) {
        // Get the current byte from the file
        char byte = fgetc(file);

        // Encrypt the byte using the key
        byte ^= key[i % key_len];

        // Store the encrypted byte in the buffer
        encrypted_file[i] = byte;
    }

    // Close the file
    fclose(file);

    // Open the file in write mode
    file = fopen(file_name, "wb");

    // Write the encrypted file to disk
    fwrite(encrypted_file, file_size, 1, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(encrypted_file);
}

// Function to decrypt a file
void decrypt_file(char *file_name, char *key) {
    // Open the file in read mode
    FILE *file = fopen(file_name, "rb");

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create a buffer to store the decrypted file
    char *decrypted_file = malloc(file_size);

    // Decrypt the file
    int key_len = strlen(key);
    for (long i = 0; i < file_size; i++) {
        // Get the current byte from the file
        char byte = fgetc(file);

        // Decrypt the byte using the key
        byte ^= key[i % key_len];

        // Store the decrypted byte in the buffer
        decrypted_file[i] = byte;
    }

    // Close the file
    fclose(file);

    // Open the file in write mode
    file = fopen(file_name, "wb");

    // Write the decrypted file to disk
    fwrite(decrypted_file, file_size, 1, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(decrypted_file);
}

int main() {
    // Get the file name and key from the user
    char file_name[100];
    char key[100];
    printf("Enter the file name: ");
    scanf("%s", file_name);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the file
    encrypt_file(file_name, key);

    // Decrypt the file
    decrypt_file(file_name, key);

    return 0;
}