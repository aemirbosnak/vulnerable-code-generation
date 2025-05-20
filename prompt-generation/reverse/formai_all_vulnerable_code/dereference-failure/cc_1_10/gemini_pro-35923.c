//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a key
char *encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char *encrypted_message = (char *)malloc(message_length + 1);

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }

    encrypted_message[message_length] = '\0';
    return encrypted_message;
}

// Function to decrypt a message using a key
char *decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char *decrypted_message = (char *)malloc(encrypted_message_length + 1);

    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }

    decrypted_message[encrypted_message_length] = '\0';
    return decrypted_message;
}

// Function to generate a random key
char *generate_key(int key_length) {
    char *key = (char *)malloc(key_length + 1);
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 256;
    }
    key[key_length] = '\0';
    return key;
}

// Function to print a message
void print_message(char *message) {
    printf("%s\n", message);
}

int main() {
    // Generate a random key
    int key_length = 16;
    char *key = generate_key(key_length);

    // Encrypt a message
    char *message = "Hello, world!";
    char *encrypted_message = encrypt(message, key);

    // Print the encrypted message
    print_message(encrypted_message);

    // Decrypt the encrypted message
    char *decrypted_message = decrypt(encrypted_message, key);

    // Print the decrypted message
    print_message(decrypted_message);

    return 0;
}