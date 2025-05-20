//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "This is a secret key"

// Function to encrypt a file
void encrypt_file(char* input_file, char* output_file) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    
    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    
    // Initialize the encryption buffer
    char buffer[1024];
    
    // Read the input file in chunks
    while (fread(buffer, sizeof(char), sizeof(buffer), input) > 0) {
        // Encrypt each chunk of data
        for (int i = 0; i < sizeof(buffer); i++) {
            buffer[i] = buffer[i] ^ KEY[i % strlen(KEY)];
        }
        
        // Write the encrypted chunk to the output file
        fwrite(buffer, sizeof(char), sizeof(buffer), output);
    }
    
    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt_file(char* input_file, char* output_file) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    
    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    
    // Initialize the decryption buffer
    char buffer[1024];
    
    // Read the input file in chunks
    while (fread(buffer, sizeof(char), sizeof(buffer), input) > 0) {
        // Decrypt each chunk of data
        for (int i = 0; i < sizeof(buffer); i++) {
            buffer[i] = buffer[i] ^ KEY[i % strlen(KEY)];
        }
        
        // Write the decrypted chunk to the output file
        fwrite(buffer, sizeof(char), sizeof(buffer), output);
    }
    
    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file]\n", argv[0]);
        return 1;
    }
    
    // Get the encryption/decryption flag
    char *flag = argv[1];
    
    // Get the input and output file names
    char *input_file = argv[2];
    char *output_file = argv[3];
    
    // Perform encryption or decryption based on the flag
    if (strcmp(flag, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(flag, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        printf("Invalid flag: %s\n", flag);
        return 1;
    }
    
    // Success
    return 0;
}