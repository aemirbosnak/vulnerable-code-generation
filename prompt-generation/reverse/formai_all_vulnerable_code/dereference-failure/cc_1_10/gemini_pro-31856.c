//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Encryption key
const char KEY[] = "SuperSecret";

// Reads a file and encrypts it using XOR encryption
void encryptFile(FILE *inputFile, FILE *outputFile) {
    // Get file size
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for encrypted data
    unsigned char *encryptedData = malloc(fileSize);

    // Encrypt each byte using XOR operation
    int i;
    for (i = 0; i < fileSize; i++) {
        unsigned char byte;
        fread(&byte, 1, 1, inputFile);
        encryptedData[i] = byte ^ KEY[i % sizeof(KEY)];
    }

    // Write encrypted data to output file
    fwrite(encryptedData, 1, fileSize, outputFile);

    // Free allocated memory
    free(encryptedData);
}

// Decrypts a file using XOR encryption
void decryptFile(FILE *inputFile, FILE *outputFile) {
    // Get file size
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for decrypted data
    unsigned char *decryptedData = malloc(fileSize);

    // Decrypt each byte using XOR operation
    int i;
    for (i = 0; i < fileSize; i++) {
        unsigned char byte;
        fread(&byte, 1, 1, inputFile);
        decryptedData[i] = byte ^ KEY[i % sizeof(KEY)];
    }

    // Write decrypted data to output file
    fwrite(decryptedData, 1, fileSize, outputFile);

    // Free allocated memory
    free(decryptedData);
}

int main() {
    char inputFileName[] = "secret.txt";
    char encryptedFileName[] = "encrypted.bin";
    char decryptedFileName[] = "decrypted.txt";

    // Open input and output files
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return EXIT_FAILURE;
    }

    FILE *encryptedFile = fopen(encryptedFileName, "wb");
    if (encryptedFile == NULL) {
        printf("Error opening encrypted file!\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    FILE *decryptedFile = fopen(decryptedFileName, "wb");
    if (decryptedFile == NULL) {
        printf("Error opening decrypted file!\n");
        fclose(inputFile);
        fclose(encryptedFile);
        return EXIT_FAILURE;
    }

    // Encrypt the file
    printf("Encrypting file...\n");
    encryptFile(inputFile, encryptedFile);
    fclose(inputFile);
    fclose(encryptedFile);

    // Decrypt the file
    printf("Decrypting file...\n");
    decryptFile(encryptedFile, decryptedFile);
    fclose(encryptedFile);
    fclose(decryptedFile);

    printf("File encryption and decryption completed successfully!\n");
    return EXIT_SUCCESS;
}