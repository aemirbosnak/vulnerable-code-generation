//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Encrypt a single character using a simple XOR cipher
char encrypt_char(char ch, unsigned char key) {
    return ch ^ key;
}

// Encrypt a string using a simple XOR cipher
char *encrypt_string(char *str, unsigned char key) {
    char *encrypted = malloc(strlen(str) + 1);
    strcpy(encrypted, str);
    for (int i = 0; i < strlen(str); i++) {
        encrypted[i] = encrypt_char(str[i], key);
    }
    return encrypted;
}

// Decrypt a string using a simple XOR cipher
char *decrypt_string(char *str, unsigned char key) {
    char *decrypted = malloc(strlen(str) + 1);
    strcpy(decrypted, str);
    for (int i = 0; i < strlen(str); i++) {
        decrypted[i] = encrypt_char(str[i], key);
    }
    return decrypted;
}

int main() {
    
    // Get a random seed from the system clock
    srand(time(NULL));

    // Generate a random key
    unsigned char key = rand() % 256;

    // Get the message to be encrypted
    char message[100];
    printf("Enter a message to encrypt: ");
    gets(message);

    // Encrypt the message
    char *encrypted_message = encrypt_string(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    char *decrypted_message = decrypt_string(encrypted_message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}