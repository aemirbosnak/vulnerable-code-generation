//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the input text using XOR with the key
void xorCipher(const char *input, const char *key, char *output) {
    size_t inputLength = strlen(input);
    size_t keyLength = strlen(key);

    for (size_t i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }
    output[inputLength] = '\0'; // Null terminate the output string
}

// Function to read a file's content and return it as a string
char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *) malloc(length + 1);
    if (!content) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(content, 1, length, file);
    content[length] = '\0'; // Null terminate the content
    fclose(file);
    return content;
}

// Function to write a string to a file
void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}

// Main function to drive the program
int main() {
    char key[256];

    printf("Enter encryption/decryption key: ");
    scanf("%s", key);

    char inputFile[100], outputFile[100];
    int choice;

    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Choose an option (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter input file name to encrypt: ");
        scanf("%s", inputFile);
        printf("Enter output file name for encrypted text: ");
        scanf("%s", outputFile);

        char *inputText = readFile(inputFile);
        if (inputText) {
            char *encryptedText = (char *) malloc(strlen(inputText) + 1);
            xorCipher(inputText, key, encryptedText);
            writeFile(outputFile, encryptedText);

            printf("File encrypted successfully: %s\n", outputFile);
            free(encryptedText);
            free(inputText);
        }
    } else if (choice == 2) {
        printf("Enter input file name to decrypt: ");
        scanf("%s", inputFile);
        printf("Enter output file name for decrypted text: ");
        scanf("%s", outputFile);

        char *encryptedText = readFile(inputFile);
        if (encryptedText) {
            char *decryptedText = (char *) malloc(strlen(encryptedText) + 1);
            xorCipher(encryptedText, key, decryptedText);
            writeFile(outputFile, decryptedText);

            printf("File decrypted successfully: %s\n", outputFile);
            free(decryptedText);
            free(encryptedText);
        }
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}