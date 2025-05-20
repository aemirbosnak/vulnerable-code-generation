//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// The key for encryption/decryption
const char key[] = "MySuperSecretKey";

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");

    // Read the input file into a buffer
    fseek(fin, 0, SEEK_END);
    long file_size = ftell(fin);
    rewind(fin);
    char *buffer = (char *) malloc(file_size);
    fread(buffer, 1, file_size, fin);

    // Encrypt the buffer
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, file_size, fout);

    // Close the files
    fclose(fin);
    fclose(fout);

    // Free the buffer
    free(buffer);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");

    // Read the input file into a buffer
    fseek(fin, 0, SEEK_END);
    long file_size = ftell(fin);
    rewind(fin);
    char *buffer = (char *) malloc(file_size);
    fread(buffer, 1, file_size, fin);

    // Decrypt the buffer
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, 1, file_size, fout);

    // Close the files
    fclose(fin);
    fclose(fout);

    // Free the buffer
    free(buffer);
}

int main() {
    // Get the input and output file names
    char input_file[100];
    char output_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Encrypt the file
    encrypt_file(input_file, output_file);

    // Decrypt the file
    decrypt_file(output_file, "decrypted_file.txt");

    printf("File encrypted and decrypted successfully!\n");

    return 0;
}