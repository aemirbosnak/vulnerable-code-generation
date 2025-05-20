//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

void xorCipher(char *input, char *output, const char *key) {
    size_t inputLength = strlen(input);
    size_t keyLength = strlen(key);
    
    for (size_t i = 0; i < inputLength; i++) {
        output[i] = input[i] ^ key[i % keyLength]; // XOR operation
    }
    output[inputLength] = '\0'; // Null-terminate the output string
}

void promptForInput(char *buffer, const char *prompt, size_t length) {
    printf("%s", prompt);
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int main() {
    char input[MAX_TEXT_LENGTH];
    char encrypted[MAX_TEXT_LENGTH];
    char decrypted[MAX_TEXT_LENGTH];
    char key[MAX_TEXT_LENGTH];

    printf("Simple XOR Encryption and Decryption Program\n");
    
    // Prompt user for the message to encrypt
    promptForInput(input, "Enter the message to encrypt: ", MAX_TEXT_LENGTH);
    
    // Prompt user for the encryption key
    promptForInput(key, "Enter the encryption key: ", MAX_TEXT_LENGTH);
    
    // Encrypt the message
    xorCipher(input, encrypted, key);
    
    printf("Encrypted message: %s\n", encrypted);
    
    // Decrypt the message using the same key
    xorCipher(encrypted, decrypted, key);
    
    printf("Decrypted message: %s\n", decrypted);
    
    // Prevent buffer overflow for very long inputs
    if (strlen(encrypted) >= MAX_TEXT_LENGTH || strlen(decrypted) >= MAX_TEXT_LENGTH) {
        fprintf(stderr, "Error: Input or output message too long!\n");
        return 1;
    }

    return 0;
}