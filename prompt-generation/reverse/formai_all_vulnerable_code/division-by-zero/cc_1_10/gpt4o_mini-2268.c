//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, char *key) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);
    
    for (int i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    output[inputLen] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output, char *key) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);
    
    for (int i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    output[inputLen] = '\0'; // Null-terminate the output string
}

int main() {
    char key[50];
    char originalText[100];
    char encryptedText[100];
    char decryptedText[100];

    // User input for key and text
    printf("Enter the encryption key (max 50 characters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    printf("Enter the text to encrypt (max 100 characters): ");
    fgets(originalText, sizeof(originalText), stdin);
    originalText[strcspn(originalText, "\n")] = 0; // Remove newline character

    // Encrypt the text
    encrypt(originalText, encryptedText, key);
    printf("Encrypted Text: ");
    for (int i = 0; i < strlen(originalText); i++) {
        printf("%02X", (unsigned char)encryptedText[i]); // Print as hex
    }
    printf("\n");

    // Decrypt the text
    decrypt(encryptedText, decryptedText, key);
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}