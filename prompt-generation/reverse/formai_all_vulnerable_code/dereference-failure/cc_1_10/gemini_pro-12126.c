//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum file size
#define MAX_FILE_SIZE 1024

// Define the encryption key
#define ENCRYPTION_KEY "MySuperSecretKey"

// Define the encryption function
void encrypt(char *file_name) {
    // Open the file in read mode
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        // Error opening the file
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Check if the file is too large
    if (file_size > MAX_FILE_SIZE) {
        // Error file too large
        fprintf(stderr, "Error: File too large (%ld bytes)\n", file_size);
        exit(1);
    }

    // Allocate memory for the encrypted file
    char *encrypted_file = malloc(file_size);
    if (encrypted_file == NULL) {
        // Error allocating memory
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into a buffer
    char buffer[MAX_FILE_SIZE];
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Encrypt the buffer
    for (int i = 0; i < file_size; i++) {
        // Get the byte at index i
        char byte = buffer[i];

        // Encrypt the byte
        byte = byte ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];

        // Store the encrypted byte back into the buffer
        buffer[i] = byte;
    }

    // Write the encrypted buffer to a new file
    file = fopen("encrypted.txt", "wb");
    if (file == NULL) {
        // Error opening the file
        perror("Error opening file");
        exit(1);
    }

    // Write the encrypted buffer to the file
    fwrite(buffer, file_size, 1, file);
    fclose(file);

    // Free the memory allocated for the encrypted file
    free(encrypted_file);

    // Print a success message
    printf("File encrypted successfully\n");
}

// Define the main function
int main(int argc, char **argv) {
    // Check if the user provided a filename
    if (argc != 2) {
        // Error: No file name provided
        fprintf(stderr, "Error: No file name provided\n");
        exit(1);
    }

    // Get the filename from the command line
    char *file_name = argv[1];

    // Encrypt the file
    encrypt(file_name);

    // Exit the program
    return 0;
}