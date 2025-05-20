//FormAI DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_KEY_LENGTH 16
#define ENCRYPTION_KEY "myencryptionkey"

void encryptFile(FILE* inputFile, FILE* outputFile, char* key);
void decryptFile(FILE* inputFile, FILE* outputFile, char* key);

int main(int argc, char* argv[]) {

    char inputFileName[MAX_FILE_NAME_LENGTH];
    char outputFileName[MAX_FILE_NAME_LENGTH];

    if (argc != 4) {
        printf("Usage: %s <input_file_name> <output_file_name> <0 for encryption, 1 for decryption>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(inputFileName, argv[1]);
    strcpy(outputFileName, argv[2]);

    int selectedOption = atoi(argv[3]);
    if (selectedOption != 0 && selectedOption != 1) {
        printf("Invalid option selected. Please select 0 for encryption, 1 for decryption.\n");
        exit(EXIT_FAILURE);
    }

    FILE* inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(EXIT_FAILURE);
    }

    char key[MAX_KEY_LENGTH];
    strcpy(key, ENCRYPTION_KEY);

    if (selectedOption == 0) {
        encryptFile(inputFile, outputFile, key);
        printf("Encryption complete.\n");
    } else {
        decryptFile(inputFile, outputFile, key);
        printf("Decryption complete.\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void encryptFile(FILE* inputFile, FILE* outputFile, char* key) {

    srand(time(NULL));
    int randomSeed = rand() % 1000;

    int bytesRead = 0;
    char buffer[1024];
    int bufferIndex = 0;

    // Write the random seed to the output file
    fwrite(&randomSeed, sizeof(int), 1, outputFile);

    // Write the length of the encryption key to the output file
    int keyLength = strlen(key);
    fwrite(&keyLength, sizeof(int), 1, outputFile);

    // Write the encryption key to the output file
    fwrite(key, sizeof(char), keyLength, outputFile);

    // Read the input file and encrypt each byte using the XOR operator with a random value generated from the seed
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), inputFile)) > 0) {
        for (bufferIndex = 0; bufferIndex < bytesRead; bufferIndex++) {
            char encryptedByte = buffer[bufferIndex] ^ (randomSeed & 0xff);
            fwrite(&encryptedByte, sizeof(char), 1, outputFile);
            randomSeed = (randomSeed * 1103515245 + 12345) & 0x7fffffff;
        }
    }
}

void decryptFile(FILE* inputFile, FILE* outputFile, char* key) {

    int randomSeed = 0;
    int keyLength = 0;
    char buffer[1024];
    int bytesRead = 0;
    int bufferIndex = 0;

    // Read the random seed from the input file
    fread(&randomSeed, sizeof(int), 1, inputFile);

    // Read the length of the encryption key from the input file
    fread(&keyLength, sizeof(int), 1, inputFile);

    // Read the encryption key from the input file
    char encryptionKey[MAX_KEY_LENGTH];
    fread(encryptionKey, sizeof(char), keyLength, inputFile);

    // Check if the encryption key in the input file matches the passed key
    if (strcmp(encryptionKey, key) != 0) {
        printf("Invalid encryption key.\n");
        exit(EXIT_FAILURE);
    }

    // Read the encrypted bytes from the input file and decrypt each byte using the XOR operator with the random value generated from the seed
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), inputFile)) > 0) {
        for (bufferIndex = 0; bufferIndex < bytesRead; bufferIndex++) {
            char decryptedByte = buffer[bufferIndex] ^ (randomSeed & 0xff);
            fwrite(&decryptedByte, sizeof(char), 1, outputFile);
            randomSeed = (randomSeed * 1103515245 + 12345) & 0x7fffffff;
        }
    }
}