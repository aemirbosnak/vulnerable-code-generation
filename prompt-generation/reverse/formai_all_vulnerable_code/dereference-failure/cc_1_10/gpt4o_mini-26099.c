//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encryptFile(const char *inputFile, const char *outputFile, const char *key);
void decryptFile(const char *inputFile, const char *outputFile, const char *key);
void xorOperation(FILE *input, FILE *output, const char *key);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *operation = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    const char *key = argv[4];

    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, key);
        printf("File encrypted successfully to %s.\n", outputFile);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFile, outputFile, key);
        printf("File decrypted successfully to %s.\n", outputFile);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Encrypts the input file using XOR operation and writes to the output file
void encryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    if (!input || !output) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    xorOperation(input, output, key);
    fclose(input);
    fclose(output);
}

// Decrypts the input file using XOR operation and writes to the output file
void decryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    if (!input || !output) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    xorOperation(input, output, key);
    fclose(input);
    fclose(output);
}

// Performs the XOR operation for encrypting and decrypting files
void xorOperation(FILE *input, FILE *output, const char *key) {
    size_t keyLen = strlen(key);
    int keyIndex = 0;
    
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // XOR the character with the corresponding character in the key
        fputc(ch ^ key[keyIndex], output);
        keyIndex = (keyIndex + 1) % keyLen; // Wrap around the key
    }
}

// Function to generate a random key for encryption (optional)
// You can uncomment and modify to use a generated key instead of a user-provided one
/*
void generateRandomKey(char *key, size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (size_t i = 0; i < length - 1; i++) {
        int keyIndex = rand() % (sizeof(charset) - 1);
        key[i] = charset[keyIndex];
    }
    key[length - 1] = '\0'; // Null-terminate the string
}
*/

// Example to write usage information
void usage(const char *progName) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", progName);
    printf("Encrypts or decrypts the specified input file using a simple XOR cipher.\n");
    printf("Example: %s encrypt myfile.txt myfile.enc mysecretkey\n", progName);
    printf("Example: %s decrypt myfile.enc myfile.txt mysecretkey\n", progName);
}

// Enhanced error handling of file operations
void errorHandling(FILE *file, const char *filename) {
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

// Function to measure the execution time (Optional)
void measureExecutionTime() {
    // Implementation left as an exercise for the reader
    // This function can use the clock() function from time.h to measure time taken for execution 
}