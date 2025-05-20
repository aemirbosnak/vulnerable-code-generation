//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' + key[i % strlen(key)]) % 26 + 'a';
        }
    }
}

void decrypt_message(char *message, char *key) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' - key[i % strlen(key)]) % 26 + 'a';
        }
    }
}

int main() {
    srand(time(NULL));
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt the message with: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    encrypt_message(message, key);

    printf("Encrypted message: %s\n", message);

    printf("Enter the encrypted message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter the key used for encryption: ");
    scanf("%s", key);

    decrypt_message(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}