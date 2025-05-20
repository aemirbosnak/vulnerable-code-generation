//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(const char* filename, const char* key) {
    // Open the file in read mode
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for encrypted file
    char* encrypted = (char*)malloc(size);
    if (encrypted == NULL) {
        fprintf(stderr, "Error allocating memory for encrypted file\n");
        fclose(file);
        return;
    }

    // Encrypt each byte of the file
    int i = 0;
    while (i < size) {
        // Read the current byte
        char byte = fgetc(file);

        // Encrypt the byte using the key
        byte ^= key[i % strlen(key)];

        // Write the encrypted byte to the encrypted file
        encrypted[i] = byte;
        i++;
    }

    // Close the input file
    fclose(file);

    // Write the encrypted file to disk
    FILE* encryptedFile = fopen(filename, "wb");
    if (encryptedFile == NULL) {
        fprintf(stderr, "Error opening encrypted file: %s\n", filename);
        free(encrypted);
        return;
    }
    fwrite(encrypted, 1, size, encryptedFile);
    fclose(encryptedFile);

    // Free the memory used by the encrypted file
    free(encrypted);
}

// Function to decrypt a file
void decryptFile(const char* filename, const char* key) {
    // Open the file in read mode
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for decrypted file
    char* decrypted = (char*)malloc(size);
    if (decrypted == NULL) {
        fprintf(stderr, "Error allocating memory for decrypted file\n");
        fclose(file);
        return;
    }

    // Decrypt each byte of the file
    int i = 0;
    while (i < size) {
        // Read the current byte
        char byte = fgetc(file);

        // Decrypt the byte using the key
        byte ^= key[i % strlen(key)];

        // Write the decrypted byte to the decrypted file
        decrypted[i] = byte;
        i++;
    }

    // Close the input file
    fclose(file);

    // Write the decrypted file to disk
    FILE* decryptedFile = fopen(filename, "wb");
    if (decryptedFile == NULL) {
        fprintf(stderr, "Error opening decrypted file: %s\n", filename);
        free(decrypted);
        return;
    }
    fwrite(decrypted, 1, size, decryptedFile);
    fclose(decryptedFile);

    // Free the memory used by the decrypted file
    free(decrypted);
}

// Main function
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <key> <filename>\n", argv[0]);
        return 1;
    }

    // Get the key and filename from the command line arguments
    const char* key = argv[1];
    const char* filename = argv[2];

    // Encrypt the file using the key
    encryptFile(filename, key);

    // Decrypt the file using the key
    decryptFile(filename, key);

    return 0;
}