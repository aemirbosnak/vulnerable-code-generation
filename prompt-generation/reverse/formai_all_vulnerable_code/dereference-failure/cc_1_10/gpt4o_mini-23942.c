//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KEY_SIZE 256  // Keystream size
#define BUFFER_SIZE 1024 // Buffer for file IO

// Function to generate a simple keystream for encryption
void generateKeystream(unsigned char *keystream, size_t length) {
    for (size_t i = 0; i < length; i++) {
        keystream[i] = rand() % 256; // Random byte
    }
}

// Function to encrypt the data
void encryptData(const unsigned char *inData, unsigned char *outData, unsigned char *keystream, size_t length) {
    for (size_t i = 0; i < length; i++) {
        outData[i] = inData[i] ^ keystream[i]; // XOR encryption
    }
}

// Function to read the file content
size_t readFile(const char *filePath, unsigned char **buffer) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    *buffer = (unsigned char *)malloc(fileSize);
    if (!*buffer) {
        perror("Memory allocation failure");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, fileSize, file);
    fclose(file);
    return fileSize;
}

// Function to write the encrypted data to a file
void writeFile(const char *filePath, const unsigned char *buffer, size_t length) {
    FILE *file = fopen(filePath, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, 1, length, file);
    fclose(file);
}

// Function to print usage instructions
void printUsage(const char *programName) {
    printf("Usage: %s <input_file> <output_file>\n", programName);
    printf("Encrypt the input file and output to the specified output file.\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];

    // Read data from input file
    unsigned char *inputData;
    size_t inputLength = readFile(inputFile, &inputData);

    // Create a keystream for encryption
    unsigned char keystream[KEY_SIZE];
    generateKeystream(keystream, inputLength);

    // Prepare an output buffer for encrypted data
    unsigned char *encryptedData = (unsigned char *)malloc(inputLength);
    if (!encryptedData) {
        perror("Memory allocation failure for encrypted data");
        free(inputData);
        return EXIT_FAILURE;
    }

    // Encrypt the data
    encryptData(inputData, encryptedData, keystream, inputLength);

    // Write the encrypted data to the output file
    writeFile(outputFile, encryptedData, inputLength);

    // Clean up
    free(inputData);
    free(encryptedData);

    printf("Encryption completed successfully. Output written to: %s\n", outputFile);
    return EXIT_SUCCESS;
}