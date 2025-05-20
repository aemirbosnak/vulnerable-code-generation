//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

// Define a struct to hold the message and key
typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
} message_key_t;

// Function to encrypt the message
void encrypt(message_key_t *message, char *key) {
    int i, j, k;
    char temp;

    // Initialize the cipher with the key
    for (i = 0; i < strlen(key); i++) {
        message->key[i] = key[i];
    }

    // Encrypt the message
    for (i = 0; i < strlen(message->message); i++) {
        temp = message->message[i];
        j = (temp + message->key[i]) % 26;
        message->message[i] = j + 'A';
    }
}

// Function to decrypt the message
void decrypt(message_key_t *message, char *key) {
    int i, j, k;
    char temp;

    // Initialize the cipher with the key
    for (i = 0; i < strlen(key); i++) {
        message->key[i] = key[i];
    }

    // Decrypt the message
    for (i = 0; i < strlen(message->message); i++) {
        temp = message->message[i];
        j = (temp - 'A') % 26;
        message->message[i] = j + 'a';
    }
}

int main() {
    message_key_t message;
    char key[] = "The quick brown fox jumps over the lazy dog";

    // Encrypt the message
    encrypt(&message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message.message);

    // Decrypt the message
    decrypt(&message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message.message);

    return 0;
}