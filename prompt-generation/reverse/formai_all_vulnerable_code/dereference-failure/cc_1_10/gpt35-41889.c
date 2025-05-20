//FormAI DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_INPUT_FILE_LENGTH 1000
#define MAX_OUTPUT_FILE_LENGTH 1100
#define MAX_PASSWORD_LENGTH 20

void encryptFile(FILE *inputFile, FILE *outputFile, char *password);
void decryptFile(FILE *inputFile, FILE *outputFile, char *password);
void printErrorAndExit(char *errorMessage);

int main(int argc, char *argv[]) {
    // Ensure correct number of command-line arguments
    if (argc != 5) {
        printErrorAndExit("Invalid arguments. Usage: ./file-encryptor [encrypt/decrypt] [input-file] [output-file] [password]");
    }

    char *operation = argv[1];
    char *inputFilename = argv[2];
    char *outputFilename = argv[3];
    char *password = argv[4];

    // Ensure operation argument is either "encrypt" or "decrypt"
    if (strcmp(operation, "encrypt") != 0 && strcmp(operation, "decrypt") != 0) {
        printErrorAndExit("Invalid operation argument. Must be either 'encrypt' or 'decrypt'.");
    }

    // Open input file for reading
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printErrorAndExit("Error opening input file.");
    }

    // Open output file for writing
    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printErrorAndExit("Error opening output file.");
    }

    // Encrypt or decrypt based on operation argument
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, password);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFile, outputFile, password);
    }

    printf("File operation complete.\n");

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

/**
 * Encrypts a file using a given password.
 */
void encryptFile(FILE *inputFile, FILE *outputFile, char *password) {
    char input[MAX_INPUT_FILE_LENGTH], output[MAX_OUTPUT_FILE_LENGTH];
    while (fgets(input, MAX_INPUT_FILE_LENGTH, inputFile)) {
        for (int i = 0; i < strlen(input); i++) {
            output[i] = (input[i] + password[i % strlen(password)]) % 128;
        }
        fprintf(outputFile, "%s", output);
    }
}

/**
 * Decrypts a file using a given password.
 */
void decryptFile(FILE *inputFile, FILE *outputFile, char *password) {
    char input[MAX_INPUT_FILE_LENGTH], output[MAX_OUTPUT_FILE_LENGTH];
    while (fgets(input, MAX_INPUT_FILE_LENGTH, inputFile)) {
        for (int i = 0; i < strlen(input); i++) {
            output[i] = (input[i] - password[i % strlen(password)]) % 128;
        }
        fprintf(outputFile, "%s", output);
    }
}

/**
 * Prints an error message and exits the program.
 */
void printErrorAndExit(char *errorMessage) {
    printf("Error: %s\n", errorMessage);
    exit(1);
}