//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 1024

// Define a struct to hold the message and its encryption
typedef struct {
    char message[MESSAGE_SIZE];
    char key[KEY_SIZE];
} message_t;

// Function to generate a random key
void generate_key() {
    int i;
    message_t *message = malloc(sizeof(message_t));
    for (i = 0; i < KEY_SIZE; i++) {
        message->key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message
void encrypt(message_t *message) {
    int i, j;
    char c, d;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        c = message->message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            d = message->key[j];
            c = (c + d) % 26;
            if (c == 'z') {
                c = 'a';
            }
            message->message[i] = c;
        }
    }
}

// Function to decrypt the message
void decrypt(message_t *message) {
    int i, j;
    char c, d;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        c = message->message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            d = message->key[j];
            c = (c - d + 26) % 26;
            if (c == 'z') {
                c = 'a';
            }
            message->message[i] = c;
        }
    }
}

int main() {
    message_t message;
    generate_key();
    printf("Original message: ");
    gets(message.message);
    encrypt(&message);
    printf("Encrypted message: ");
    gets(message.message);
    decrypt(&message);
    printf("Decrypted message: ");
    gets(message.message);
    return 0;
}