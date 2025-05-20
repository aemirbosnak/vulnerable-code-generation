//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 5
#define MAX_MESSAGE_SIZE 100

// Structure to hold the encryption key and message
typedef struct {
    char key[KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
} message_t;

// Function to encrypt a message
void encrypt(message_t *message) {
    int i, j;
    char c;

    // Iterate through the message and substitute each character with the corresponding
    // character in the encryption key, shifted by the position of the character in the key
    for (i = 0; i < strlen(message->message); i++) {
        c = message->message[i];
        for (j = 0; j < strlen(message->key); j++) {
            if (c == message->key[j]) {
                c = message->key[j + (i - j) % strlen(message->key)];
                break;
            }
        }
        message->message[i] = c;
    }
}

// Function to decrypt a message
void decrypt(message_t *message) {
    int i, j;
    char c;

    // Iterate through the message and substitute each character with the corresponding
    // character in the encryption key, shifted by the position of the character in the key
    for (i = 0; i < strlen(message->message); i++) {
        c = message->message[i];
        for (j = 0; j < strlen(message->key); j++) {
            if (c == message->key[j]) {
                c = message->key[j - (i - j) % strlen(message->key)];
                break;
            }
        }
        message->message[i] = c;
    }
}

int main() {
    message_t message;
    char encrypted_message[] = "Hello World!";

    // Encrypt the message
    encrypt(&message);
    printf("Encrypted message: %s\n", message.message);

    // Decrypt the message
    decrypt(&message);
    printf("Decrypted message: %s\n", message.message);

    return 0;
}