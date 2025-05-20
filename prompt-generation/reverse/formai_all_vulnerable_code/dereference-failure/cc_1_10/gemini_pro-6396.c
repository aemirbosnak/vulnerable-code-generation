//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR encryption key
char key[] = "SECRET_KEY";

// Encrypt a file using XOR encryption
void encryptFile(char *filename) {
    // Open the file in binary mode
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Create a buffer to hold the encrypted data
    char *encryptedData = malloc(filesize);
    if (encryptedData == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    fread(encryptedData, 1, filesize, file);

    // Encrypt the data using XOR encryption
    for (long i = 0; i < filesize; i++) {
        encryptedData[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted data back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(encryptedData, 1, filesize, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(encryptedData);
}

// Decrypt a file using XOR encryption
void decryptFile(char *filename) {
    // Open the file in binary mode
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // Create a buffer to hold the decrypted data
    char *decryptedData = malloc(filesize);
    if (decryptedData == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    fread(decryptedData, 1, filesize, file);

    // Decrypt the data using XOR encryption
    for (long i = 0; i < filesize; i++) {
        decryptedData[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted data back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(decryptedData, 1, filesize, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(decryptedData);
}

// Print usage information
void usage() {
    printf("Usage: file_encrypter [encrypt|decrypt] <filename>\n");
    printf("Example: file_encrypter encrypt secret.txt\n");
    printf("Example: file_encrypter decrypt secret.txt.enc\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        usage();
        return 1;
    }

    // Get the action (encrypt or decrypt)
    char *action = argv[1];

    // Get the filename
    char *filename = argv[2];

    // Encrypt the file
    if (strcmp(action, "encrypt") == 0) {
        encryptFile(filename);
        printf("File encrypted successfully!\n");
    // Decrypt the file
    } else if (strcmp(action, "decrypt") == 0) {
        decryptFile(filename);
        printf("File decrypted successfully!\n");
    // Print usage information
    } else {
        usage();
        return 1;
    }

    return 0;
}