//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the text using XOR operation
void xorCipher(char *input, char *key, char *output) {
    int inputLength = strlen(input);
    int keyLength = strlen(key);
    
    for (int i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }
    output[inputLength] = '\0'; // Null-terminate the output string
}

// Function to write encrypted text to a file
void writeToFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Successfully wrote to the file: %s\n", filename);
}

// Function to read text from a file
void readFromFile(const char *filename, char *buffer, int bufferLength) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }
    fgets(buffer, bufferLength, file);
    fclose(file);
}

// Main program
int main() {
    char key[64];
    char plaintext[256];
    char encryptedText[256];
    char decryptedText[256];
    char filename[] = "encrypted.txt";

    // Prompt user for plaintext input
    printf("Enter the plaintext to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the newline character

    // Prompt user for a key
    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character

    // Encrypt the plaintext
    xorCipher(plaintext, key, encryptedText);
    printf("Encrypted text: %s\n", encryptedText);

    // Write encrypted text to the file
    writeToFile(filename, encryptedText);

    // Now let's decrypt the text
    readFromFile(filename, encryptedText, sizeof(encryptedText));
    xorCipher(encryptedText, key, decryptedText);
    printf("Decrypted text read from file: %s\n", decryptedText);

    // Thank you for trying this example! Enjoy your day!
    return 0;
}