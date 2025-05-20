//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define MAX_BUFFER_SIZE 1024

void encrypt_file(char* input_filename, char* output_filename, char* encryption_key) {
    // open input file for reading
    FILE* input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open file %s for reading.\n", input_filename);
        exit(EXIT_FAILURE);
    }

    // open output file for writing
    FILE* output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Unable to open file %s for writing.\n", output_filename);
        exit(EXIT_FAILURE);
    }

    // get the size of the input file
    fseek(input_file, 0L, SEEK_END);
    long int input_file_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // read data from input file in chunks and write to output file
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int bytes_read = 0;
    int bytes_written = 0;
    while ((bytes_read = fread(input_buffer, 1, MAX_BUFFER_SIZE, input_file)) > 0) {
        // encrypt the input buffer with the encryption key and store in the output buffer
        for (int i = 0; i < bytes_read; i++) {
            output_buffer[i] = input_buffer[i] ^ encryption_key[i % strlen(encryption_key)];
        }

        // write encrypted data to output file
        bytes_written = fwrite(output_buffer, 1, bytes_read, output_file);
        if (bytes_written < bytes_read) {
            printf("Error: Unable to write data to output file.\n");
            exit(EXIT_FAILURE);
        }
    }

    // close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Encryption successful! Encrypted file saved as %s", output_filename);
}

int main() {
    char input_filename[MAX_FILENAME_SIZE];
    char output_filename[MAX_FILENAME_SIZE];
    char encryption_key[MAX_FILENAME_SIZE];

    // get input filename from user
    printf("Enter filename to encrypt: ");
    fgets(input_filename, MAX_FILENAME_SIZE, stdin);
    input_filename[strcspn(input_filename, "\n")] = 0;

    // get output filename from user
    printf("Enter name for encrypted file: ");
    fgets(output_filename, MAX_FILENAME_SIZE, stdin);
    output_filename[strcspn(output_filename, "\n")] = 0;

    // get encryption key from user
    printf("Enter encryption key: ");
    fgets(encryption_key, MAX_FILENAME_SIZE, stdin);
    encryption_key[strcspn(encryption_key, "\n")] = 0;

    encrypt_file(input_filename, output_filename, encryption_key);

    return 0;
}