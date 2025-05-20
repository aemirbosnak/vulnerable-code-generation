//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        fclose(inFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read from the input file and write to the output file
    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;  // XOR encryption/decryption
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void print_usage(char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    char key = argv[4][0];  // Use the first character of the key string

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_decrypt(inputFile, outputFile, key);
        printf("File encrypted successfully: %s\n", outputFile);
    } else if (strcmp(mode, "decrypt") == 0) {
        encrypt_decrypt(inputFile, outputFile, key);
        printf("File decrypted successfully: %s\n", outputFile);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}