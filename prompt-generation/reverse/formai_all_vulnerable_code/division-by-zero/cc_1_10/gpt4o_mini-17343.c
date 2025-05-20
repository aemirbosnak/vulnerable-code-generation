//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform XOR encryption/decryption
void xorEncryptDecrypt(char *input, char *key, char *output) {
    size_t inputLen = strlen(input);
    size_t keyLen = strlen(key);
    
    for (size_t i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    output[inputLen] = '\0'; // Null terminate the output string
}

// Function to process user input and call the encryption and decryption
void processInput() {
    char plaintext[256];
    char key[256];
    char encrypted[256];
    char decrypted[256];
    
    printf("Welcome to the Introspective XOR Encryption Program\n");
    printf("Please enter a message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the trailing newline character
    
    printf("Please enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the trailing newline character

    printf("\nYou entered the plaintext: \"%s\"\n", plaintext);
    printf("You entered the key: \"%s\"\n", key);
    
    // Encrypting the message
    xorEncryptDecrypt(plaintext, key, encrypted);
    printf("\nEncrypted message: \"%s\"\n", encrypted);
    
    // Decrypting the message
    xorEncryptDecrypt(encrypted, key, decrypted);
    printf("Decrypted message: \"%s\"\n", decrypted);
}

int main() {
    // Providing some context
    printf("Introspection is key in understanding our encryption\n");
    printf("Encryption transforms our original data into a secured format\n");
    
    processInput();
    
    printf("\nThanks for using the XOR Encryption Program!\n");
    return 0;
}