//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char key) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inputFile)) > 0) {
        for(size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;  // XOR encryption/decryption
        }
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }
}

void printUsage() {
    printf("Usage: file_encryptor <encrypt|decrypt> <input_file> <output_file> <key>\n");
    printf("Example: file_encryptor encrypt myfile.txt myfile.enc 'A'\n");
    printf("         file_encryptor decrypt myfile.enc myfile.txt 'A'\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage();
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];
    char key = argv[4][0];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "encrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File encrypted successfully!\n");
    } else if (strcmp(mode, "decrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File decrypted successfully!\n");
    } else {
        printUsage();
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}