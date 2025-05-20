//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert string to uppercase
void toUpperCase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to perform substitution encryption
char* substitutionEncrypt(char* message, char* key) {
    int len = strlen(message);
    char* encrypted = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        char letter = message[i];
        // Convert letter to uppercase for easy comparison
        toUpperCase(&letter);
        // Find position of letter in key
        int pos = strchr(key, letter) - key;
        if (pos < 0) {
            // If the letter is not in key, ignore it
            encrypted[i] = letter;
        } else {
            // Perform substitution
            encrypted[i] = 'A' + pos;
        }
    }
    return encrypted;
}

// Function to perform substitution decryption
char* substitutionDecrypt(char* message, char* key) {
    int len = strlen(message);
    char* decrypted = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        char letter = message[i];
        // Convert letter to uppercase for easy comparison
        toUpperCase(&letter);
        if (letter < 'A' || letter > 'Z') {
            // If the character is not a letter, ignore it
            decrypted[i] = letter;
        } else {
            // Find position of letter in key
            int pos = letter - 'A';
            if (pos >= strlen(key)) {
                // If the letter is not in key, ignore it
                decrypted[i] = letter;
            } else {
                // Perform reverse substitution
                decrypted[i] = key[pos];
            }
        }
    }
    return decrypted;
}

int main() {
    // Define key for substitution encryption
    char key[] = "RIPTOR";
    
    // Define message to encrypt
    char message[] = "Hello, world!";
    
    // Perform substitution encryption
    char* encrypted = substitutionEncrypt(message, key);
    
    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted);
    
    // Perform substitution decryption
    char* decrypted = substitutionDecrypt(encrypted, key);
    
    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted);
    
    // Free memory allocated by encrypted and decrypted strings
    free(encrypted);
    free(decrypted);
    
    return 0;
}