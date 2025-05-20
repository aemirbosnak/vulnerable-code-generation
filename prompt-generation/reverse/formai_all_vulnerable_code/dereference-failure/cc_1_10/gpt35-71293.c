//FormAI DATASET v1.0 Category: File Encyptor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

void encrypt(char* inputFilePath, char* outputFilePath, char* encryptionKey)
{
    FILE* inputFile = fopen(inputFilePath, "rb");
    FILE* outputFile = fopen(outputFilePath, "wb");

    if (inputFile && outputFile) {
        char buffer[MAX_FILE_SIZE];
        size_t bytesRead = 0;
        size_t fileSize = 0;

        // Read the input file into a buffer
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
            fileSize += bytesRead;

            // Encrypt the buffer with the encryption key
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = buffer[i] ^ encryptionKey[i % strlen(encryptionKey)];
            }

            // Write the encrypted buffer to the output file
            fwrite(buffer, 1, bytesRead, outputFile);
        }

        fclose(inputFile);
        fclose(outputFile);
        printf("File encrypted successfully.\n");
    } else {
        printf("Error: Unable to open file.\n");
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Invalid arguments: Usage ./encrypt inputFilePath outputFilePath encryptionKey\n");
        exit(EXIT_FAILURE);
    }

    char* inputFilePath = argv[1];
    char* outputFilePath = argv[2];
    char* encryptionKey = argv[3];

    encrypt(inputFilePath, outputFilePath, encryptionKey);

    return 0;
}