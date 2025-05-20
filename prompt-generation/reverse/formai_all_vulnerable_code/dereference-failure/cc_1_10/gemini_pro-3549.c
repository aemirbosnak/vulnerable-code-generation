//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using XOR cipher
void encryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input and output files
    FILE *in = fopen(inputFile, "rb");
    FILE *out = fopen(outputFile, "wb");

    // Get the length of the key
    int keyLen = strlen(key);

    // Read the input file and encrypt it
    int ch;
    int i = 0;
    while ((ch = fgetc(in)) != EOF) {
        // Apply XOR encryption
        ch ^= key[i];
        i = (i + 1) % keyLen;

        // Write the encrypted byte to the output file
        fputc(ch, out);
    }

    // Close the files
    fclose(in);
    fclose(out);
}

// Function to decrypt a file using XOR cipher
void decryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input and output files
    FILE *in = fopen(inputFile, "rb");
    FILE *out = fopen(outputFile, "wb");

    // Get the length of the key
    int keyLen = strlen(key);

    // Read the input file and decrypt it
    int ch;
    int i = 0;
    while ((ch = fgetc(in)) != EOF) {
        // Apply XOR decryption
        ch ^= key[i];
        i = (i + 1) % keyLen;

        // Write the decrypted byte to the output file
        fputc(ch, out);
    }

    // Close the files
    fclose(in);
    fclose(out);
}

// Function to get the password from the user
char *getPassword() {
    char *password = (char *)malloc(sizeof(char) * 100);
    printf("Enter the password: ");
    scanf("%s", password);
    return password;
}

// Main function
int main() {
    // Get the input and output file names
    char inputFile[100], outputFile[100];
    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    // Get the password
    char *password = getPassword();

    // Encrypt the file
    encryptFile(inputFile, outputFile, password);

    // Decrypt the file
    decryptFile(outputFile, "decrypted.txt", password);

    // Free the allocated memory
    free(password);

    return 0;
}