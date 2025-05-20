//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

// Function prototypes
void encrypt_decrypt_file(const char *filename, const char *key);
void generate_key(char *key, int length);
void usage(const char *program_name);

int main(int argc, char *argv[]) {
    // Variables for file name and operation
    char filename[MAX_FILENAME_LENGTH];
    char key[BUFFER_SIZE];
    
    // Check whether the user provided the correct number of arguments
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Assign command line arguments to variables
    strcpy(filename, argv[1]);
    strcpy(key, argv[2]);

    // Encrypt or decrypt the file
    encrypt_decrypt_file(filename, key);
    
    printf("Operation completed successfully!\n");
    return EXIT_SUCCESS;
}

// Display usage information
void usage(const char *program_name) {
    printf("Usage: %s <filename> <key>\n", program_name);
    printf("Provide a filename to encrypt/decrypt and a key for the process.\n");
}

// Function to encrypt or decrypt the file
void encrypt_decrypt_file(const char *filename, const char *key) {
    FILE *file;
    FILE *temp_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t key_length = strlen(key);
    
    // Open the original file in read mode
    file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Create a temporary file for output
    char temp_filename[MAX_FILENAME_LENGTH];
    snprintf(temp_filename, sizeof(temp_filename), "%s.temp", filename);
    temp_file = fopen(temp_filename, "wb");
    if (!temp_file) {
        fclose(file);
        perror("Error creating temporary file");
        exit(EXIT_FAILURE);
    }

    // Encrypt/Decrypt the file content
    size_t i, j;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (i = 0, j = 0; i < bytes_read; i++, j = (j + 1) % key_length) {
            buffer[i] ^= key[j]; // XOR operation
        }
        fwrite(buffer, 1, bytes_read, temp_file);
    }
    
    // Clean up and close files
    fclose(file);
    fclose(temp_file);
    
    // Replace the original file with the temporary file
    remove(filename);
    rename(temp_filename, filename);
    
    printf("File '%s' has been processed.\n", filename);
}

// Helper function to generate a random key (not used in the current implementation)
void generate_key(char *key, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[length] = '\0'; // Null-terminate the string
}