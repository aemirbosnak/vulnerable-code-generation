//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* encrypt(char* message, int key) {
    // Calculate the length of the message
    int length = strlen(message);
    
    // Allocate space for the encrypted message and null terminator
    char* encrypted = (char*)malloc((length+1) * sizeof(char));
    
    // Iterate over each character in the message
    for(int i=0; i<length; i++) {
        // Convert the character to its ASCII code
        int ascii = (int)message[i];
        
        // Encrypt the character using the key
        ascii = (ascii + key) % 127;
        
        // Convert the encrypted ASCII code back to a character
        char encryptedChar = (char)ascii;
        
        // Add the encrypted character to the encrypted message
        encrypted[i] = encryptedChar;
    }
    
    // Add the null terminator to the end of the encrypted message
    encrypted[length] = '\0';
    
    return encrypted;
}

char* decrypt(char* message, int key) {
    // Calculate the length of the message
    int length = strlen(message);
    
    // Allocate space for the decrypted message and null terminator
    char* decrypted = (char*)malloc((length+1) * sizeof(char));
    
    // Iterate over each character in the message
    for(int i=0; i<length; i++) {
        // Convert the character to its ASCII code
        int ascii = (int)message[i];
        
        // Decrypt the character using the key
        ascii = (ascii - key + 127) % 127;
        
        // Convert the decrypted ASCII code back to a character
        char decryptedChar = (char)ascii;
        
        // Add the decrypted character to the decrypted message
        decrypted[i] = decryptedChar;
    }
    
    // Add the null terminator to the end of the decrypted message
    decrypted[length] = '\0';
    
    return decrypted;
}

int main() {
    // Take input message from the user
    char message[100];
    printf("Enter the message you want to encrypt: ");
    fgets(message, 100, stdin);
    
    // Take input key from the user
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    // Encrypt the message using the key
    char* encryptedMessage = encrypt(message, key);
    printf("Encrypted message: %s", encryptedMessage);
    
    // Decrypt the message using the key
    char* decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted message: %s", decryptedMessage);
    
    // Free the memory allocated for the encrypted and decrypted messages
    free(encryptedMessage);
    free(decryptedMessage);
    
    return 0;
}