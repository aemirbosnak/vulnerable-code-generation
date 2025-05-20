//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void encrypt_decrypt(const char *input, const char *output, const char *key) {
    FILE *inFile, *outFile;
    size_t keyLen = strlen(key);
    size_t bytesRead;
    unsigned char buffer[MAX_BUFFER];

    inFile = fopen(input, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outFile = fopen(output, "wb");
    if (outFile == NULL) {
        fclose(inFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = fread(buffer, 1, MAX_BUFFER, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLen]; // XOR encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *key = argv[3];

    if (strlen(key) == 0) {
        fprintf(stderr, "Error: Key cannot be empty\n");
        return EXIT_FAILURE;
    }

    encrypt_decrypt(inputFile, outputFile, key);
    
    printf("Encryption/Decryption completed successfully.\n");
    return EXIT_SUCCESS;
}