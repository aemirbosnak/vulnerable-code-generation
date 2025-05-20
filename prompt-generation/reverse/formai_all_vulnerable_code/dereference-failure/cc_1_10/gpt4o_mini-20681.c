//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x5A // Simple XOR key for encryption

void encrypt(char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        data[i] ^= KEY; // XOR encryption
    }
}

void decrypt(char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        data[i] ^= KEY; // XOR decryption (same operation)
    }
}

void display_help() {
    printf("C File Encryptor\n");
    printf("Usage:\n");
    printf("  encryptor <encrypt/decrypt> <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        display_help();
        return EXIT_FAILURE;
    }
    
    const char *mode = argv[1];
    const char *input_filename = argv[2];
    const char *output_filename = argv[3];
    
    // Open input file
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    
    // Get file size
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    
    // Allocate memory for the data
    char *data = (char *)malloc(file_size);
    if (!data) {
        perror("Memory allocation failed");
        fclose(input_file);
        return EXIT_FAILURE;
    }
    
    // Read data from the input file
    fread(data, 1, file_size, input_file);
    fclose(input_file);
    
    // Process data based on the mode
    if (strcmp(mode, "encrypt") == 0) {
        encrypt(data, file_size);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(data, file_size);
    } else {
        printf("Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        free(data);
        return EXIT_FAILURE;
    }
    
    // Open output file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(data);
        return EXIT_FAILURE;
    }
    
    // Write processed data to the output file
    fwrite(data, 1, file_size, output_file);
    fclose(output_file);
    
    // Release allocated memory
    free(data);
    
    printf("Operation successful! Output saved to: %s\n", output_filename);
    
    return EXIT_SUCCESS;
}