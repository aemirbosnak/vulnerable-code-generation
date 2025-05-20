//FormAI DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt the given message using our custom modern encryption algorithm
char* EncryptMessage(const char* message) {
    int len = strlen(message);
    char* encrypted = (char*) malloc((len+1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        // Our algorithm simply XORs each character with the number 42
        encrypted[i] = message[i] ^ 42;
    }
    encrypted[len] = '\0';
    
    return encrypted;
}

// Decrypt the given message that was encrypted using our modern encryption algorithm
char* DecryptMessage(const char* message) {
    int len = strlen(message);
    char* decrypted = (char*) malloc((len+1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        // To decrypt, we simply XOR again with the same number (42)
        decrypted[i] = message[i] ^ 42;
    }
    decrypted[len] = '\0';
    
    return decrypted;
}

// Main function for testing out our encryption functions
int main() {
    printf("Please enter a message to encrypt: ");
    char message[100];
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline character at end of input
    
    char* encrypted = EncryptMessage(message);
    printf("Encrypted message: %s\n", encrypted);
    
    char* decrypted = DecryptMessage(encrypted);
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    
    return 0;
}