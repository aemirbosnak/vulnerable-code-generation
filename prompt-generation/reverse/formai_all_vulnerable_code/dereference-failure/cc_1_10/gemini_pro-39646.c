//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "MySecretKey"

// Function to encrypt a string using the XOR cipher
char* encrypt(char* plaintext) {
    // Allocate memory for the ciphertext
    char* ciphertext = malloc(strlen(plaintext) + 1);
    
    // Iterate over each character in the plaintext
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        // XOR the character with the key
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }
    
    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';
    
    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string using the XOR cipher
char* decrypt(char* ciphertext) {
    // Allocate memory for the plaintext
    char* plaintext = malloc(strlen(ciphertext) + 1);
    
    // Iterate over each character in the ciphertext
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        // XOR the character with the key
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }
    
    // Terminate the plaintext with a null character
    plaintext[strlen(ciphertext)] = '\0';
    
    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char* plaintext = malloc(100);
    printf("Enter the plaintext to encrypt: ");
    gets(plaintext);
    
    // Encrypt the plaintext
    char* ciphertext = encrypt(plaintext);
    
    // Print the ciphertext
    printf("The ciphertext is: %s\n", ciphertext);
    
    // Decrypt the ciphertext
    char* decryptedText = decrypt(ciphertext);
    
    // Print the decrypted text
    printf("The decrypted text is: %s\n", decryptedText);
    
    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedText);
    
    return 0;
}