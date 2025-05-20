//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 1024

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        encrypted_message[i] = message[i] ^ key[j];
    }
    encrypted_message[i] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; i < encrypted_message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }
    decrypted_message[i] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    // Get key from user
    printf("Enter key to encrypt/decrypt: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    // Encrypt message
    encrypt(message, key);

    // Decrypt encrypted message
    decrypt(message, key);

    return 0;
}