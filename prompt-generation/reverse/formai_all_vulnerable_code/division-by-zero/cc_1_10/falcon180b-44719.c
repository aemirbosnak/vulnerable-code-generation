//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_TEXT_LENGTH 1000000

// Function to generate a random key of length key_length
void generate_key(char *key, int key_length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}\\|;:'\",.<>?";
    int i;

    for (i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }

    key[key_length] = '\0';
}

// Function to encrypt a message using the given key
void encrypt(char *message, char *key) {
    int i, j, k;
    char encrypted_message[MAX_TEXT_LENGTH];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j++] = (char) ((message[i] + key[i % strlen(key)]) % 26 + 'A');
        } else {
            encrypted_message[j++] = message[i];
        }
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt an encrypted message using the given key
void decrypt(char *encrypted_message, char *key) {
    int i, j, k;
    char decrypted_message[MAX_TEXT_LENGTH];

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j++] = (char) ((encrypted_message[i] - key[i % strlen(key)]) % 26 + 'A');
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }

    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main() {
    char message[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH];

    // Generate a random key
    generate_key(key, strlen(key));

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_TEXT_LENGTH, stdin);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}