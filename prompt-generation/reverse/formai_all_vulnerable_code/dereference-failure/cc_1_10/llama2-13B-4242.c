//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 20
#define MAX_MESSAGE_SIZE 50

// Define a struct to hold the message and key
typedef struct {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
} message_t;

// Function to encrypt the message
void encrypt(message_t *message) {
    int i, j, k;
    char temp;

    // Loop through the message and key
    for (i = 0; i < strlen(message->message); i++) {
        // Calculate the index of the next character in the key
        j = (i + 1) % strlen(message->key);

        // XOR the characters
        temp = message->message[i] ^ message->key[j];

        // Store the result in the message array
        message->message[i] = temp;
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    int i, j, k;
    char temp;

    // Loop through the message and key
    for (i = 0; i < strlen(message->message); i++) {
        // Calculate the index of the next character in the key
        j = (i + 1) % strlen(message->key);

        // XOR the characters
        temp = message->message[i] ^ message->key[j];

        // Store the result in the message array
        message->message[i] = temp;
    }
}

int main() {
    // Create a message and key
    message_t message = {
        "Hello, world!",
        "This is a secret key"
    };

    // Encrypt the message
    encrypt(&message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message.message);

    // Decrypt the message
    decrypt(&message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message.message);

    return 0;
}