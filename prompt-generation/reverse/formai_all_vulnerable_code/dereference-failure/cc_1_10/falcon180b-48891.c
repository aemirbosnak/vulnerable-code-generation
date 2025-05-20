//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key of specified length
void generate_key(char* key, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?~";
    int i;
    for (i = 0; i < length; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[length] = '\0';
}

// Function to encrypt a message using the key
void encrypt(char* message, char* key) {
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }
}

// Function to decrypt an encrypted message using the key
void decrypt(char* encrypted_message, char* key) {
    int i, j, k;
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        encrypted_message[i] = encrypted_message[i] ^ key[j];
    }
}

// Function to prompt the user for a message to encrypt/decrypt
char* get_message() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt/decrypt: ");
    fgets(message, sizeof(message), stdin);
    return strdup(message);
}

// Function to prompt the user for a key to use for encryption/decryption
char* get_key() {
    char key[MAX_KEY_LENGTH];
    printf("Enter a key to use for encryption/decryption: ");
    fgets(key, sizeof(key), stdin);
    return strdup(key);
}

int main() {
    srand(time(NULL));
    char* message = get_message();
    char* key = get_key();

    // Encrypt the message using the key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message using the same key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    free(message);
    free(key);

    return 0;
}