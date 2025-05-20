//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 50
#define MAX_KEY_LENGTH 20

// Define a struct to hold the message and key
typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
} message_t;

// Function to encrypt the message
void encrypt(message_t *message) {
    // Generate a random key
    srand(time(NULL));
    int key_len = strlen(message->key);
    char *key = (char *) malloc(key_len);
    for (int i = 0; i < key_len; i++) {
        key[i] = 'a' + (rand() % 26);
    }

    // Encrypt the message
    for (int i = 0; i < strlen(message->message); i++) {
        char current = message->message[i];
        char next = current;
        for (int j = 0; j < key_len; j++) {
            next = (next + key[j]) % 26;
        }
        message->message[i] = next;
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    // Generate a random key
    srand(time(NULL));
    int key_len = strlen(message->key);
    char *key = (char *) malloc(key_len);
    for (int i = 0; i < key_len; i++) {
        key[i] = 'a' + (rand() % 26);
    }

    // Decrypt the message
    for (int i = 0; i < strlen(message->message); i++) {
        char current = message->message[i];
        char next = current;
        for (int j = 0; j < key_len; j++) {
            next = (next - key[j]) % 26;
        }
        message->message[i] = next;
    }
}

int main() {
    message_t message;
    char message_encrypted[MAX_MESSAGE_LENGTH];

    // Ask the user for the message and key
    printf("Enter a message (max %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(message.message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter a key (max %d characters): ", MAX_KEY_LENGTH);
    fgets(message.key, MAX_KEY_LENGTH, stdin);

    // Encrypt the message
    encrypt(&message);

    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message_encrypted); i++) {
        printf("%c", message_encrypted[i]);
    }

    // Decrypt the message
    decrypt(&message);

    // Print the decrypted message
    printf("Decrypted message: ");
    for (int i = 0; i < strlen(message.message); i++) {
        printf("%c", message.message[i]);
    }

    return 0;
}