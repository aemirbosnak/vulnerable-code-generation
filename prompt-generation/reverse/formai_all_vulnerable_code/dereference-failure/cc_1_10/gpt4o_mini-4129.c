//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt data using XOR cipher
void xorCipher(char *data, char *key) {
    int dataLength = strlen(data);
    int keyLength = strlen(key);
    
    for (int i = 0; i < dataLength; i++) {
        data[i] ^= key[i % keyLength];  // XOR operation
    }
}

// Function to read data from file
char* readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = (char *)malloc(length + 1);
    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the string
    
    fclose(file);
    return buffer;
}

// Function to write data to file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }
    
    fputs(data, file);
    fclose(file);
}

// Main function
int main() {
    char *inputFilename = "plaintext.txt";
    char *outputFilename = "ciphertext.txt";
    char *decryptedFilename = "decrypted.txt";
    char *key = "mysecretkey"; // This key should be kept secure!
    
    // Step 1: Read data from the input file
    char *data = readFile(inputFilename);
    printf("Original Data:\n%s\n\n", data);
    
    // Step 2: Encrypting the data
    printf("Encrypting the data...\n");
    xorCipher(data, key);
    writeFile(outputFilename, data);
    printf("Data encrypted and written to %s!\n", outputFilename);
    
    // Step 3: Decrypting the data
    printf("Decrypting the data...\n");
    xorCipher(data, key);
    writeFile(decryptedFilename, data);
    printf("Data decrypted and written to %s!\n", decryptedFilename);
    
    // Free allocated memory
    free(data);
    
    return 0;
}