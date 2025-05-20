//Falcon-180B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 64
#define MAX_MESSAGE_SIZE 1024

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];
    int key_size;
    int message_size;
    int i, j;

    // Generate a random key
    srand(time(NULL));
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key_size = strlen(key);

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message_size = strlen(message);

    // Encrypt the message
    for (i = 0, j = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j++] = ((message[i] - 'a' + key_size) % 26) + 'a';
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    for (i = 0, j = 0; i < message_size; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j++] = ((encrypted_message[i] - 'a' - key_size + 26) % 26) + 'a';
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}