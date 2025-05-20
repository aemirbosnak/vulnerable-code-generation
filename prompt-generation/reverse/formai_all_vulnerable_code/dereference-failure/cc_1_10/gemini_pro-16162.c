//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char* encrypt(char* plaintext, char* key) {
    // Allocate memory for the ciphertext
    char* ciphertext = malloc(strlen(plaintext) + 1);
    
    // Iterate over the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Apply the encryption algorithm
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    
    // Terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';
    
    // Return the encrypted ciphertext
    return ciphertext;
}

// Custom decryption function
char* decrypt(char* ciphertext, char* key) {
    // Allocate memory for the decrypted text
    char* decryptedText = malloc(strlen(ciphertext) + 1);
    
    // Iterate over the ciphertext
    for (int i = 0; i < strlen(ciphertext); i++) {
        // Apply the decryption algorithm
        decryptedText[i] = ciphertext[i] ^ key[i % strlen(key)];
    }
    
    // Terminate the decrypted text
    decryptedText[strlen(ciphertext)] = '\0';
    
    // Return the decrypted text
    return decryptedText;
}

int main() {
    // Define the plaintext and key
    char* plaintext = "This is a secret message!";
    char* key = "MySecretPassword";
    
    // Encrypt the plaintext using the custom encryption function
    char* ciphertext = encrypt(plaintext, key);
    
    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    printf("Press any key to decrypt ...\n");
    getchar();
    
    // Decrypt the ciphertext using the custom decryption function
    char* decryptedText = decrypt(ciphertext, key);
    
    // Print the decrypted text
    printf("Decrypted Text: %s\n", decryptedText);
    
    // Free the allocated memory
    free(ciphertext);
    free(decryptedText);
    
    return 0;
}