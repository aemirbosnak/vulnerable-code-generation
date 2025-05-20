//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Our super secret encryption key
#define SECRET_KEY "HappyEncryption!"

// Encrypt a message using XOR encryption
char *encrypt(const char *message) {
    // Allocate memory for the encrypted message
    char *encrypted_message = malloc(strlen(message) + 1);
    
    // Get the length of the message
    size_t message_len = strlen(message);
    
    // Loop through each character in the message
    for (size_t i = 0; i < message_len; i++) {
        // XOR the character with the secret key
        encrypted_message[i] = message[i] ^ SECRET_KEY[i % strlen(SECRET_KEY)];
    }
    
    // Terminate the encrypted message with a null character
    encrypted_message[message_len] = '\0';
    
    // Return the encrypted message
    return encrypted_message;
}

// Decrypt a message using XOR encryption
char *decrypt(const char *encrypted_message) {
    // Allocate memory for the decrypted message
    char *decrypted_message = malloc(strlen(encrypted_message) + 1);
    
    // Get the length of the encrypted message
    size_t encrypted_message_len = strlen(encrypted_message);
    
    // Loop through each character in the encrypted message
    for (size_t i = 0; i < encrypted_message_len; i++) {
        // XOR the character with the secret key
        decrypted_message[i] = encrypted_message[i] ^ SECRET_KEY[i % strlen(SECRET_KEY)];
    }
    
    // Terminate the decrypted message with a null character
    decrypted_message[encrypted_message_len] = '\0';
    
    // Return the decrypted message
    return decrypted_message;
}

int main() {
    // Let's start by getting a message from the user
    printf("Enter a message to encrypt: ");
    char message[1024];
    fgets(message, sizeof(message), stdin);
    
    // Encrypt the message
    char *encrypted_message = encrypt(message);
    
    // Print the encrypted message
    printf("Encrypted message: %s", encrypted_message);

    // Decrypt the encrypted message
    char *decrypted_message = decrypt(encrypted_message);
    
    // Print the decrypted message
    printf("Decrypted message: %s", decrypted_message);
    
    // Free the allocated memory
    free(encrypted_message);
    free(decrypted_message);
    
    return 0;
}