//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024  // Buffer size for file operations
#define KEY_SIZE 256      // Size of the encryption key
#define MAX_FILENAME 255  // Maximum filename length

// Function prototypes
void encrypt_decrypt_file(const char *filename, const char *key);
void display_usage(const char *program_name);
void generate_key(char *key);

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *key_option = argv[2];

    char key[KEY_SIZE];
    if (strcmp(key_option, "-g") == 0) {
        generate_key(key);
        printf("Generated Key: %s\n", key);
    } else {
        strncpy(key, key_option, KEY_SIZE - 1);
        key[KEY_SIZE - 1] = '\0';  // Ensure null-termination
    }

    encrypt_decrypt_file(input_file, key);
    printf("File encryption/decryption complete.\n");

    return EXIT_SUCCESS;
}

// Function to encrypt or decrypt the file
void encrypt_decrypt_file(const char *filename, const char *key) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = (unsigned char *)malloc(file_size);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(unsigned char), file_size, file);
    
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];  // XOR encryption/decryption
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, sizeof(unsigned char), file_size, file);

    free(buffer);
    fclose(file);
}

// Function to display usage instructions
void display_usage(const char *program_name) {
    printf("Usage: %s <filename> <-g | key>\n", program_name);
    printf("Options:\n");
    printf("  <filename> : The file to encrypt/decrypt\n");
    printf("  -g         : Generate a random encryption key and display it\n");
    printf("  key       : Use the provided key for encryption/decryption\n");
}

// Function to generate a random key
void generate_key(char *key) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "0123456789";
    int key_length = rand() % (KEY_SIZE - 1) + 1;  // Generate key length between 1 and KEY_SIZE
    for (int i = 0; i < key_length; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[key_length] = '\0';  // Null-terminate the string
}