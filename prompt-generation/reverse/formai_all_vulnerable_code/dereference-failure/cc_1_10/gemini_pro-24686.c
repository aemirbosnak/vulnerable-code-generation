//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Peaceful Encryption Algorithm

// Generate a random key
char *generate_key(int key_length) {
    char *key = malloc(key_length + 1);
    for (int i = 0; i < key_length; i++) {
        key[i] = 'a' + rand() % 26;
    }
    key[key_length] = '\0';
    return key;
}

// Encrypt a message using the key
char *encrypt(char *message, char *key) {
    int message_length = strlen(message);
    char *encrypted_message = malloc(message_length + 1);
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = (message[i] + key[i]) % 26 + 'a';
    }
    encrypted_message[message_length] = '\0';
    return encrypted_message;
}

// Decrypt a message using the key
char *decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    char *decrypted_message = malloc(encrypted_message_length + 1);
    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = (encrypted_message[i] - key[i] + 26) % 26 + 'a';
    }
    decrypted_message[encrypted_message_length] = '\0';
    return decrypted_message;
}

// Print the encrypted and decrypted messages
int main() {
    char *message = "Hello, world!";
    char *key = generate_key(strlen(message));

    printf("Original message: %s\n", message);
    printf("Key: %s\n", key);

    char *encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    char *decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}