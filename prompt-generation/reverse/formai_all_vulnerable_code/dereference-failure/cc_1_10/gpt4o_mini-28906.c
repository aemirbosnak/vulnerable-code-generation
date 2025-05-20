//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using a simple XOR cipher
void encrypt_decrypt(char *input, char *output, char key) {
    while (*input) {
        *output = *input ^ key; // XOR operation for encryption/decryption
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

// Function to read content from a file into a string
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(length + 1);
    if (!content) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(content, 1, length, file);
    content[length] = '\0'; // Null-terminate the content
    fclose(file);
    return content;
}

// Function to write content from a string to a file
int write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);
    return 1;
}

// Main program to encrypt a file
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    char key = argv[3][0]; // Take first character of the key for simplicity

    // Read the input file
    char *file_content = read_file(input_file);
    if (!file_content) {
        return EXIT_FAILURE;
    }

    // Prepare buffer for the output
    char *encrypted_content = malloc(strlen(file_content) + 1);
    if (!encrypted_content) {
        perror("Failed to allocate memory for encrypted content");
        free(file_content);
        return EXIT_FAILURE;
    }

    // Encrypt the content
    encrypt_decrypt(file_content, encrypted_content, key);

    // Write encrypted content to the output file
    if (!write_file(output_file, encrypted_content)) {
        free(file_content);
        free(encrypted_content);
        return EXIT_FAILURE;
    }

    // Cleanup memory
    free(file_content);
    free(encrypted_content);

    printf("File '%s' encrypted successfully to '%s' using key '%c'.\n", input_file, output_file, key);
    return EXIT_SUCCESS;
}