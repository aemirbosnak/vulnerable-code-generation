//FormAI DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a given string
char* encryptString(char *str, int key) {
    // Calculate the length of the string
    int len = strlen(str);
    
    // Create a buffer to hold the encrypted string
    char *encrypted = (char*) malloc(len * sizeof(char));
    
    // Iterate over each character in the string
    for(int i=0; i<len; i++) {
        // Apply the encryption algorithm to the character
        encrypted[i] = str[i] + key;
    }
    
    // Null terminate the encrypted string
    encrypted[len] = '\0';
    
    // Return the encrypted string
    return encrypted;
}

// Function to decrypt a given string
char* decryptString(char *str, int key) {
    // Calculate the length of the string
    int len = strlen(str);
    
    // Create a buffer to hold the decrypted string
    char *decrypted = (char*) malloc(len * sizeof(char));
    
    // Iterate over each character in the string
    for(int i=0; i<len; i++) {
        // Apply the decryption algorithm to the character
        decrypted[i] = str[i] - key;
    }
    
    // Null terminate the decrypted string
    decrypted[len] = '\0';
    
    // Return the decrypted string
    return decrypted;
}

int main() {
    char *str = "hello world";
    int key = 10;
    
    // Encrypt the string using the key
    char *encrypted = encryptString(str, key);
    
    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted);
    
    // Decrypt the string using the key
    char *decrypted = decryptString(encrypted, key);
    
    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted);
    
    // Free the memory used by the strings
    free(encrypted);
    free(decrypted);
    
    return 0;
}