//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the input text
void xorCipher(char *input, char *output, char *key) {
    int inputLength = strlen(input);
    int keyLength = strlen(key);
    for (int i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength]; // XOR operation
    }
    output[inputLength] = '\0'; // Null-terminate the output string
}

// Function to read the input from a file
char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file!");
        return NULL;
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

// Function to write output to a file
void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file!");
        return;
    }
    fputs(data, file);
    fclose(file);
}

// Main function
int main() {
    char *text, *encryptedText, *decryptedText, key[256];
    char filename[256];

    printf("Enter the encryption key (up to 255 characters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    printf("Enter the filename to read text from: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline
    
    text = readFile(filename);
    if (!text) {
        return 1; // Exit on read failure
    }

    encryptedText = (char *)malloc(strlen(text) + 1);
    decryptedText = (char *)malloc(strlen(text) + 1);

    // Encrypt the text
    xorCipher(text, encryptedText, key);
    printf("Encrypted Text: %s\n", encryptedText);

    // Write encrypted text to a file
    writeFile("encrypted.txt", encryptedText);

    // Decrypt the text
    xorCipher(encryptedText, decryptedText, key);
    printf("Decrypted Text: %s\n", decryptedText);

    // Write decrypted text to a file
    writeFile("decrypted.txt", decryptedText);

    // Free allocated memory
    free(text);
    free(encryptedText);
    free(decryptedText);

    printf("Encryption and Decryption completed successfully!\n");
    return 0;
}