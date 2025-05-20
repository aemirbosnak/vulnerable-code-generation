//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to be encrypted
#define KEY_SIZE 16 // Size of encryption key

// Function to encrypt file using recursion
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read, bytes_written;
    char encrypted_buffer[MAX_FILE_SIZE];

    // Read data from input file
    bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file);

    // Encrypt data using key
    for(int i = 0; i < bytes_read; i++) {
        encrypted_buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
    }

    // Write encrypted data to output file
    bytes_written = fwrite(encrypted_buffer, 1, bytes_read, output_file);

    // Check if end of file is reached
    if(ferror(input_file)) {
        // If end of file is reached, close the input and output files
        fclose(input_file);
        fclose(output_file);
        return;
    }

    // If end of file is not reached, encrypt next block of data recursively
    encrypt_file(input_file, output_file, key);
}

int main() {
    char input_file_name[100], output_file_name[100], key[KEY_SIZE];
    FILE *input_file, *output_file;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Get encryption key from user
    printf("Enter encryption key (16 characters): ");
    scanf("%s", key);

    // Open input and output files
    input_file = fopen(input_file_name, "rb");
    output_file = fopen(output_file_name, "wb");

    // Check if input file is opened successfully
    if(input_file == NULL) {
        printf("Error opening input file");
        exit(1);
    }

    // Check if output file is opened successfully
    if(output_file == NULL) {
        printf("Error opening output file");
        exit(1);
    }

    // Encrypt file using recursion
    encrypt_file(input_file, output_file, key);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}