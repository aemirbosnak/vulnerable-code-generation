//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt a string using a simple XOR cipher
void encrypt_decrypt(const char *input, char *output, char key) {
    for (size_t i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key; // XOR operation
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

// Function to read the content of a file
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error reading file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0'; // Null-terminate the buffer
    fclose(file);
    return buffer;
}

// Function to write content to a file
void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error writing file");
        return;
    }

    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
}

// Function to display usage information
void display_usage(const char *program_name) {
    printf("Usage: %s <path_to_file> <key>\n", program_name);
    printf("Encrypts or decrypts the specified file using a simple XOR cipher.\n");
    printf("Example: %s myfile.txt A\n", program_name);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    char key = argv[2][0]; // Use the first character of the second argument as the key

    char *file_content = read_file(input_file);
    if (file_content == NULL) {
        return EXIT_FAILURE;
    }

    char *encrypted_content = (char *)malloc(strlen(file_content) + 1);
    if (encrypted_content == NULL) {
        perror("Error allocating memory");
        free(file_content);
        return EXIT_FAILURE;
    }

    // Encrypt or decrypt the file content
    encrypt_decrypt(file_content, encrypted_content, key);

    // Write the result back to the file
    write_file(input_file, encrypted_content);

    // Cleanup
    free(file_content);
    free(encrypted_content);

    printf("File '%s' encrypted/decrypted successfully using key '%c'.\n", input_file, key);
    return EXIT_SUCCESS;
}