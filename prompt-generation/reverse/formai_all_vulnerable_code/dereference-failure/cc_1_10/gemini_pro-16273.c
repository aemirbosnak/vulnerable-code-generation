//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file
void encryptFile(char *fileName) {
    // Open the file
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate memory for the encrypted file
    unsigned char *encryptedFile = malloc(fileSize);
    if (encryptedFile == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    fread(encryptedFile, 1, fileSize, file);

    // Encrypt the file
    for (long i = 0; i < fileSize; i++) {
        encryptedFile[i] ^= 0x55;
    }

    // Write the encrypted file to a new file
    FILE *encryptedFileFile = fopen("encrypted.bin", "wb");
    if (encryptedFileFile == NULL) {
        perror("Error opening encrypted file");
        exit(1);
    }

    fwrite(encryptedFile, 1, fileSize, encryptedFileFile);

    // Close the files
    fclose(file);
    fclose(encryptedFileFile);

    // Free the memory
    free(encryptedFile);
}

// Function to decrypt a file
void decryptFile(char *fileName) {
    // Open the file
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate memory for the decrypted file
    unsigned char *decryptedFile = malloc(fileSize);
    if (decryptedFile == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file into the buffer
    fread(decryptedFile, 1, fileSize, file);

    // Decrypt the file
    for (long i = 0; i < fileSize; i++) {
        decryptedFile[i] ^= 0x55;
    }

    // Write the decrypted file to a new file
    FILE *decryptedFileFile = fopen("decrypted.bin", "wb");
    if (decryptedFileFile == NULL) {
        perror("Error opening decrypted file");
        exit(1);
    }

    fwrite(decryptedFile, 1, fileSize, decryptedFileFile);

    // Close the files
    fclose(file);
    fclose(decryptedFileFile);

    // Free the memory
    free(decryptedFile);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encrypt|decrypt> <file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(argv[2]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return 1;
    }

    return 0;
}