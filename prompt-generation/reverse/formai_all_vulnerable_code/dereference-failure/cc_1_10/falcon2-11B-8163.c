//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt file
void encrypt_file(const char* input_filename, const char* output_filename) {
    // Open input file
    FILE* input_file = fopen(input_filename, "r");
    
    // Check if file opened successfully
    if (input_file == NULL) {
        printf("Error: Unable to open input file\n");
        return;
    }
    
    // Get size of input file
    fseek(input_file, 0L, SEEK_END);
    long size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);
    
    // Allocate memory for encrypted data
    char* encrypted_data = (char*)malloc(size + 1);
    
    // Read data from input file
    fread(encrypted_data, 1, size, input_file);
    
    // Close input file
    fclose(input_file);
    
    // Open output file
    FILE* output_file = fopen(output_filename, "w");
    
    // Check if output file opened successfully
    if (output_file == NULL) {
        printf("Error: Unable to open output file\n");
        free(encrypted_data);
        return;
    }
    
    // Encrypt data
    for (int i = 0; i < size; i++) {
        encrypted_data[i] = encrypted_data[i] ^ 0xFF;
    }
    
    // Write encrypted data to output file
    fwrite(encrypted_data, 1, size, output_file);
    
    // Close output file
    fclose(output_file);
    
    // Free allocated memory
    free(encrypted_data);
}

// Function to decrypt file
void decrypt_file(const char* input_filename, const char* output_filename) {
    // Open input file
    FILE* input_file = fopen(input_filename, "r");
    
    // Check if file opened successfully
    if (input_file == NULL) {
        printf("Error: Unable to open input file\n");
        return;
    }
    
    // Get size of input file
    fseek(input_file, 0L, SEEK_END);
    long size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);
    
    // Allocate memory for decrypted data
    char* decrypted_data = (char*)malloc(size + 1);
    
    // Read data from input file
    fread(decrypted_data, 1, size, input_file);
    
    // Close input file
    fclose(input_file);
    
    // Open output file
    FILE* output_file = fopen(output_filename, "w");
    
    // Check if output file opened successfully
    if (output_file == NULL) {
        printf("Error: Unable to open output file\n");
        free(decrypted_data);
        return;
    }
    
    // Decrypt data
    for (int i = 0; i < size; i++) {
        decrypted_data[i] = decrypted_data[i] ^ 0xFF;
    }
    
    // Write decrypted data to output file
    fwrite(decrypted_data, 1, size, output_file);
    
    // Close output file
    fclose(output_file);
    
    // Free allocated memory
    free(decrypted_data);
}

// Main function
int main() {
    // Encrypt file
    encrypt_file("input.txt", "encrypted.txt");
    
    // Decrypt file
    decrypt_file("encrypted.txt", "decrypted.txt");
    
    return 0;
}