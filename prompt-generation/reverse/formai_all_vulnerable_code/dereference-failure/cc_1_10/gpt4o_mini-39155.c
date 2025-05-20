//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the data
void encrypt(char *data, int shift) {
    for (int i = 0; data[i] != '\0'; i++) {
        // Only encrypt alphabetic characters
        if ((data[i] >= 'A' && data[i] <= 'Z')) {
            data[i] = (data[i] - 'A' + shift) % 26 + 'A';
        } else if ((data[i] >= 'a' && data[i] <= 'z')) {
            data[i] = (data[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the data
void decrypt(char *data, int shift) {
    encrypt(data, 26 - shift); // Reusing the encrypt function for decryption
}

// Function to read from a file
char* readFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open the file!");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *data = (char *)malloc(length + 1);
    if (data == NULL) {
        perror("Failed to allocate memory!");
        exit(EXIT_FAILURE);
    }
    fread(data, 1, length, file);
    data[length] = '\0';
    fclose(file);
    
    return data;
}

// Function to write to a file
void writeFile(const char* filename, const char* data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open the file for writing!");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", data);
    fclose(file);
}

// Function to display usage information
void displayUsage(const char* programName) {
    printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <shift>\n", programName);
    printf("Example: %s encrypt myfile.txt myfile.enc 4\n", programName);
    printf("Example: %s decrypt myfile.enc myfile.txt 4\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *action = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    int shift = atoi(argv[4]);
    
    // Reading data from the input file
    char *data = readFile(inputFile);
    
    if (strcmp(action, "encrypt") == 0) {
        printf("Encrypting file: %s\n", inputFile);
        encrypt(data, shift);
        writeFile(outputFile, data);
        printf("Encryption complete! Saved to: %s\n", outputFile);
    } else if (strcmp(action, "decrypt") == 0) {
        printf("Decrypting file: %s\n", inputFile);
        decrypt(data, shift);
        writeFile(outputFile, data);
        printf("Decryption complete! Saved to: %s\n", outputFile);
    } else {
        printf("Invalid action. Please choose 'encrypt' or 'decrypt'.\n");
        free(data);
        return EXIT_FAILURE;
    }

    // Clean up and free memory
    free(data);
    return EXIT_SUCCESS;
}