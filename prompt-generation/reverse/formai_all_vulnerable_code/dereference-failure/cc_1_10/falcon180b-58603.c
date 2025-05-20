//Falcon-180B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

void encrypt_message(char *message, char *key) {
    int i, j;
    char encrypted_message[MAX_MESSAGE_LENGTH];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j++] = (message[i] - 'A' + key[i % MAX_KEY_LENGTH] - 'A') % 26 + 'A';
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
    strcpy(message, encrypted_message);
}

void decrypt_message(char *message, char *key) {
    int i, j;
    char decrypted_message[MAX_MESSAGE_LENGTH];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            decrypted_message[j++] = (message[i] - key[i % MAX_KEY_LENGTH] - 'A' + 26) % 26 + 'A';
        } else {
            decrypted_message[j++] = message[i];
        }
    }
    decrypted_message[j] = '\0';
    strcpy(message, decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter a key to encrypt with: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key);
    encrypt_message(message, key);

    printf("Encrypted message:\n%s\n", message);

    decrypt_message(message, key);

    printf("Decrypted message:\n%s\n", message);

    return 0;
}