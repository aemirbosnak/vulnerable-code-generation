//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char* encrypt(char* message, int key) {
    int messageLength = strlen(message);
    char* encryptedMessage = malloc(messageLength + 1); // Allocate memory for encrypted message
    
    for (int i = 0; i < messageLength; i++) {
        char currentChar = message[i];
        
        // Encrypt character by shifting it by the key
        if (isalpha(currentChar)) { // Check if character is a letter
            int shiftedChar = currentChar + key;
            
            // Wrap around if necessary
            if (isupper(currentChar) && shiftedChar > 'Z') {
                shiftedChar -= 26;
            } else if (islower(currentChar) && shiftedChar > 'z') {
                shiftedChar -= 26;
            }
            
            encryptedMessage[i] = shiftedChar;
        } else { // If not a letter, just copy it
            encryptedMessage[i] = currentChar;
        }
    }
    
    encryptedMessage[messageLength] = '\0'; // Null-terminate encrypted message
    return encryptedMessage;
}


// Custom decryption function
char* decrypt(char* encryptedMessage, int key) {
    int messageLength = strlen(encryptedMessage);
    char* decryptedMessage = malloc(messageLength + 1); // Allocate memory for decrypted message
    
    for (int i = 0; i < messageLength; i++) {
        char currentChar = encryptedMessage[i];
        
        // Decrypt character by shifting it back by the key
        if (isalpha(currentChar)) { // Check if character is a letter
            int shiftedChar = currentChar - key;
            
            // Wrap around if necessary
            if (isupper(currentChar) && shiftedChar < 'A') {
                shiftedChar += 26;
            } else if (islower(currentChar) && shiftedChar < 'a') {
                shiftedChar += 26;
            }
            
            decryptedMessage[i] = shiftedChar;
        } else { // If not a letter, just copy it
            decryptedMessage[i] = currentChar;
        }
    }
    
    decryptedMessage[messageLength] = '\0'; // Null-terminate decrypted message
    return decryptedMessage;
}


// Main function to test encryption and decryption
int main() {
    // Original message
    char message[] = "Hello, World!";
    
    // Encryption key
    int key = 3;
    
    // Encrypt message
    char* encryptedMessage = encrypt(message, key);
    printf("Encrypted Message: %s\n", encryptedMessage);
    
    // Decrypt encrypted message
    char* decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted Message: %s\n", decryptedMessage);
    
    // Free allocated memory
    free(encryptedMessage);
    free(decryptedMessage);
    
    return 0;
}