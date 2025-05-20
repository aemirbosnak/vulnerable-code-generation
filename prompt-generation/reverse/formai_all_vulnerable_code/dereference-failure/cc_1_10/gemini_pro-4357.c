//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key
unsigned int generate_key(void) {
    srand(time(NULL));
    return rand();
}

// Function to encrypt a message
char *encrypt(char *message, unsigned int key) {
    char *encrypted_message = malloc(strlen(message) + 1);
    int i;
    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key;
    }
    encrypted_message[i] = '\0';
    return encrypted_message;
}

// Function to decrypt a message
char *decrypt(char *encrypted_message, unsigned int key) {
    char *decrypted_message = malloc(strlen(encrypted_message) + 1);
    int i;
    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key;
    }
    decrypted_message[i] = '\0';
    return decrypted_message;
}

int main() {
    // Generate a random key
    unsigned int key = generate_key();

    // Get the message to be encrypted
    char *message = "Hello, world!";

    // Encrypt the message
    char *encrypted_message = encrypt(message, key);

    // Decrypt the message
    char *decrypted_message = decrypt(encrypted_message, key);

    // Print the original, encrypted, and decrypted messages
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}