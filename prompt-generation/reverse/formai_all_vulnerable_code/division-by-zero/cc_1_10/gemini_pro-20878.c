//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *fileName, char *key) {
    // Open the file to be encrypted
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Create a buffer to hold the encrypted file
    char *encryptedFile = malloc(fileSize);
    if (encryptedFile == NULL) {
        printf("Error allocating memory for encrypted file\n");
        fclose(file);
        return;
    }

    // Encrypt the file
    for (long i = 0; i < fileSize; i++) {
        encryptedFile[i] = fgetc(file) ^ key[i % strlen(key)];
    }

    // Close the input file
    fclose(file);

    // Open the output file to write the encrypted file
    file = fopen("encrypted.dat", "wb");
    if (file == NULL) {
        printf("Error opening file encrypted.dat\n");
        free(encryptedFile);
        return;
    }

    // Write the encrypted file to disk
    fwrite(encryptedFile, fileSize, 1, file);

    // Close the output file
    fclose(file);

    // Free the memory allocated for the encrypted file
    free(encryptedFile);
}

// Function to decrypt a file
void decryptFile(char *fileName, char *key) {
    // Open the file to be decrypted
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Create a buffer to hold the decrypted file
    char *decryptedFile = malloc(fileSize);
    if (decryptedFile == NULL) {
        printf("Error allocating memory for decrypted file\n");
        fclose(file);
        return;
    }

    // Decrypt the file
    for (long i = 0; i < fileSize; i++) {
        decryptedFile[i] = fgetc(file) ^ key[i % strlen(key)];
    }

    // Close the input file
    fclose(file);

    // Open the output file to write the decrypted file
    file = fopen("decrypted.txt", "wb");
    if (file == NULL) {
        printf("Error opening file decrypted.txt\n");
        free(decryptedFile);
        return;
    }

    // Write the decrypted file to disk
    fwrite(decryptedFile, fileSize, 1, file);

    // Close the output file
    fclose(file);

    // Free the memory allocated for the decrypted file
    free(decryptedFile);
}

int main() {
    // Get the file name and key from the user
    char fileName[256];
    char key[256];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the file
    encryptFile(fileName, key);

    // Decrypt the file
    decryptFile("encrypted.dat", key);

    return 0;
}