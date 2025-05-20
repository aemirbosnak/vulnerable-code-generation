//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the data using a simple XOR encryption
void encrypt_decrypt(char *input, char *output, char key) {
    while (*input) {
        *output = *input ^ key;
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

// Function to read the file content into a string
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END); 
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("Memory allocation error");
        fclose(file);
        return NULL;
    }
    
    fread(buffer, 1, size, file);
    buffer[size] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}

// Function to write the encrypted data back to a file
void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
}

// Main function to handle file encryption
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <encryption_key>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    char key = (char)atoi(argv[3]); // Convert encryption key (A simple integer key)

    // Read the content of the input file
    char *input_data = read_file(input_file);
    if (!input_data) {
        return 1; // Exit if reading file failed
    }

    // Allocate memory for encrypted output
    char *encrypted_data = malloc(strlen(input_data) + 1);
    if (!encrypted_data) {
        perror("Memory allocation error");
        free(input_data);
        return 1;
    }

    // Encrypt the data
    encrypt_decrypt(input_data, encrypted_data, key);

    // Write the encrypted data to the output file
    write_file(output_file, encrypted_data);

    printf("File encrypted successfully!\n");

    // Free allocated memory
    free(input_data);
    free(encrypted_data);

    return 0;
}