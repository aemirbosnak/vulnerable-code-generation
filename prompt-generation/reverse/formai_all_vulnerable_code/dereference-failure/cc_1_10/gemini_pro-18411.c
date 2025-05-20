//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to encrypt a file
void encrypt_file(char *filename, char *key) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size);
    if (file_contents == NULL) {
        fprintf(stderr, "Error allocating memory for file contents\n");
        exit(1);
    }

    // Read the file contents into memory
    fread(file_contents, file_size, 1, file);
    fclose(file);

    // Encrypt the file contents
    for (int i = 0; i < file_size; i++) {
        file_contents[i] ^= key[i % strlen(key)];
    }

    // Open the file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Write the encrypted file contents to the file
    fwrite(file_contents, file_size, 1, file);
    fclose(file);

    // Free the memory allocated for the file contents
    free(file_contents);
}

// Function to decrypt a file
void decrypt_file(char *filename, char *key) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size);
    if (file_contents == NULL) {
        fprintf(stderr, "Error allocating memory for file contents\n");
        exit(1);
    }

    // Read the file contents into memory
    fread(file_contents, file_size, 1, file);
    fclose(file);

    // Decrypt the file contents
    for (int i = 0; i < file_size; i++) {
        file_contents[i] ^= key[i % strlen(key)];
    }

    // Open the file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Write the decrypted file contents to the file
    fwrite(file_contents, file_size, 1, file);
    fclose(file);

    // Free the memory allocated for the file contents
    free(file_contents);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments have been passed
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [encrypt|decrypt] [filename] [key]\n", argv[0]);
        exit(1);
    }

    // Get the file name
    char *filename = argv[2];

    // Get the key
    char *key = argv[3];

    // Check if the key is valid
    if (strlen(key) == 0) {
        fprintf(stderr, "Error: The key cannot be empty\n");
        exit(1);
    }

    // Encrypt or decrypt the file
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(filename, key);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(filename, key);
    } else {
        fprintf(stderr, "Error: Invalid operation\n");
        exit(1);
    }

    return 0;
}