//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "MySuperSecretEncryptionKey"

// Function to encrypt a string using XOR encryption
char *xor_encrypt(char *plaintext) {
    int key_len = strlen(KEY);
    int plaintext_len = strlen(plaintext);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintext_len + 1);

    // Encrypt each character of the plaintext
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % key_len];
    }

    // Terminate the ciphertext with a null character
    ciphertext[plaintext_len] = '\0';

    // Return the encrypted ciphertext
    return ciphertext;
}

// Function to decrypt a ciphertext using XOR encryption
char *xor_decrypt(char *ciphertext) {
    int key_len = strlen(KEY);
    int ciphertext_len = strlen(ciphertext);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertext_len + 1);

    // Decrypt each character of the ciphertext
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % key_len];
    }

    // Terminate the plaintext with a null character
    plaintext[ciphertext_len] = '\0';

    // Return the decrypted plaintext
    return plaintext;
}

// Function to read a file into a buffer
char *read_file(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file buffer
    char *buffer = malloc(file_size + 1);

    // Read the file into the buffer
    fread(buffer, file_size, 1, file);

    // Terminate the buffer with a null character
    buffer[file_size] = '\0';

    // Close the file
    fclose(file);

    // Return the file buffer
    return buffer;
}

// Function to write a buffer to a file
void write_file(char *filename, char *buffer) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the buffer to the file
    fwrite(buffer, strlen(buffer), 1, file);

    // Close the file
    fclose(file);
}

// Function to encrypt a file using XOR encryption
void encrypt_file(char *input_filename, char *output_filename) {
    // Read the input file into a buffer
    char *input_buffer = read_file(input_filename);

    // Encrypt the input buffer
    char *output_buffer = xor_encrypt(input_buffer);

    // Write the output buffer to the output file
    write_file(output_filename, output_buffer);

    // Free the input and output buffers
    free(input_buffer);
    free(output_buffer);
}

// Function to decrypt a file using XOR encryption
void decrypt_file(char *input_filename, char *output_filename) {
    // Read the input file into a buffer
    char *input_buffer = read_file(input_filename);

    // Decrypt the input buffer
    char *output_buffer = xor_decrypt(input_buffer);

    // Write the output buffer to the output file
    write_file(output_filename, output_buffer);

    // Free the input and output buffers
    free(input_buffer);
    free(output_buffer);
}

// Function to print help message
void print_help() {
    printf("Usage: file_encryptor [options] input_filename output_filename\n");
    printf("Options:\n");
    printf("  -e Encrypt the input file\n");
    printf("  -d Decrypt the input file\n");
    printf("  -h Print this help message\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 4) {
        print_help();
        exit(EXIT_FAILURE);
    }

    // Get the option and input and output filenames
    char *option = argv[1];
    char *input_filename = argv[2];
    char *output_filename = argv[3];

    // Check if the option is valid
    if (strcmp(option, "-e") != 0 && strcmp(option, "-d") != 0) {
        print_help();
        exit(EXIT_FAILURE);
    }

    // Encrypt or decrypt the file
    if (strcmp(option, "-e") == 0) {
        encrypt_file(input_filename, output_filename);
    } else if (strcmp(option, "-d") == 0) {
        decrypt_file(input_filename, output_filename);
    }

    return EXIT_SUCCESS;
}