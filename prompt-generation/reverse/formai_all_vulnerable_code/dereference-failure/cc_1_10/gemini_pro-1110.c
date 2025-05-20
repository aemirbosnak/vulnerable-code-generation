//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a password
int encrypt_file(char *filename, char *password) {
    FILE *fp;
    char *buffer;
    long file_size;
    int i, key_length;

    // Open the file in read mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for the buffer to hold the file contents
    buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        fclose(fp);
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    // Get the length of the password
    key_length = strlen(password);

    // Encrypt the file contents using the password
    for (i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ password[i % key_length];
    }

    // Open the file in write mode
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        free(buffer);
        return -1;
    }

    // Write the encrypted file contents to the file
    fwrite(buffer, 1, file_size, fp);
    fclose(fp);

    // Free the memory allocated for the buffer
    free(buffer);

    return 0;
}

// Function to decrypt a file using a password
int decrypt_file(char *filename, char *password) {
    FILE *fp;
    char *buffer;
    long file_size;
    int i, key_length;

    // Open the file in read mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for the buffer to hold the file contents
    buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        fclose(fp);
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    // Get the length of the password
    key_length = strlen(password);

    // Decrypt the file contents using the password
    for (i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ password[i % key_length];
    }

    // Open the file in write mode
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        free(buffer);
        return -1;
    }

    // Write the decrypted file contents to the file
    fwrite(buffer, 1, file_size, fp);
    fclose(fp);

    // Free the memory allocated for the buffer
    free(buffer);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s {encrypt|decrypt} filename password\n", argv[0]);
        return -1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        return encrypt_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        return decrypt_file(argv[2], argv[3]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return -1;
    }

    return 0;
}