//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16

char* generate_key() {
    srand(time(NULL));
    char* key = malloc(KEY_SIZE + 1);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = (char)((rand() % 26) + 'a');
    }
    key[KEY_SIZE] = '\0';
    return key;
}

char* encrypt_message(char* message, char* key) {
    // get message and key lengths
    size_t message_length = strlen(message);
    size_t key_length = strlen(key);

    // allocate memory for encrypted message
    char* encrypted_message = malloc(message_length + 1);
    strncpy(encrypted_message, message, message_length + 1);

    // perform encryption
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = ((encrypted_message[i] - 'a') + (key[i % key_length] - 'a')) % 26 + 'a';
    }

    return encrypted_message;
}

int main() {
    // get user input
    char message[256];
    printf("Enter message to encrypt:\n");
    fgets(message, 256, stdin);

    // generate key and encrypt message
    char* key = generate_key();
    char* encrypted_message = encrypt_message(message, key);

    // print encrypted message and key
    printf("\nEncrypted message: %s\nKey: %s\n", encrypted_message, key);

    // clear memory
    free(key);
    free(encrypted_message);

    return 0;
}