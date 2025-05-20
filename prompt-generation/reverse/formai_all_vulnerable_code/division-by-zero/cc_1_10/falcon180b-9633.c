//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_key(char* key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length + 1];
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (message[i] - 'A' + key[j] - 'a') % 26 + 'A';
            } else {
                encrypted_message[i] = (message[i] - 'a' + key[j] - 'a') % 26 + 'a';
            }
        } else {
            encrypted_message[i] = message[i];
        }
        j = (j + 1) % key_length;
    }
    encrypted_message[message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[message_length + 1];
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = (message[i] - 'A' - key[j] + 26) % 26 + 'A';
            } else {
                decrypted_message[i] = (message[i] - 'a' - key[j] + 26) % 26 + 'a';
            }
        } else {
            decrypted_message[i] = message[i];
        }
        j = (j + 1) % key_length;
    }
    decrypted_message[message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    char key[1000];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}